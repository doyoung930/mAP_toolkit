#define _CRT_SECURE_NO_WARNINGS
#define USE_NAMESPACE
#include "Inference.h" 
#include "libIDL.h"

#include <fstream>
namespace fs = std::filesystem;

Inference::Inference() {
    device = IDL::make_device(0, 0);
    handle = IDL::make_handle(device);
    model_index = IDL::get_model_id((char*)"ocr_LPRNetS1B_rep_fp16");
    model = IDL::make_model_instance(handle, model_index);
    video_ins = IDL::make_video_instance(device, (char*)"video");
   
    model_name = std::filesystem::current_path().string() + "\\..\\model\\ocr_LPRNetS1B.aix";
    loadModel();
    initialize();
    block_size = IDL::get_decoder_data_block_size(model);
    block = new float[block_size];
    
    
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
    IDL::set_input_image(video_ins, 0, image.rows, image.cols, 3, image.data);
    //cv::imshow("result", image);
    //cv::waitKey(1000);
    IDL::forward(model);
    int count = IDL::get_decoder_data_count(model);
    IDL::reset_decoder_iterator(model);
    for (int i = 0; i < count; i++) {
        IDL::get_decoder_data(model, block);
        int class_id = (int)block[0];
        float score = block[1];
        int xmin = int(block[2]);
        int ymin = int(block[3]);
        int xmax = int(block[4]);
        int ymax = int(block[5]);

        IDL::next_decoder_data(model);
    }
    float pre_time = IDL::get_pre_time(model);
    float net_time = IDL::get_net_time(model);
    float post_time = IDL::get_post_time(model);
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
                        //IDL::set_input_image(video_ins, 0, image.rows, image.cols, 3, image.data);
                        IDL::set_input_image(video_ins, 0, image_temp.rows, image_temp.cols, 3, image_temp.data);
                        IDL::forward(model);
                        int count = IDL::get_decoder_data_count(model);
                        processFrame();
                    }

                    //std::vector<std::string> lines;
                    //std::string line;
                    //lines.reserve(4);
                    //std::stringstream StringStream(content);
                    //while (std::getline(StringStream, line, '\n'))
                    //{
                    //    lines.push_back(line);
                    //}
                    //
                    //std::string ResultString = "";
                    //for (const auto& l : lines)
                    //{
                    //    std::stringstream Linecontent(l);
                    //    std::string temp;
                    //    Linecontent >> temp;
                    //    ResultString += GetIntToStr(temp);
                    //}
                    //
                    ////if (std::string::npos == filename.find(ResultString))
                    //std::string temp = GetRealFilename(filename);
                    //if (temp != ResultString)
                    //{
                    //    std::cout << "File: " << filename << std::endl;
                    //    std::cout << "\"" << ResultString << "\" is Different!" << std::endl;
                    //}
                    
                    file.close();
                }
                else {
                    std::cerr << "Unable to open file: " << filename << std::endl;
                }
            }
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
     //   else
    //        break;
            

    //}
}