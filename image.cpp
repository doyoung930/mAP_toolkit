#define USE_NAMESPACE
#include <string>
#include <filesystem>
#include <iostream>
#include "libIDL.h"
#include <opencv2/opencv.hpp>

int main()
{
	//cv::namedWindow("image", WINDOW_NORMAL);
	size_t device = IDL::make_device(0, 0);
	size_t handle = IDL::make_handle(device);
	int model_index = IDL::get_model_id((char*)"ocr_LPRNetS1B_rep_fp16");			// ocr_LPRNetS1B_rep_fp16, od_YOLOv7_rep_fp16
	size_t model = IDL::make_model_instance(handle, model_index);
	size_t video_ins = IDL::make_video_instance(device, (char*)"image");
	auto path = std::filesystem::current_path().string();
	std::string model_name = path + "\\..\\model\\ocr_LPRNetS1B_rep_fp16.aix";						// ocr_LPRNetS1B_rep_fp16.aix, yolov7.aix
	std::cout << model_name << std::endl;
	IDL::load_param_aix(model, (char*)model_name.c_str(), true);
	IDL::initialize(model);
	IDL::load_weight_aix(model, (char*)model_name.c_str(), true);

	IDL::set_video_instance_use_ptz_detection(video_ins, false);
	IDL::set_video_instance(model, video_ins);

	int block_size = IDL::get_decoder_data_block_size(model);
	float* block = new float[block_size];
	float pre_time, net_time, post_time;

	std::string image_path = "C:/code/24µÎ2348.jpg";
	cv::Mat image = cv::imread(image_path);
	
	bool is_open = image.empty();
	
	int width = image.rows;//(cv::CAP_PROP_FRAME_WIDTH);
	int height = image.cols;//(cv::CAP_PROP_FRAME_HEIGHT);
	cv::Mat frame(cv::Size(width, height), CV_8UC3);
	if (!is_open)
	{
		IDL::set_input_image(video_ins, 0, frame.cols, frame.rows , 3, frame.data);
		IDL::forward(model);
		int count = IDL::get_decoder_data_count(model);
		IDL::reset_decoder_iterator(model);
		for (int i = 0; i < count; i++)
		{
			IDL::get_decoder_data(model, block);
			int class_id = (int)block[0];
			float score = block[1];
			int xmin = int(block[2]);
			int ymin = int(block[3]);
			int xmax = int(block[4]);
			int ymax = int(block[5]);
			cv::rectangle(frame, { xmin, ymin }, { xmax, ymax }, cv::Scalar(0, 0, 255), 1);
			IDL::next_decoder_data(model);
		}
		cv::imshow("image", image);
		//if (cv::waitKey(1) == 27) break;
		cv::waitKey(0);

		printf("%d objects\n", count);

		pre_time = IDL::get_pre_time(model);
		net_time = IDL::get_net_time(model);
		post_time = IDL::get_post_time(model);

		printf("pre %.2fms / net %.2fms / post %.2fms(%.1f FPS)\n", pre_time, net_time, post_time, 1000.0f / net_time);
	}

	delete[] block;
	IDL::release_video_instance(video_ins);
	IDL::release_model_instance(model);
	IDL::release_handle(handle);
	IDL::release_device(device);
	return 0;
}