#include <iostream>
#include <vector>
#include "DefaultMapCalculation.h"

int main() {
    // ���� ������ ����
    std::vector<std::string> data = { "class1", "class2", "class3" };

    // DefaultMapCalculation ��ü ����
    DefaultMapCalculation mapCalculation;

    // ���� �����ͷ� calculateMap �Լ� ȣ��
    mapCalculation.calculateMap(data);

    // ���÷� BoundingBox �߰�
    mapCalculation._true_bboxes["class1"] = { 0, 0, 10, 10 };
    mapCalculation._predicted_bboxes["class1"] = { 0, 0, 8, 8 };

    // CalculationOverLapping �Լ� ȣ��
    mapCalculation.CalculationOverLapping();

    // AP ��� ����
    std::vector<PrecisionRecall> precisionRecallList;
    PrecisionRecall pr1 = { 0.8, 0.6 };
    PrecisionRecall pr2 = { 0.7, 0.5 };
    precisionRecallList.push_back(pr1);
    precisionRecallList.push_back(pr2);
    float ap = mapCalculation.calculateAP(precisionRecallList);
    mapCalculation.APs["class1"] = ap;

    // mAP ��� ����
    float mAP = mapCalculation.calculateMAP();

    // ��� ���
    std::cout << "mAP: " << mAP << std::endl;

    return 0;
}