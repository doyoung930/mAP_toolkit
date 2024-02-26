#pragma once
#define USE_NAMESPACE

//#include "header.h"
#include <string>
#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>

class Inference {
public:
    Inference();
    ~Inference();
    void run(std::string directory_path);

private:
    size_t device;
    size_t handle;
    size_t model;
    size_t video_ins;
    int block_size;
    float* block;
    cv::Mat image;
    std::string model_name;

    int model_index;

    void loadModel();
    void initialize();
    void processFrame();
};
