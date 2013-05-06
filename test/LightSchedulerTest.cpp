#include "CppUTest/TestHarness.h"

extern "C" {
#include "FakeTimeService.h"
#include "LightControllerSpy.h"
#include "LightScheduler.h"
#include "TimeService.h"
}

TEST_GROUP(LightScheduler) {
	void setup() {
		LightScheduler_Create();
		LightController_Create();
	}
	void teardown() {
		LightScheduler_Destroy();
		LightController_Destroy();
	}
};

TEST(LightScheduler, NoScheduleNothingHappens) {
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(100);
	LightScheduler_Wakeup();
	LONGS_EQUAL(TIME_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet) {
	LightScheduler_SchedulerTurnOn(3, EVERYDAY, 1200);

	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1199);
	LightScheduler_Wakeup();

	LONGS_EQUAL(TIME_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayItsTime) {
	LightScheduler_SchedulerTurnOn(3, EVERYDAY, 1200);

	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1200);
	LightScheduler_Wakeup();

	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOffEverydayItsTime) {
	LightScheduler_SchedulerTurnOff(3, EVERYDAY, 1200);

	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1200);
	LightScheduler_Wakeup();

	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_OFF, LightControllerSpy_GetLastState());
}
