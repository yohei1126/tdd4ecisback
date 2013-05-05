#ifndef TIMESERVICE_H_
#define TIMESERVICE_H_

typedef struct {
	int minuteOfDay;
	int dayOfWeek;
} Time;

enum {
	TIME_UNKNOWN = -1,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

void TimeService_Create();

void TimeService_Destroy();

void TimeService_GetTime(Time* time);

#endif /* TIMESERVICE_H_ */
