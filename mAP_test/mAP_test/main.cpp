#include <iostream>
#include <vector>
#include "DefaultMapCalculation.h"

int main() {
    // 예시 데이터 생성
    std::vector<std::string> data = { "class1", "class2", "class3" };

    // DefaultMapCalculation 객체 생성
    DefaultMapCalculation mapCalculation;

    // 예시 데이터로 calculateMap 함수 호출
    mapCalculation.calculateMap(data);

    // 예시로 BoundingBox 추가
    mapCalculation._true_bboxes["class1"] = { 0, 0, 10, 10 };
    mapCalculation._predicted_bboxes["class1"] = { 0, 0, 8, 8 };

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

    // mAP 계산 예시
    float mAP = mapCalculation.calculateMAP();

    // 결과 출력
    std::cout << "mAP: " << mAP << std::endl;

    return 0;
}