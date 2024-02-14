#include "MapCalculation.h"



void MapCalculation::SaveIoU() {

    auto true_it = _true_bboxes.begin();
    auto predicted_it = _predicted_bboxes.begin();
    for (; true_it != _true_bboxes.end() 
        && predicted_it != _predicted_bboxes.end();
        ++true_it, ++predicted_it) {
        const std::string& class_name = true_it->first;
        const BoundingBox& true_box = true_it->second;
        const BoundingBox& predicted_box = predicted_it->second;
        float IoU = CalculateIoU(true_box, predicted_box);
        _id_IoU.insert(std::make_pair(class_name, IoU));
    }
}

float MapCalculation::CalculateIoU(const BoundingBox& box1, const BoundingBox& box2) {
    float intersection_width = std::max(0.f, std::min(box1.x + box1.width, box2.x + box2.width) - std::max(box1.x, box2.x));
    float intersection_height = std::max(0.f, std::min(box1.y + box1.height, box2.y + box2.height) - std::max(box1.y, box2.y));

    float intersection_area = intersection_width * intersection_height;
    float union_area = box1.width * box1.height + box2.width * box2.height - intersection_area;

    if (union_area == 0)
        return 0;

    return intersection_area / union_area;
}


void MapCalculation::CalculationTPFPFN() {
    auto true_it = _true_bboxes.begin();
    auto predicted_it = _predicted_bboxes.begin();
    auto iou_it = _id_IoU.begin();
    for (; true_it != _true_bboxes.end() && predicted_it != _predicted_bboxes.end();
        ++true_it, ++predicted_it, ++iou_it) {
        // true_bboxes와 predicted_bboxes에서 해당 위치의 BoundingBox 비교
        if (true_it->first == predicted_it->first) {
            // 
            if (iou_it->second >= t) {
                // tp
                _id_confidence_matrix.insert(std::make_pair(true_it->first, 1));
            }
            else {
                // fn
                _id_confidence_matrix.insert(std::make_pair(true_it->first, 2));
            }
        }
        else {
            if (iou_it->second >= t) {
                // fp
                _id_confidence_matrix.insert(std::make_pair(true_it->first, 3));
            }
        }
    }

}
float MapCalculation::calculateAP(const std::vector<PrecisionRecall>& precision_recall) {
    // calculateAP 함수의 구현
    // Precision-Recall 곡선을 정렬하여 Recall이 증가하는 순서로 정렬합니다.
    std::vector<PrecisionRecall> sorted_precision_recall = precision_recall;
    std::sort(sorted_precision_recall.begin(), sorted_precision_recall.end(),
        [](const PrecisionRecall& a, const PrecisionRecall& b) {
            return a.recall < b.recall;
        });

    float ap = 0.0;
    float prev_recall = 0.0;
    float prev_precision = 1.0;

    // Precision-Recall 곡선을 탐색하면서 trapezoidal rule을 적용하여 AP를 계산합니다.
    for (const auto& pr : sorted_precision_recall) {
        float recall = pr.recall;
        float precision = pr.precision;

        // 현재 Recall 값과 이전 Recall 값 사이의 면적을 계산하여 AP에 추가합니다.
        ap += (recall - prev_recall) * ((precision + prev_precision) / 2.0);

        // 현재 Recall 및 Precision 값을 저장합니다.
        prev_recall = recall;
        prev_precision = precision;
    }

    return ap;
}

float MapCalculation::calculateMAP() {
    // calculateMAP 함수의 구현
    float total_ap = 0.0;
    for (const auto& ap : APs) {
        total_ap += ap.second; // 각 클래스의 AP 값을 더함
    }
    return total_ap / APs.size(); // 클래스 수로 나누어 mAP 계산
}