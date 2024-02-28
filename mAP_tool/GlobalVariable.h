#pragma once

#include "vector"
#include "string"
#include <memory>

// 프로그램 전체적으로 사용할 전역변수를 싱글톤으로 관리
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
	// AP 값
	std::vector<float> APArray;

	// 0~9, 가, 나, 다... 에 대한 자료
	std::vector<std::string> CateArray;

	// 추론 객체
	std::shared_ptr<class Inference> inference;
};

