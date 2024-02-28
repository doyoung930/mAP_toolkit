#include <iostream>
#include <vector>

double calculateAveragePrecision(const std::vector<int>& relevantResults) {
    int numRelevant = 0;
    double precisionSum = 0.0;

    for (size_t i = 0; i < relevantResults.size(); ++i) {
        if (relevantResults[i] == 1) { // 해당 결과가 relevant하면
            numRelevant++; // relevant 결과의 수 증가
            precisionSum += static_cast<double>(numRelevant) / (i + 1); // Precision 누적 합산
        }
    }

    if (numRelevant == 0) // relevant한 결과가 없는 경우
        return 0.0;

    return precisionSum / numRelevant; // Average Precision 반환
}

int main() {
    std::vector<int> relevantResults = { 1, 0, 1, 1, 0, 1, 0, 0, 1, 1 }; // 1이면 relevant, 0이면 non-relevant

    double averagePrecision = calculateAveragePrecision(relevantResults);
    std::cout << "Average Precision: " << averagePrecision << std::endl;

    return 0;
}