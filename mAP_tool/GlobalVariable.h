#pragma once

#include "vector"
#include "string"
#include <memory>

// ���α׷� ��ü������ ����� ���������� �̱������� ����
class GlobalVariable
{
public:
	static GlobalVariable* Instance()
	{
		static GlobalVariable inst;
		return &inst;
	}

	GlobalVariable();
	~GlobalVariable() {};

	void InitCategory();

	std::vector<float>& GetApArray() { return APArray; }
	std::vector<std::string>& GetCateArray() { return CateArray; }
	std::shared_ptr<class Inference> GetInference() { return inference; }

private:
	// AP ��
	std::vector<float> APArray;

	// 0~9, ��, ��, ��... �� ���� �ڷ�
	std::vector<std::string> CateArray;

	// �߷� ��ü
	std::shared_ptr<class Inference> inference;
};

