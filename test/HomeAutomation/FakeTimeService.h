#ifndef FAKETIMESERVICE_H_
#define FAKETIMESERVICE_H_

#include "TimeService.h"

enum {
	TIME_UNKNOWN = -1
};

void FakeTimeService_SetMinute(int minute);

void FakeTimeService_SetDay(int day);

#endif /* FAKETIMESERVICE_H_ */
