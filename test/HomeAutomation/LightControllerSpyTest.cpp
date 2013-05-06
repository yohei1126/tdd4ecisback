#include "CppUTest/TestHarness.h"

extern "C" {
#include "LightControllerSpy.h"
}

TEST_GROUP(LightControllerSpy) {
	void setup() {
		LightController_Create();
	}
	void teardown() {
		LightController_Destroy();
	}
};

TEST(LightControllerSpy, Create) {
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightControllerSpy, RememberTheLastIdControllerdOn) {
	LightController_On(10);
	LONGS_EQUAL(10, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

TEST(LightControllerSpy, RememberTheLastIdControllerdOff) {
	LightController_Off(10);
	LONGS_EQUAL(10, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_OFF, LightControllerSpy_GetLastState());
}
