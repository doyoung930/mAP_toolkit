#include "GlobalVariable.h"
#include "inference/Inference.h"
#include <random>

GlobalVariable::GlobalVariable()
{
    InitCategory();
    APArray.reserve(75);

    {
        // Graph �׽�Ʈ�� ���� �ӽ� Ap ����
        std::uniform_real_distribution<float> uid(0.f, 1.f);
        std::random_device rd;

        for (int i = 0; i < 75; i++)
        {
            APArray.push_back(uid(rd));
        }
    }

    inference = std::make_shared<Inference>();
}

void GlobalVariable::InitCategory()
{
    CateArray.clear();
    CateArray.reserve(75);

    CateArray.push_back("Unknown");
    CateArray.push_back("1");
    CateArray.push_back("2");
    CateArray.push_back("3");
    CateArray.push_back("4");
    CateArray.push_back("5");
    CateArray.push_back("6");
    CateArray.push_back("7");
    CateArray.push_back("8");
    CateArray.push_back("9");
    CateArray.push_back("0");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("ȣ");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("��");
    CateArray.push_back("õ");
    CateArray.push_back("��");
    CateArray.push_back("��");
}