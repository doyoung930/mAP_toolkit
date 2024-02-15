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
    std::unordered_map<int, BoundingBox> _true_bboxes;
    std::unordered_map<int, BoundingBox> _predicted_bboxes;
    std::unordered_map <int, float > _id_IoU;

    // TP : 1, FN : 2, FP : 3 
    std::unordered_map<int, int > _id_confidence_matrix;

    std::unordered_map<int, std::vector<PrecisionRecall>> _precision_recall;
    std::unordered_map<int, float> APs;
    std::unordered_map<int, float> APs;
    float map;
    float t = 0.5;
    float epsilon = 0.001;
private:

    void SaveIoU();
    float CalculateIoU(const BoundingBox& box1, const BoundingBox& box2);

    void CalculationTPFPFN();
    std::vector<PrecisionRecall> CalculationPR();
    float calculateAP(const std::vector<PrecisionRecall>& precision_recall);
    float calculateMAP();  

};