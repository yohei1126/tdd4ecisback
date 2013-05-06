#include "TimeService.h"
#include "LightScheduler.h"
#include "LightController.h"

typedef enum {
	TURN_OFF,
	TURN_ON
} Event;

typedef struct {
	int id;
	Day day;
	int minuteOfDay;
	Event event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduldedEvent;

void LightScheduler_Create() {
	scheduldedEvent.id = UNUSED;
}

void LightScheduler_Destroy() {
}

void LightScheduler_Wakeup() {
	Time time;
	TimeService_GetTime(&time);

	if (scheduldedEvent.id == UNUSED) {
		return;
	}
	if (time.minuteOfDay != scheduldedEvent.minuteOfDay) {
		return;
	}

	if (scheduldedEvent.event == TURN_ON) {
		LightController_On(scheduldedEvent.id);
	} else {
		LightController_Off(scheduldedEvent.id);
	}
}

void LightScheduler_SchedulerTurnOn(int id, Day day, int minuteOfDay) {
	scheduldedEvent.id = id;
	scheduldedEvent.day = day;
	scheduldedEvent.minuteOfDay = minuteOfDay;
	scheduldedEvent.event = TURN_ON;
}

void LightScheduler_SchedulerTurnOff(int id, Day day, int minuteOfDay) {
	scheduldedEvent.id = id;
	scheduldedEvent.day = day;
	scheduldedEvent.minuteOfDay = minuteOfDay;
	scheduldedEvent.event = TURN_OFF;
}
