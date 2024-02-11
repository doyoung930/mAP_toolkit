#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "define.h"
#include "MapCalculation.h"
class DefaultMapCalculation  {
//public:
//
//    //void calculateMap(const std::vector<std::string>& data) override;
//
//    // true bboxes
//    std::unordered_map<std::string, BoundingBox> _true_bboxes;
//
//    // predicted bboxes
//    std::unordered_map<std::string, BoundingBox> _predicted_bboxes;
//
//    // ��ġ�� ���� 
//    std::vector<float> _overlapping_area;
//
//    // ��ġ�� ���� ����ϱ�
//    void CalculationOverLapping(){
//        for (const auto& true_bbox : _true_bboxes) {
//
//            const std::string& class_name = true_bbox.first;
//            const BoundingBox& true_box = true_bbox.second;
//
//            if (_predicted_bboxes.find(class_name) != _predicted_bboxes.end()) {
//                const BoundingBox& predicted_box = _predicted_bboxes[class_name];
//
//                // Calculate overlapping area using IoU
//                float overlapping_area = calculateIoU(true_box, predicted_box);
//
//                // Add calculated overlapping area to _overlapping_area
//                _overlapping_area.push_back(overlapping_area);
//            }
//        }
//    }
//
//    // IoU ���
//    float calculateIoU(const BoundingBox& box1, const BoundingBox& box2) {
//        // Calculate overlapping area using IoU algorithm
//        float intersection_width = std::max(0.f, std::min(box1.x + box1.width, box2.x + box2.width) - std::max(box1.x, box2.x));
//        float intersection_height = std::max(0.f, std::min(box1.y + box1.height, box2.y + box2.height) - std::max(box1.y, box2.y));
//
//        float intersection_area = intersection_width * intersection_height;
//        float union_area = box1.width * box1.height + box2.width * box2.height - intersection_area;
//
//        if (union_area == 0)
//            return 0; // Return 0 if union area is 0 to avoid division by zero
//
//        return intersection_area / union_area;
//    }
//
//    // IoU
//    std::unordered_map<std::string, float> _IoU;
//
//    float CompareIoU(float a, float b) {
//        return (a > b) ? a : b;
//    }
//
//    // TP, FP, FN 
//    std::vector<ConfusionMatrix> _confidence_matrix;
//
//    std::vector<PrecisionRecall> CalculationPR() {
//
//        std::vector<PrecisionRecall> precision_recall_list;
//
//        for (const ConfusionMatrix& confidence_matrix : _confidence_matrix) {
//            PrecisionRecall pr;
//            pr.precision = confidence_matrix.tp / (confidence_matrix.tp + confidence_matrix.fp);
//            pr.recall = confidence_matrix.tp / (confidence_matrix.tp + confidence_matrix.fn);
//
//            precision_recall_list.push_back(pr);
//        }
//
//        return  precision_recall_list;
//    }
//
//    // precision recall
//    std::unordered_map<std::string, std::vector<PrecisionRecall>> _precision_recall;
//
//    // ����� ap�� �� �´� id�� ���� 
//    std::unordered_map<std::string, float> APs;
//    
//    // �ѹ� �����ؾߵ�
//    float calculateAP(const std::vector<PrecisionRecall>& precision_recall) {
//        // Precision-Recall ��� �����Ͽ� Recall�� �����ϴ� ������ �����մϴ�.
//        std::vector<PrecisionRecall> sorted_precision_recall = precision_recall;
//        std::sort(sorted_precision_recall.begin(), sorted_precision_recall.end(),
//            [](const PrecisionRecall& a, const PrecisionRecall& b) {
//                return a.recall < b.recall;
//            });
//
//        float ap = 0.0;
//        float prev_recall = 0.0;
//        float prev_precision = 1.0;
//
//        // Precision-Recall ��� Ž���ϸ鼭 trapezoidal rule�� �����Ͽ� AP�� ����մϴ�.
//        for (const auto& pr : sorted_precision_recall) {
//            float recall = pr.recall;
//            float precision = pr.precision;
//
//            // ���� Recall ���� ���� Recall �� ������ ������ ����Ͽ� AP�� �߰��մϴ�.
//            ap += (recall - prev_recall) * ((precision + prev_precision) / 2.0);
//
//            // ���� Recall �� Precision ���� �����մϴ�.
//            prev_recall = recall;
//            prev_precision = precision;
//        }
//
//        return ap;
//    }
//
//    float map;
//
//    float calculateMAP() {
//        float total_ap = 0.0;
//        for (const auto& ap : APs) {
//            total_ap += ap.second; // �� Ŭ������ AP ���� ����
//        }
//        return total_ap / APs.size(); // Ŭ���� ���� ������ mAP ���
//    }
//
//    // threshold
//    float t = 0.5;
//
//    float epsilon = 0.001; // 0���� ������ ���� �����ϱ� ���� ���� ��

  

    
};

