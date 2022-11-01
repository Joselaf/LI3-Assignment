#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "cat_users.h"
#include "cat_drivers.h"
#include "cat_rides.h"
#include "stats.h"



int main(){
    // FILE *fp = fopen("dataset1/users.csv", "r");
    // char str[256];
    // CatUsers cat_users = new_cat_users();

    // fgets(str, 256, fp); // Ignore header
    // while(fgets(str, 256, fp)){
        
    //     User sr = user_parsing(str);
    //     user_add(sr, cat_users);
    //     user_free(sr);
    // }

    // User u = user_get(cat_users, "SMartins");

    // user_print(u);

    // FILE *fp2 = fopen("dataset1/drivers.csv", "r");
    // char str2[256];
    // CatDrivers cat_drivers = new_cat_driver();

    // fgets(str2, 256, fp2);  //ignore header
    // while(fgets(str2, 256, fp2)){
    //     Driver dr = driver_parsing(str2);
    //    driver_add(dr, cat_drivers);
    //     driver_free(dr);
    // }

    // Driver drv = driver_get(cat_drivers, "000000009967");

    // driver_print(drv);

    // FILE *fp3 = fopen("dataset1/rides.csv", "r");
    // char str3[256];
    // CatRides cat_rides = new_cat_rides();

    // fgets(str3, 256, fp3); //ignore header
    // while(fgets(str3, 256, fp3)){
    //     Ride rd = ride_parsing(str3);
    //     ride_add(rd, cat_rides);
    //     ride_free(rd);
    // }
    //     Ride rd = ride_get(cat_rides, "000000000002");

    //     ride_print(rd);

    Results res = stats_result_new();

    stats_results_add_row(res);
    stats_results_add_cell(res, "007");
    stats_results_add_cell(res, "james Bond");
    stats_results_add_cell(res, "9.9");

    stats_results_add_row(res);
    stats_results_add_cell(res, "055");
    stats_results_add_cell(res, "zidane");
    stats_results_add_cell(res, "6.6");

    // puts(stats_results_get_cell(res, 0, 0));
   printf("id= %s, name= %s, points= %s \n id= %s, name= %s, points= %s", stats_results_get_cell(res, 0, 0), stats_results_get_cell(res, 0,1), stats_results_get_cell(res, 0,2), stats_results_get_cell(res, 1,0), stats_results_get_cell(res, 1,1), stats_results_get_cell(res, 1, 2));


    return 0;
}