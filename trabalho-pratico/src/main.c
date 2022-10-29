#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "glib-2.0/glib.h"
#include "driver.h"
#include "user.h"
#include "ride.h"




int main(){
    FILE *fp = fopen("dataset1/users.csv", "r");
    char str[256];

    fgets(str, 256, fp); // Ignore header
    while(fgets(str, 256, fp)){
        
        User sr = parsing_user(str);
        // print_user(sr);
    }

    FILE *fp2 = fopen("dataset1/drivers.csv", "r");
    char str2[256];

    fgets(str2, 256, fp2);  //ignore header
    while(fgets(str2, 256, fp2)){
        Driver dr = parsing_driver(str2);
        // print_driver(dr);
    }

    FILE *fp3 = fopen("dataset1/rides.csv", "r");
    char str3[256];

    fgets(str3, 256, fp3); //ignore header
    while(fgets(str3, 256, fp3)){
        Ride rd = parsing_ride(str3);
        // print_ride(rd);
    }

    return 0;
}