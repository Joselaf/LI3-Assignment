#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "cat_users.h"
#include "cat_drivers.h"



int main(){
    FILE *fp = fopen("dataset1/users.csv", "r");
    char str[256];
    CatUsers cat_users = new_cat_users();

    fgets(str, 256, fp); // Ignore header
    while(fgets(str, 256, fp)){
        
        User sr = parsing_user(str);
        add_user(sr, cat_users);
        free_user(sr);
    }

    // User u = get_user(cat_users, "DiniAndrade17");

    // print_user(u);

    FILE *fp2 = fopen("dataset1/drivers.csv", "r");
    char str2[256];
    CatDrivers cat_drivers = new_cat_driver();

    fgets(str2, 256, fp2);  //ignore header
    while(fgets(str2, 256, fp2)){
        Driver dr = parsing_driver(str2);
       add_driver(dr, cat_drivers);
        free_driver(dr);
    }

    Driver drv = get_driver(cat_drivers, "000000009967");

    print_driver(drv);

    // FILE *fp3 = fopen("dataset1/rides.csv", "r");
    // char str3[256];

    // fgets(str3, 256, fp3); //ignore header
    // while(fgets(str3, 256, fp3)){
    //     Ride rd = parsing_ride(str3);
    //     // print_ride(rd);
    // }

    return 0;
}