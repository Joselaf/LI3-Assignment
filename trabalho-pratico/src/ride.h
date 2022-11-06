#ifndef RIE_H
#define RIDE_H

#include "common.h"


typedef struct ride* Ride;


Ride ride_parsing(char *rideStr);

void ride_print(Ride rd);

void ride_free(Ride rd);

Ride ride_clone(Ride original);

char* ride_get_id(Ride rd);

char* ride_get_driver(Ride rd);

char* ride_get_user(Ride rd);

int ride_get_distance(Ride rd);

double ride_get_score_user(Ride rd);

double ride_get_score_driver(Ride rd);

#endif

