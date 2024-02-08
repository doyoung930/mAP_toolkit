#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "define.h"
#include "MapCalculation.h"
class DefaultMapCalculation : public MapCalculation {
public:

    void calculateMap(const std::vector<std::string>& data) override;

    // true bboxes
    std::unordered_map<std::string, vector<BoundingBox>> _true_bboxes;

    // predicted bboxes
    std::unordered_map<std::string, vector<BoundingBox>> _predicted_bboxes;

    std::vector<float> _overlapping_area;

    // 겹치는 영역 계산하기
    void CalculationOverLapping(){
        for (const auto& true_pair : _true_bboxes) {
            const std::string& class_name = true_pair.first;
            const std::vector<BoundingBox>& true_bboxes = true_pair.second;

            const std::vector<BoundingBox>& predicted_bboxes = _predicted_bboxes[class_name];

            for (const auto& true_bbox : true_bboxes) {
                for (const auto& predicted_bbox : predicted_bboxes) {
                    //int overlap_area = calculateOverlapArea(true_bbox, predicted_bbox);
                    // 계산된 overlap_area를 사용하여 원하는 작업을 수행할 수 있습니다.
                }
            }
        }
    }

    
    // IoU
    std::unordered_map<std::string, float> _IoU;

    

    float CompareIoU(float a, float b) {
        return (a > b) ? a : b;
    }
    
    float CalculateIoU(){
    }

    // TP, FP, FN 
    std::vector<ConfusionMatrix> _confidence_matrix;

    PrecisionRecall CalculationPR() {

        PrecisionRecall t_PR;

        for (ConfusionMatrix confidence_matrix : _confidence_matrix) {
            
            t_PR.precision = confidence_matrix.tp / (confidence_matrix.tp + confidence_matrix.fp);
            t_PR.recall = confidence_matrix.tp / (confidence_matrix.tp + confidence_matrix.fn);
                        
        }

        return t_PR;
    }

    // precision recall
    std::unordered_map<char, std::vector<PrecisionRecall>> _precision_recall;


    // threshold
    float t = 0.5;

    float epsilon = 0.001; // 0으로 나누는 것을 방지하기 위한 작은 값

  

    
};

