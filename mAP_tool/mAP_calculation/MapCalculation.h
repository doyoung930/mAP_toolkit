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

    void SaveIoU();

    float CalculateIoU(const BoundingBox& box1, const BoundingBox& box2);

    void CalculationTPFPFN();

    float calculateAP(const std::vector<float>& precisions, const std::vector<float>& recalls);

    float calculateMAP();

private:
    std::vector<BoundingBox> _true_bboxes;
    std::vector<BoundingBox> _predicted_bboxes;
    std::vector <IdIoU> _id_IoU;

    // TP : 1, FN : 2, FP : 3 
    std::vector<ConfusionMatrix> confidence_matrix;
    std::unordered_map<int, std::tuple<int, int, int>> id_tpfnfp;
   

    //////////
    //std::vector<PrecisionRecall> _precisions_recalls;
    std::vector<float> aps;

    float map;
    float t = 0.5;
    float epsilon = 0.001;



};