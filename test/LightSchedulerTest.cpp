#include "CppUTest/TestHarness.h"

extern "C" {
#include "FakeTimeService.h"
#include "LightControllerSpy.h"
#include "LightScheduler.h"
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
	LONGS_EQUAL(TIME_UNKNOWN, LightControllerSpy_GetLastState());
}
