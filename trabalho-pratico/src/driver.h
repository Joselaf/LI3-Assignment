#ifndef DRIVER_H
#define DRIVER_h

#include "common.h"

 typedef struct driver{
    char id[16];
    char name[32];
    Date birth_date;
    Gender gender;
    char car_class[16];
    char license_plate[16];
    char city[16];
    Date account_creation;
    AccountStatus account_status;

 } Driver;

 Driver parsing_driver( char* driverStr);

 void print_driver(Driver drv);


#endif