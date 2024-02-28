#pragma once
enum class EventEnum
{
	SET_DIRECTORY_PATH,
	SET_CURRENT_SELECT,
	SET_IOU,
	UPDATE_IOU_GRAPH,
};

struct Event
{
	int Serial;
	EventEnum evet;
	void* mess;
};