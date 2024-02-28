#include <iostream>
#include <vector>

double calculateAveragePrecision(const std::vector<int>& relevantResults) {
    int numRelevant = 0;
    double precisionSum = 0.0;

    for (size_t i = 0; i < relevantResults.size(); ++i) {
        if (relevantResults[i] == 1) { // �ش� ����� relevant�ϸ�
            numRelevant++; // relevant ����� �� ����
            precisionSum += static_cast<double>(numRelevant) / (i + 1); // Precision ���� �ջ�
        }
    }

    if (numRelevant == 0) // relevant�� ����� ���� ���
        return 0.0;

    return precisionSum / numRelevant; // Average Precision ��ȯ
}

int main() {
    std::vector<int> relevantResults = { 1, 0, 1, 1, 0, 1, 0, 0, 1, 1 }; // 1�̸� relevant, 0�̸� non-relevant

    double averagePrecision = calculateAveragePrecision(relevantResults);
    std::cout << "Average Precision: " << averagePrecision << std::endl;

    return 0;
}