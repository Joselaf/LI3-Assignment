#ifndef CAT_DRIVERS_H
#define CAT_DRIVERS_H

#include "driver.h"


typedef struct cat_drivers* CatDrivers;


CatDrivers new_cat_driver();

void driver_add(Driver driver, CatDrivers cat);


Driver driver_get(CatDrivers cat, char* id);









#endif