#ifndef TIMESERVICE_H_
#define TIMESERVICE_H_

typedef struct {
	int minuteOfDay;
	int dayOfWeek;
} Time;

void TimeService_Create(void);

void TimeService_Destroy(void);

void TimeService_GetTime(Time* time);

#endif /* TIMESERVICE_H_ */
