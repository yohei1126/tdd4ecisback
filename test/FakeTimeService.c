#include "FakeTimeService.h"

static Time time_;

void TimeService_Create() {
	time_.dayOfWeek = TIME_UNKNOWN;
	time_.minuteOfDay = TIME_UNKNOWN;
}

void TimeService_Destroy() {
}

void TimeService_GetTime(Time* time) {
	time->dayOfWeek = time_.dayOfWeek;
	time->minuteOfDay = time_.minuteOfDay;
}

void FakeTimeService_SetMinute(int minute) {
	time_.minuteOfDay = minute;
}

void FakeTimeService_SetDay(int day) {
	time_.dayOfWeek = day;
}
