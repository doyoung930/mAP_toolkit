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
    
    MapCalculation(const std::vector<BoundingBox>& true_bboxes, const std::vector<BoundingBox>& predicted_bboxes) {
        // 텍스트 파일에서 읽은 실제 바운딩 박스와 예측된 바운딩 박스를 멤버 변수에 추가
        for (const auto& bbox : true_bboxes) {
            _true_bboxes.push_back(bbox);
        }

        for (const auto& bbox : predicted_bboxes) {
            _predicted_bboxes.push_back(bbox);
        }
    }
    ~MapCalculation() {}



    void SaveIoU();

    float CalculateIoU(const BoundingBox& box1, const BoundingBox& box2);

    void CalculationTPFPFN();

    float calculateAP(const std::vector<float>& precisions, const std::vector<float>& recalls);

    float calculateMAP();

    void Truth_GetData(string directory_path);
    void Predicted_GetData(string directory_path);
private:
    std::vector<BoundingBox> _true_bboxes;
    std::vector<BoundingBox> _predicted_bboxes;
    std::vector <IdIoU> _id_IoU;

    // TP : 1, FN : 2, FP : 3 
    std::vector<ConfusionMatrix> confidence_matrix;
    std::unordered_map<int, std::tuple<int, int, int>> id_tpfnfp;
   

    //////////

    std::vector<float> aps;

    float map;
    float t = 0.5;
    float epsilon = 0.001;



};