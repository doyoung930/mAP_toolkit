#include "MapCalculation.h"
#include "define.h" // Assuming you have this header for definitions
#include <string>

int main() {
  
    // ���� ������ ����
    std::unordered_map<std::string, BoundingBox> true_bboxes;
    std::unordered_map<std::string, BoundingBox> predicted_bboxes;

    // �� Ŭ������ ���� ���� ������ ����
    std::string class_name = "class_1";
    // ���� Bounding Box ���� (����: [0, 0, 10, 10])
    true_bboxes[class_name] = BoundingBox{ 0, 0, 10, 10 };
    // ������ Bounding Box ���� (���� Bounding Box�� �������� �ʵ��� ����)
    predicted_bboxes["class_2"] = BoundingBox{ 0, 0, 9, 9 }; // ���� Bounding Box�� �������� �ʵ��� �����Ͽ� FN�� �߻��ϵ��� ��

    // MapCalculation ��ü ����
    MapCalculation map_calculation;

    // ���� �����ͷ� MapCalculation ��ü�� ������ ����
    map_calculation._true_bboxes = true_bboxes;
    map_calculation._predicted_bboxes = predicted_bboxes;

    // IoU ��� �� ����
    map_calculation.SaveIoU();

    // TP, FP, FN ���
    map_calculation.CalculationTPFPFN();
    for (const auto& entry : map_calculation._id_confidence_matrix) {
        std::cout << "Class: " << entry.first << ", Confidence: " << entry.second << std::endl;
    }
    // Precision-Recall �� AP ���
    //std::vector<PrecisionRecall> precision_recall = map_calculation.CalculationPR();
    //float ap = map_calculation.calculateAP(precision_recall);

    //// AP ��� ���
    //std::cout << "Average Precision (AP): " << ap << std::endl;

    //// mAP ���
    //float map = map_calculation.calculateMAP();

    //// mAP ��� ���
    //std::cout << "Mean Average Precision (mAP): " << map << std::endl;

    return 0;
}