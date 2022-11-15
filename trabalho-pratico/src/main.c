#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "cat_users.h"
#include "cat_drivers.h"
#include "cat_rides.h"
#include "stats.h"


char* folder_file_cat(char * folder, char * file){
    int size = strlen(folder)+strlen(file)+2;
    char* location = malloc(sizeof(char) * size);

    strcpy(location, folder);
    strcat(location, "/");
    strcat(location, file);

    return location;

}

int main(int argc, char **argv){
     char* folder = argv[1];

    

    FILE *fp = fopen(folder_file_cat(folder, "users.csv"), "r");
    char str[256];
    CatUsers cat_users = new_cat_users();

    fgets(str, 256, fp); // Ignore header
    while(fgets(str, 256, fp)){
        
        User sr = user_parsing(str);
        user_add(sr, cat_users);
        user_free(sr);
    }

    FILE *fp2 = fopen(folder_file_cat(folder, "drivers.csv"), "r");
    char str2[256];
    CatDrivers cat_drivers = new_cat_driver();

    fgets(str2, 256, fp2);  //ignore header
    while(fgets(str2, 256, fp2)){
        Driver dr = driver_parsing(str2);
       driver_add(dr, cat_drivers);
        driver_free(dr);
    }

    FILE *fp3 = fopen(folder_file_cat(folder, "rides.csv"), "r");
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

    queries_file(s, argv[2]);




    return 0;
}

