#ifndef DRIVER_H
#define DRIVER_h

#include "common.h"

typedef struct driver* Driver;


 Driver driver_parsing( char* driverStr);

 void driver_print(Driver drv);

 void driver_free(Driver drv);

Driver driver_clone(Driver original);

char* driver_get_id(Driver drv);

char* driver_get_gender(Driver drv);

CarClass driver_get_car_class(Driver drv);

Date driver_get_birth(Driver drv);

char* driver_get_city(Driver drv);

char* driver_get_name(Driver drv);



#endif