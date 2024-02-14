#include "MapCalculation.h"
#include "define.h" // Assuming you have this header for definitions
#include <string>

int main() {
  
    // 예시 데이터 생성
    std::unordered_map<std::string, BoundingBox> true_bboxes;
    std::unordered_map<std::string, BoundingBox> predicted_bboxes;

    // 한 클래스에 대한 예시 데이터 생성
    std::string class_name = "class_1";
    // 실제 Bounding Box 생성 (예시: [0, 0, 10, 10])
    true_bboxes[class_name] = BoundingBox{ 0, 0, 10, 10 };
    // 예측된 Bounding Box 생성 (실제 Bounding Box를 포함하지 않도록 설정)
    predicted_bboxes["class_2"] = BoundingBox{ 0, 0, 9, 9 }; // 실제 Bounding Box를 포함하지 않도록 설정하여 FN이 발생하도록 함

    // MapCalculation 객체 생성
    MapCalculation map_calculation;

    // 예시 데이터로 MapCalculation 객체에 데이터 전달
    map_calculation._true_bboxes = true_bboxes;
    map_calculation._predicted_bboxes = predicted_bboxes;

    // IoU 계산 및 저장
    map_calculation.SaveIoU();

    // TP, FP, FN 계산
    map_calculation.CalculationTPFPFN();
    for (const auto& entry : map_calculation._id_confidence_matrix) {
        std::cout << "Class: " << entry.first << ", Confidence: " << entry.second << std::endl;
    }
    // Precision-Recall 및 AP 계산
    //std::vector<PrecisionRecall> precision_recall = map_calculation.CalculationPR();
    //float ap = map_calculation.calculateAP(precision_recall);

    //// AP 결과 출력
    //std::cout << "Average Precision (AP): " << ap << std::endl;

    //// mAP 계산
    //float map = map_calculation.calculateMAP();

    //// mAP 결과 출력
    //std::cout << "Mean Average Precision (mAP): " << map << std::endl;

    return 0;
}