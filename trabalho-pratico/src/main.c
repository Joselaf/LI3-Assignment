#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "glib-2.0/glib.h"

typedef enum payMethod {
    CASH = 0, 
    CREDIT_CARD = 1
} PayMethod;

typedef enum accountStatus {
    ACTIVE = 0, 
    INACTIVE = 1
} AccountStatus;

typedef enum gender{
    M = 0,
    F = 1
} Gender;

typedef struct date{
    int day;
    int month;
    int year;
}  Date;

 typedef struct user{
    char username[64];
    char name[64];
    Gender gender;
    Date birth_date;
    Date account_creation;
    PayMethod pay_method;
    AccountStatus account_status;
} User;

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

 typedef struct ride{
    char id[16];
    Date date;
    char driver[16];
    char user[32];
    char city[16];
    int distance;
    int score_user;
    int score_driver;
    double tip;
    char comment[128];

} Ride;

char* accountStatus_translator(AccountStatus status){
    switch(status){
        case ACTIVE:
            return "active";

        case INACTIVE:
            return "inactive";
    }
}

char* pay_mathod_translator(PayMethod method){
    switch(method){
        case CASH:
            return "cash";

        case CREDIT_CARD:
            return"credit_card";
    }
}

char Gender_translator(Gender g){
    switch(g){
        case M :
            return 'M';
        case F :
            return 'F';
    }
}

Date parsing_date(char* dateStr){
    Date date;
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(dateStr, "/", &rest);
    date.day = atoi(chunck);

    chunck = strtok_r(NULL, "/", &rest);
    date.month = atoi(chunck);

    chunck = strtok_r(NULL, "/", &rest);
    date.year = atoi(chunck);

    return date;
}

User parsing_user(char* userStr){
    User user;
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(userStr, ";", &rest);
    strcpy(user.username, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(user.name, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    if(chunck[0] == 'M'){
        user.gender = M;
    }else{
        user.gender = F;
    }

    chunck = strtok_r(NULL, ";", &rest);
    user.birth_date = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    user.account_creation = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    if(!strcmp(chunck,"cash")){
        user.pay_method = CASH;
    }else{
        user.pay_method = CREDIT_CARD;
    }

    chunck = strtok_r(NULL, "\n", &rest);
    if(!strcmp(chunck,"active")){
        user.account_status = ACTIVE;
    }else{
        user.account_status = INACTIVE;
    }
         
    return user;
}

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

Ride parsing_ride(char *rideStr){

    Ride rd;
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(rideStr, ";", &rest);
    strcpy(rd.id, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd.date = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(rd.driver, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(rd.user, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(rd.city, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd.distance = atoi(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd.score_user = atoi(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd.score_driver = atoi(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd.tip = atof(chunck);

    chunck = strtok_r(NULL, "\n", &rest);
    if(chunck) {
        strcpy(rd.comment, chunck);
    } else {
        rd.comment[0] = '\0';
    }


    return rd;

}

void print_user(User sr){

    printf("username = %s, name = %s, gender=%c, birth_date = %d/%d/%d, account_date = %d/%d/%d, paymethod = %s, account_status = %s\n", 
        sr.username, 
        sr.name, 
        Gender_translator(sr.gender), 
        sr.birth_date.day, 
        sr.birth_date.month, 
        sr.birth_date.year, 
        sr.account_creation.day, 
        sr.account_creation.month, 
        sr.account_creation.year,
        pay_mathod_translator(sr.pay_method),
       accountStatus_translator(sr.account_status));

    return;
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

void print_ride(Ride rd){
printf("id = %s, date = %d/%d/%d, driver = %s, city = %s,  distance = %d, score_user = %d, score_driver = %d, tip = %f, comment = %s \n",
rd.id,
rd.date.day,
rd.date.month,
rd.date.year,
rd.driver,
rd.city,
rd.distance,
rd.score_user,
rd.score_driver,
rd.tip,
rd.comment);


}


int main(){
    // FILE *fp = fopen("dataset1/users.csv", "r");
    // char str[256];

    // fgets(str, 256, fp); // Ignore header
    // while(fgets(str, 256, fp)){
        
    //     User sr = parsing_user(str);
    //     // print_user(sr);
    // }

    // FILE *fp2 = fopen("dataset1/drivers.csv", "r");
    // char str2[256];

    // fgets(str2, 256, fp2);  //ignore header
    // while(fgets(str2, 256, fp2)){
    //     Driver dr = parsing_driver(str2);
    //     // print_driver(dr);
    // }

    FILE *fp3 = fopen("dataset1/rides.csv", "r");
    char str3[256];

    fgets(str3, 256, fp3); //ignore header
    while(fgets(str3, 256, fp3)){
        Ride rd = parsing_ride(str3);
        print_ride(rd);
    }

    return 0;
}