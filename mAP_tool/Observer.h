#pragma once
#include "Window.h"
#include "Event.h"

// �޼��� ������ ó�� (Window Communication)
class Observer
{
public:
    virtual ~Observer() {}
    virtual void OnNotify(const int IntEntity, EventEnum evet, void* mess) = 0;
};

