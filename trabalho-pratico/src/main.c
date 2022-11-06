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
    FILE *fp = fopen("dataset1/users.csv", "r");
    char str[256];
    CatUsers cat_users = new_cat_users();

    fgets(str, 256, fp); // Ignore header
    while(fgets(str, 256, fp)){
        
        User sr = user_parsing(str);
        user_add(sr, cat_users);
        user_free(sr);
    }

    // User u = user_get(cat_users, "SMartins");

    // user_print(u);

    FILE *fp2 = fopen("dataset1/drivers.csv", "r");
    char str2[256];
    CatDrivers cat_drivers = new_cat_driver();

    fgets(str2, 256, fp2);  //ignore header
    while(fgets(str2, 256, fp2)){
        Driver dr = driver_parsing(str2);
       driver_add(dr, cat_drivers);
        driver_free(dr);
    }

    FILE *fp3 = fopen("dataset1/rides.csv", "r");
    char str3[256];
    CatRides cat_rides = new_cat_rides();

    fgets(str3, 256, fp3); //ignore header
    while(fgets(str3, 256, fp3)){
        Ride rd = ride_parsing(str3);
        ride_add(rd, cat_rides, cat_drivers, cat_users);

        ride_free(rd);
    }
        // Ride rd = ride_get(cat_rides, "000000000002");

        // ride_print(rd);

    
    Stats s = stats_new(cat_users, cat_drivers, cat_rides);

    Results res = Q1_get_user_or_driver( s, "MiTeixeira" );



    // puts(stats_results_get_cell(res, 0, 0));
    printf("username = %s, gender = %s, idade = %s, avarage_rating = %s, nr_viagens = %s, total = %s\n", stats_results_get_cell(res, 0, 0), stats_results_get_cell(res, 0,1), stats_results_get_cell(res, 0, 2), stats_results_get_cell(res, 0, 3), stats_results_get_cell(res, 0, 4), stats_results_get_cell(res, 0, 5));

    // printf("avaliacao = %f", user_stats_get_avalicao_media(cat_rides, "AMatias"));



    return 0;
}