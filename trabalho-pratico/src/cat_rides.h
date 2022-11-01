#ifndef CAT_RIDES_H
#define CAT_RIDES_H

#include "ride.h"

typedef struct cat_rides* CatRides;

CatRides new_cat_rides();

void add_ride(Ride rd, CatRides cat);

Ride get_ride(CatRides cat, char* id);









#endif