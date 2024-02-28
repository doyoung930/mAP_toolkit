#define _CRT_SECURE_NO_WARNINGS
#define USE_NAMESPACE
#include "Inference.h" 
#include "libIDL.h"
#include "mAP_calculation/MapCalculation.h"

#include <fstream>
namespace fs = std::filesystem;

Inference::Inference() {
    device = IDL::make_device(0, 0);
    handle = IDL::make_handle(device);
    model_index = IDL::get_model_id((char*)"od_YOLOv7_rep_fp16");                           // ocr_LPRNetS1B_rep_fp16, od_YOLOv7_rep_fp16
    model = IDL::make_model_instance(handle, model_index);
    video_ins = IDL::make_video_instance(device, (char*)"video");
   
    model_name = std::filesystem::current_path().string() + "\\..\\model\\yolov7.aix";   // ocr_LPRNetS1B_rep_fp16.aix, yolov7.aix
    loadModel();
    initialize();
    block_size = IDL::get_decoder_data_block_size(model);
    block = new float[block_size];
    
    calculation = std::make_shared<MapCalculation>();
}

Inference::~Inference() {
    delete[] block;
    IDL::release_video_instance(video_ins);
    IDL::release_model_instance(model);
    IDL::release_handle(handle);
    IDL::release_device(device);
}

void Inference::loadModel() {
    IDL::load_param_aix(model, (char*)model_name.c_str(), true);
    IDL::initialize(model);
    IDL::load_weight_aix(model, (char*)model_name.c_str(), true);
}

void Inference::initialize() {
    
    IDL::set_video_instance_use_ptz_detection(video_ins, false);
    IDL::set_video_instance(model, video_ins);
}

void Inference::processFrame() {
    calculation->GetPredictedBB().clear();

    int count = IDL::get_decoder_data_count(model);

    calculation->GetPredictedBB().reserve(count);

    IDL::reset_decoder_iterator(model);
    for (int i = 0; i < count; i++) {
        IDL::get_decoder_data(model, block);
        int class_id = (int)block[0];
        float score = block[1];
        int xmin = int(block[2]);
        int ymin = int(block[3]);
        int xmax = int(block[4]);
        int ymax = int(block[5]);

        calculation->GetPredictedBB().emplace_back(class_id, xmin, ymin, xmax - xmin, ymax - ymin);
        calculation->GettempPredictedBB().emplace_back(class_id, xmin, ymin, xmax - xmin, ymax - ymin);

        IDL::next_decoder_data(model);
    }
    float pre_time = IDL::get_pre_time(model);
    float net_time = IDL::get_net_time(model);
    float post_time = IDL::get_post_time(model);
}

std::string Inference::findTextFile(std::string fileName)
{
    size_t dotPos = fileName.find_last_of('.');
    if (dotPos == std::string::npos)
    {
        return "";
    }

    std::string JpgPath = fileName.substr(0, dotPos) + ".txt";  // AAA.jpg -> AAA.txt
    std::fstream file(JpgPath);
    if (!file.is_open())
    {
        return "";
    }

    //file.close();
    return JpgPath;
}

void Inference::readTextFile(std::string textFileName, int width, int height)
{
    calculation->GetTrueBB().clear();
    calculation->GetTrueBB().reserve(10);

    std::fstream file(textFileName);
    if (file.is_open())
    {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        std::vector<std::stringstream> lines;
        std::string line;
        std::stringstream StringStream(content);

        while (std::getline(StringStream, line, '\n'))
        {
            lines.emplace_back(line);
        }

        // TODO: 경기 12바 3456 일때 txt에 경기만 들어있다면?
        for (auto& l : lines)
        {
            int id;
            float x, y, Width, Height;
            BoundingBox BB;

            l >> id >> x >> y >> Width >> Height;

            // DeNormalize
            BB.id = id;
            BB.width = Width * width;
            BB.height = Height * height;
            BB.x = (x * width) - BB.width / 2;
            BB.y = (y * height) - BB.height / 2;

            calculation->GetTrueBB().push_back(BB);
            calculation->GettempTrueBB().push_back(BB);
        }
    }
}

void Inference::run(std::string directory_path) {
    //while (true) {
    try {
        for (const auto& entry : fs::directory_iterator(directory_path)) {
            if (entry.path().extension() == ".jpg") {
                std::string filename = entry.path().filename().string();
                std::ifstream file(entry.path());

                if (file.is_open()) {
                    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

                    std::string a = directory_path + "\\" + filename;

                    cv::Mat image_temp = cv::imread(directory_path + "\\" + filename);
                    bool is_open = image_temp.empty();
                    if (!is_open) {
                        // Checking Text File
                        auto abc = entry.path();
                        std::string TextFile = findTextFile(directory_path + "\\" + filename);
                        if (TextFile == "")
                        {
                            // No Text File
                            continue;
                        }

                        //Get true
                        readTextFile(TextFile, image_temp.cols, image_temp.rows);

                        // Get Predict
                        IDL::set_input_image(video_ins, 0, image_temp.rows, image_temp.cols, 3, image_temp.data);
                        IDL::forward(model);
                        int count = IDL::get_decoder_data_count(model);
                        processFrame();
                        // TODO: Calculate IOU
                        calculation->SaveIoU();
                        
                       
                    }
                    
                    file.close();
                }
                else {
                    //닫히면 ap 계산
                    std::cerr << "Unable to open file: " << filename << std::endl;
                }
            }
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    calculation->CalculationTPFPFN();

     //   else
    //        break;
            

    //}
}