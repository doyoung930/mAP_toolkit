#pragma once
#include "Window.h"
#include "Event.h"

// 메세지 전송을 처리 (Window Communication)
class Observer
{
public:
    virtual ~Observer() {}
    virtual void OnNotify(const int IntEntity, EventEnum evet, void* mess) = 0;
};

