#ifndef RIE_H
#define RIDE_H

#include "common.h"


typedef struct ride* Ride;


Ride parsing_ride(char *rideStr);

void print_ride(Ride rd);

void free_ride(Ride rd);

Ride clone_ride(Ride original);

char* get_id_ride(Ride rd);


#endif

