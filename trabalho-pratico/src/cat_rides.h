#ifndef CAT_RIDES_H
#define CAT_RIDES_H

#include "ride.h"
#include "driver.h"
#include "cat_drivers.h"
#include "cat_users.h"
#include "cat_rides.h"
#include "common.h"
#include "glib-2.0/glib.h"


typedef struct cat_rides* CatRides;

CatRides new_cat_rides();

void ride_add(Ride rd, CatRides catR, CatDrivers catD, CatUsers catU);

Ride ride_get(CatRides cat, char* id);

int user_or_driver_stats_calculate_age(Date birth);

void user_stats_add(CatRides catR,CatDrivers catD, CatUsers catU, Ride rd);

void driver_stats_add(CatRides catR, CatDrivers catD, CatUsers catU, Ride rd);

void user_or_driver_stats_add(CatRides catR, CatDrivers catD, CatUsers catU , Ride rd);

void driver_stats_add(CatRides catR,CatDrivers catD,CatUsers catU,Ride rd);

void city_stats_add(CatRides catR, CatDrivers catD, CatUsers catU, Ride rd);

int user_stats_get_nr_viagens(CatRides catR, char* id);

int driver_stats_get_nr_viagens(CatRides catR, char* id);

int user_stats_get_age(CatRides catR, char* id);

int driver_stats_get_age(CatRides catR, char* id);


int user_stats_get_distace(CatRides catR, char* id);

double user_stats_get_avarage_rating(CatRides catR,char *id);

double driver_stats_get_avarage_rating(CatRides catR,char *id);

double user_stats_get_total(CatRides catR, char *id);

double driver_stats_get_total(CatRides catR, char *id);

GArray* get_top_drivers(CatRides catR);


int city_stats_get_distance(CatRides cat, char* id);

int city_stats_get_nr_viagens(CatRides catR, char *id);

double city_stats_get_total(CatRides catR, char* id);

GArray* get_top_drivers(CatRides catR);

double cat_rides_get_driver_avarage_score(CatRides catR, char* id);



#endif