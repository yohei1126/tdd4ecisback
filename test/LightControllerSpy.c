#include "LightControllerSpy.h"

static int lastId;
static int lastState;

void LightController_Create() {
	lastId = LIGHT_ID_UNKNOWN;
	lastState = LIGHT_STATE_UNKNOWN;
}

void LightController_Destroy() {
}

void LightController_On(int id) {
	lastId = id;
	lastState = LIGHT_ON;
}

void LightController_Off(int id) {
	lastId = id;
	lastState = LIGHT_OFF;
}

int LightControllerSpy_GetLastId() {
	return lastId;
}

int LightControllerSpy_GetLastState() {
	return lastState;
}
