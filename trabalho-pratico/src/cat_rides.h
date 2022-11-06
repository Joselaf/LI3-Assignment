#ifndef CAT_RIDES_H
#define CAT_RIDES_H

#include "ride.h"
#include "driver.h"
#include "cat_drivers.h"
#include "cat_users.h"
#include "common.h"

typedef struct cat_rides* CatRides;

CatRides new_cat_rides();

void ride_add(Ride rd, CatRides catR, CatDrivers catD, CatUsers catU);

Ride ride_get(CatRides cat, char* id);

int user_or_driver_stats_calculate_age(Date birth);

void user_stats_add(CatRides catR,CatDrivers catD, CatUsers catU, Ride rd);

void driver_stats_add(CatRides catR, CatDrivers catD, CatUsers catU, Ride rd);

int user_or_driver_stats_get_age(CatRides catR, char* id);

void user_or_driver_stats_add(CatRides catR, CatDrivers catD, CatUsers catU , Ride rd);

void driver_stats_add(CatRides catR,CatDrivers catD,CatUsers catU,Ride rd);

int user_or_driver_stats_get_distance(CatRides catR, char* id);

int user_or_driver_stats_get_nr_viagens(CatRides catR, char* id);

double user_or_driver_stats_get_avarage_rating(CatRides catR,char *id);

double user_or_driver_stats_get_total(CatRides catR, char *id);

int user_or_driver_stats_get_distace(CatRides catR, char* id);









#endif