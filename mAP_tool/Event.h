#pragma once
enum class EventEnum
{
	SET_DIRECTORY_PATH,
	SET_CURRENT_SELECT,
	SET_IOU,
};

struct Event
{
	int Serial;
	EventEnum evet;
	void* mess;
};