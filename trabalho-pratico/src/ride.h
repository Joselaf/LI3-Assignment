#ifndef RIE_H
#define RIDE_H

#include "common.h"


 typedef struct ride{
    char id[16];
    Date date;
    char driver[16];
    char user[32];
    char city[16];
    int distance;
    int score_user;
    int score_driver;
    double tip;
    char comment[128];

} Ride;


Ride parsing_ride(char *rideStr);

void print_ride(Ride rd);

#endif

