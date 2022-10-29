#ifndef DRIVER_H
#define DRIVER_h

#include "common.h"

typedef struct driver* Driver;


 Driver parsing_driver( char* driverStr);

 void print_driver(Driver drv);

 void free_driver(Driver drv);

Driver clone_driver(Driver original);

char* get_id(Driver drv);



#endif