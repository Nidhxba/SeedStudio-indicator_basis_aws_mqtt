#ifndef INDICATOR_SENSOR_H
#define INDICATOR_SENSOR_H

#include "config.h"
#include "view_data.h"
#include "driver/uart.h"


#ifdef __cplusplus
extern "C" {
#endif


int indicator_sensor_init(void);
// int sensor_data_task(void);

#ifdef __cplusplus
}
#endif

// float getco2();
// float gettVOC();


#endif
