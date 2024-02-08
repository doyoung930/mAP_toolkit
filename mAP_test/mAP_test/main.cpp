#include <iostream>
#include <vector>
#include "DefaultMapCalculation.h"

int main() {
    // 예시 데이터 생성
    std::vector<std::string> data = { "class1", "class2", "class3" };

    // DefaultMapCalculation 객체 생성
    DefaultMapCalculation mapCalculation;

    // 예시 데이터로 calculateMap 함수 호출
   // mapCalculation.calculateMap(data);

    // 예시로 BoundingBox 추가
    mapCalculation._true_bboxes["class1"] = { 0, 0, 10, 10 };
    mapCalculation._predicted_bboxes["class1"] = { 0, 0, 8, 8 };
    mapCalculation._true_bboxes["class2"] = { 0, 0, 12, 12 };
    mapCalculation._predicted_bboxes["class2"] = { 0, 0, 10, 10 };

    mapCalculation._true_bboxes["class3"] = { 0, 0, 8, 8 };
    mapCalculation._predicted_bboxes["class3"] = { 0, 0, 6, 6 };
    // CalculationOverLapping 함수 호출
    mapCalculation.CalculationOverLapping();

    // AP 계산 예시
    std::vector<PrecisionRecall> precisionRecallList;
    PrecisionRecall pr1 = { 0.8, 0.6 };
    PrecisionRecall pr2 = { 0.7, 0.5 };
    precisionRecallList.push_back(pr1);
    precisionRecallList.push_back(pr2);
    float ap = mapCalculation.calculateAP(precisionRecallList);
    mapCalculation.APs["class1"] = ap;

    std::vector<PrecisionRecall> precisionRecallList2;
    PrecisionRecall pr2_1 = { 0.85, 0.7 };
    PrecisionRecall pr2_2 = { 0.75, 0.6 };
    precisionRecallList2.push_back(pr2_1);
    precisionRecallList2.push_back(pr2_2);
    float ap2 = mapCalculation.calculateAP(precisionRecallList2);
    mapCalculation.APs["class2"] = ap2;

    std::vector<PrecisionRecall> precisionRecallList3;
    PrecisionRecall pr3_1 = { 0.9, 0.8 };
    PrecisionRecall pr3_2 = { 0.8, 0.7 };
    precisionRecallList3.push_back(pr3_1);
    precisionRecallList3.push_back(pr3_2);
    float ap3 = mapCalculation.calculateAP(precisionRecallList3);
    mapCalculation.APs["class3"] = ap3;

    // mAP 계산 예시
    float mAP = mapCalculation.calculateMAP();

    // 결과 출력
    std::cout << "mAP: " << mAP << std::endl;

    // 각 클래스의 AP 출력
    for (const auto& ap : mapCalculation.APs) {
        std::cout << "AP for " << ap.first << ": " << ap.second << std::endl;
    }

    return 0;
}