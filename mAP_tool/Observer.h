#pragma once
#include "Window.h"
#include "Event.h"

// 皋技瘤 傈价阑 贸府 (Window Communication)
class Observer
{
public:
    virtual ~Observer() {}
    virtual void OnNotify(const int IntEntity, EventEnum evet, void* mess) = 0;
};

