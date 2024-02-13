#pragma once
enum class EventEnum
{
	SET_DIRECTORY_PATH,
};

struct Event
{
	int Serial;
	EventEnum evet;
	void* mess;
};