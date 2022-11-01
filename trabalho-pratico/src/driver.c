#include "driver.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct driver{
    char id[16];
    char name[32];
    Date birth_date;
    Gender gender;
    char car_class[16];
    char license_plate[16];
    char city[16];
    Date account_creation;
    AccountStatus account_status;

 } ;



Driver parsing_driver( char* driverStr){
    Driver drv = malloc(sizeof(struct driver));
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(driverStr, ";", &rest);
    strcpy(drv -> id, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv -> name, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    drv -> birth_date = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    if(chunck[0] == 'M'){
        drv -> gender = M;
    }else{
        drv -> gender = 'F';
    }

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv -> car_class, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv -> license_plate, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(drv -> city, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    drv -> account_creation = parsing_date(chunck);

     chunck = strtok_r(NULL, "\n", &rest);
    if(!strcmp(chunck,"inactive")){
        drv -> account_status = INACTIVE;
    }else{
        drv -> account_status = ACTIVE;
    }


    return drv;

}

void print_driver(Driver drv){

    if(drv == NULL){
        printf("NULL driver\n");
    }else{
        printf("id = %s, name = %s, birth_day = %d/%d/%d, gender = %c, car_class = %s, license_plate = %s, city = %s, accou_creation = %d/%d/%d, account_status = %s \n ",
            drv -> id,
            drv -> name,
            drv -> birth_date. day,
            drv -> birth_date.month,
            drv -> birth_date.year,
            Gender_translator(drv -> gender),
            drv -> car_class,
            drv -> license_plate,
            drv -> city,
            drv -> account_creation.day,
            drv -> account_creation.month,
            drv -> account_creation.year,
            accountStatus_translator(drv -> account_status));


    }


}

void free_driver(Driver drv){
        free(drv);
}

Driver clone_driver (Driver original){
    Driver copy = malloc(sizeof(struct driver));

    memcpy(copy, original, sizeof(struct driver));

    return copy;
}


char* driver_get_id(Driver drv){
    return strdup(drv -> id);
}