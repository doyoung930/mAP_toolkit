#include "WindowObserver.h"

void WindowObserver::OnNotify(const int IntEntity, EventEnum evet, void* mess)
{
	Event e;
	e.Serial = IntEntity;
	e.evet = evet;
	e.mess = mess;

	EventQueue.push(e);
}
