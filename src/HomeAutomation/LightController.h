#ifndef LIGHTCONTROLLER_H_
#define LIGHTCONTROLLER_H_

enum {
	LIGHT_ID_UNKNOWN = -1,
	UNUSED
};

typedef enum {
	LIGHT_STATE_UNKNOWN = -1,
	LIGHT_OFF = 0,
	LIGHT_ON = 1
} LightState;

void LightController_Create(void);

void LightController_Destroy(void);

void LightController_On(int id);

void LightController_Off(int id);

#endif /* LIGHTCONTROLLER_H_ */
