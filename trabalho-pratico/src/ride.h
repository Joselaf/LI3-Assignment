#ifndef RIE_H
#define RIDE_H

#include "common.h"


typedef struct ride* Ride;


Ride ride_parsing(char *rideStr);

void ride_print(Ride rd);

void ride_free(Ride rd);

Ride ride_clone(Ride original);

char* ride_get_id(Ride rd);


#endif

