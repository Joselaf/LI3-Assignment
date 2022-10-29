#include "driver.h"
#include <stdio.h>
#include <string.h>



Driver parsing_driver( char* driverStr){
    Driver drv;
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(driverStr, ";", &rest);
    strcpy(drv.id, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv.name, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    drv.birth_date = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    if(chunck[0] == 'M'){
        drv.gender = M;
    }else{
        drv.gender = 'F';
    }

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv.car_class, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv.license_plate, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv.city, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    drv.account_creation = parsing_date(chunck);

     chunck = strtok_r(NULL, "\n", &rest);
    if(!strcmp(chunck,"inactive")){
        drv.account_status = INACTIVE;
    }else{
        drv.account_status = ACTIVE;
    }


    return drv;

}

void print_driver(Driver drv){

    printf("id = %s, name = %s, birth_day = %d/%d/%d, gender = %c, car_class = %s, license_plate = %s, city = %s, accou_creation = %d/%d/%d, account_status = %s \n ",
        drv.id,
        drv.name,
        drv.birth_date.day,
        drv.birth_date.month,
        drv.birth_date.year,
        Gender_translator(drv.gender),
        drv.car_class,
        drv.license_plate,
        drv.city,
        drv.account_creation.day,
        drv.account_creation.month,
        drv.account_creation.year,
        accountStatus_translator(drv.account_status));

}