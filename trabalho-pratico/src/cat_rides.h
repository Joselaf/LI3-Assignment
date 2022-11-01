#ifndef CAT_RIDES_H
#define CAT_RIDES_H

#include "ride.h"

typedef struct cat_rides* CatRides;

CatRides new_cat_rides();

void ride_add(Ride rd, CatRides cat);

Ride ride_get(CatRides cat, char* id);









#endif