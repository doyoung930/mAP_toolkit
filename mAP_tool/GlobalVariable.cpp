#include "GlobalVariable.h"
#include "inference/Inference.h"
#include <random>

GlobalVariable::GlobalVariable()
{
    InitCategory();
    APArray.reserve(75);

    {
        // Graph 테스트를 위한 임시 Ap 저장
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
    CateArray.push_back("가");
    CateArray.push_back("나");
    CateArray.push_back("다");
    CateArray.push_back("라");
    CateArray.push_back("마");
    CateArray.push_back("바");
    CateArray.push_back("사");
    CateArray.push_back("아");
    CateArray.push_back("자");
    CateArray.push_back("거");
    CateArray.push_back("너");
    CateArray.push_back("더");
    CateArray.push_back("러");
    CateArray.push_back("머");
    CateArray.push_back("버");
    CateArray.push_back("서");
    CateArray.push_back("어");
    CateArray.push_back("저");
    CateArray.push_back("고");
    CateArray.push_back("노");
    CateArray.push_back("도");
    CateArray.push_back("로");
    CateArray.push_back("모");
    CateArray.push_back("보");
    CateArray.push_back("소");
    CateArray.push_back("오");
    CateArray.push_back("조");
    CateArray.push_back("구");
    CateArray.push_back("누");
    CateArray.push_back("두");
    CateArray.push_back("루");
    CateArray.push_back("무");
    CateArray.push_back("부");
    CateArray.push_back("수");
    CateArray.push_back("우");
    CateArray.push_back("주");
    CateArray.push_back("허");
    CateArray.push_back("하");
    CateArray.push_back("호");
    CateArray.push_back("배");
    CateArray.push_back("공");
    CateArray.push_back("해");
    CateArray.push_back("육");
    CateArray.push_back("합");
    CateArray.push_back("국");
    CateArray.push_back("울");
    CateArray.push_back("경");
    CateArray.push_back("기");
    CateArray.push_back("강");
    CateArray.push_back("원");
    CateArray.push_back("북");
    CateArray.push_back("대");
    CateArray.push_back("남");
    CateArray.push_back("전");
    CateArray.push_back("산");
    CateArray.push_back("제");
    CateArray.push_back("영");
    CateArray.push_back("충");
    CateArray.push_back("인");
    CateArray.push_back("천");
    CateArray.push_back("세");
    CateArray.push_back("종");
}