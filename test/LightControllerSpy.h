#ifndef LIGHT_CONTROLLER_SPY_H
#define LIGHT_CONTROLLER_SPY_H

#include "LightController.h"

enum {
	LIGHT_ID_UNKNOWN = -1,
	LIGHT_STATE_UNKNOWN = -1,
	LIGHT_OFF = 0,
	LIGHT_ON = 1
};

int LightControllerSpy_GetLastId();

int LightControllerSpy_GetLastState();

#endif /* LIGHT_CONTROLLER_SPY_H */
