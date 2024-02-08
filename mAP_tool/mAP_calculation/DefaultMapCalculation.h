#pragma once
#include <iostream>
#include <unordered_map>

#include "define.h"
#include "MapCalculation.h"
class DefaultMapCalculation : public MapCalculation {
public:
    void calculateMap(const std::vector<std::string>& data) override;

    // true bboxes
    std::unordered_map<std::string, vector<struct BoundingBox>> true_bboxes;

    // predicted bboxes
    std::unordered_map<std::string, vector<struct BoundingBox>> predicted_bboxes;

    // IoU
    std::unordered_map<std::string, float> best_IoU;

    float compare_iou(float a, float b) {
        return (a > b) ? a : b;
    }

    // precision recall
    std::unordered_map<char, vector<struct PrecisionRecall>> _precision_recall;

};

