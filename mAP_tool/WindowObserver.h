#pragma once

#include "Observer.h"
#include <queue>

class WindowObserver : public Observer
{
public:
    static WindowObserver* Instance()
    {
        static WindowObserver inst;
        return &inst;
    }

    virtual ~WindowObserver() {}
    virtual void OnNotify(const int IntEntity, EventEnum evet, void* mess);

    std::queue<Event>& GetQueue() { return EventQueue; }

private:
    std::queue<Event> EventQueue;
};

