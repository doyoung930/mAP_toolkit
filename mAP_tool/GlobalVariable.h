#pragma once

#include "vector"
#include "string"

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

private:
	std::vector<float> APArray;
	std::vector<std::string> CateArray;
};

