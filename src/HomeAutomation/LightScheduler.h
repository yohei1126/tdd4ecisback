#ifndef LIGHTSCHEDULER_H_
#define LIGHTSCHEDULER_H_

typedef enum {
	SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY,
	EVERYDAY = 100, WEEKDAY, WEEKEND
} Day;

void LightScheduler_Create(void);

void LightScheduler_Destroy(void);

void LightScheduler_Wakeup(void);

void LightScheduler_SchedulerTurnOn(int id, Day day, int minuteOfDay);

void LightScheduler_SchedulerTurnOff(int id, Day day, int minuteOfDay);

#endif /* LIGHTSCHEDULER_H_ */
