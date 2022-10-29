#ifndef CAT_DRIVERS_H
#define CAT_DRIVERS_H

#include "driver.h"


typedef struct cat_drivers* CatDrivers;


CatDrivers new_cat_driver();

void add_driver(Driver driver, CatDrivers cat);

Driver get_driver (CatDrivers cat, char* username );

Driver get_driver(CatDrivers cat, char* name);









#endif