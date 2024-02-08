#pragma once
#include "header.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "define.h"
class MapCalculation
{
public:
    
    MapCalculation() {}
    ~MapCalculation() {}

public:

    std::unordered_map<std::string, BoundingBox> _true_bboxes;
    std::unordered_map<std::string, BoundingBox> _predicted_bboxes;
    std::vector<float> _overlapping_area;
    std::unordered_map<std::string, float> _IoU;
    std::vector<ConfusionMatrix> _confidence_matrix;
    std::unordered_map<std::string, std::vector<PrecisionRecall>> _precision_recall;
    std::unordered_map<std::string, float> APs;
    float map;
    float t = 0.5;
    float epsilon = 0.001;
private:
    void CalculationOverLapping();
    float calculateIoU(const BoundingBox& box1, const BoundingBox& box2);
    float CompareIoU(float a, float b);
    std::vector<PrecisionRecall> CalculationPR();
    float calculateAP(const std::vector<PrecisionRecall>& precision_recall);
    float calculateMAP();
    void calculateMap(const vector<string>& data);
   

};