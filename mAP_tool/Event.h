#pragma once
enum class EventEnum
{
	SET_DIRECTORY_PATH,
	SET_CURRENT_SELECT,
};

struct Event
{
	int Serial;
	EventEnum evet;
	void* mess;
};