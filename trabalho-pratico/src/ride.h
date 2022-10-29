#ifndef RIE_H
#define RIDE_H

#include "common.h"


typedef struct ride* Ride;


Ride parsing_ride(char *rideStr);

void print_ride(Ride rd);

void free_ride(Ride rd);

Ride clone_ride(Ride original);

// char* get_id(Ride rd);

// Date get_date(Ride rd);

// char* get_driver(Ride rd);

// char* get_user(Ride rd):

// char* get_city(Ride rd);

// int get_distance(Rid rd);

// int get_score_user(Ride rd);

// int get_score_driver(Ride rd);

// double get_tip

#endif

