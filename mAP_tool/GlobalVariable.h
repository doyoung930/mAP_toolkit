#pragma once

#include "vector"
#include "string"
#include <memory>

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
	std::vector<float> APArray;
	std::vector<std::string> CateArray;

	std::shared_ptr<class Inference> inference;
};

