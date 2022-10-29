#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "cat_users.h"



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

    User u = get_user(cat_users, "DiniAndrade17");

    print_user(u);

    // FILE *fp2 = fopen("dataset1/drivers.csv", "r");
    // char str2[256];

    // fgets(str2, 256, fp2);  //ignore header
    // while(fgets(str2, 256, fp2)){
    //     Driver dr = parsing_driver(str2);
    //     // print_driver(dr);
    // }

    // FILE *fp3 = fopen("dataset1/rides.csv", "r");
    // char str3[256];

    // fgets(str3, 256, fp3); //ignore header
    // while(fgets(str3, 256, fp3)){
    //     Ride rd = parsing_ride(str3);
    //     // print_ride(rd);
    // }

    return 0;
}