#pragma once
#define USE_NAMESPACE

//#include "header.h"
#include <string>
#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <memory>

#include "define.h"

class Inference {
public:
    Inference();
    ~Inference();
    void run(std::string directory_path);

private:
    std::shared_ptr<class MapCalculation> calculation;

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
    std::string findTextFile(std::string fileName);
    void readTextFile(std::string textFileName, int width, int height);
};