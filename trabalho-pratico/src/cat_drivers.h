#ifndef CAT_DRIVERS_H
#define CAT_DRIVERS_H

#include "driver.h"


typedef struct cat_drivers* CatDrivers;


CatDrivers new_cat_driver();

void driver_add(Driver driver, CatDrivers cat);

Driver cat_drivers_get_driver(CatDrivers cat , char* id);

CarClass cat_driver_get_class(CatDrivers cat, char*id);










#endif