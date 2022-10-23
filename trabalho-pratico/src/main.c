#include <stdio.h>
#include <string.h>
#include "glib-2.0/glib.h"

typedef enum payMethod {
    CASH = 0, 
    CREDIT_CARD = 1
} PayMethod;

typedef enum accountStatus {
    ACIVE = 0, 
    INACTIVE = 1
} AccountSatus;

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
    AccountSatus account_status;
} User;

 typedef struct driver{
    int id;
    char name[64];
    Date birth_date;
    Gender gender;
    char car_class[64];
    char license_plate[64];
    char city[64];
    Date account_creation;
    AccountSatus account_status;

 } Driver;

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

    chunck = strtok_r(NULL, ";", &rest);
    if(!strcmp(chunck,"inactive")){
        user.account_status = INACTIVE;
    }else{
        user.account_status = ACIVE;
    }
         
    return user;
}

Driver parsing_driver( char* driver){
    Driver drv;
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(driver, ";", &rest);
    drv.id = atoi(chunck);

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

     chunck = strtok_r(NULL, ";", &rest);
    if(!strcmp(chunck,"inactive")){
        drv.account_status = INACTIVE;
    }else{
        drv.account_status = ACIVE;
    }


    return drv;

}

void print_user(User sr){

    printf("username = %s, name = %s, gender=%d, birth_date = %d/%d/%d, account_date = %d/%d/%d, paymethod = %d, account_status = %d\n", 
        sr.username, 
        sr.name, 
        sr.gender, 
        sr.birth_date.day, 
        sr.birth_date.month, 
        sr.birth_date.year, 
        sr.account_creation.day, 
        sr.account_creation.month, 
        sr.account_creation.year,
        sr.pay_method,
        sr.account_status);

    return;
}

int main(){
    FILE *fp = fopen("dataset1/users.csv", "r");
    char str[256];

    fgets(str, 256, fp); // Ignore header
    while(fgets(str, 256, fp)){
        
        User sr = parsing_user(str);
        print_user(sr);
    }

    FILE *fp2 = fopen("dataset1/drivers.csv", "r");
    char str2[256];

    fgets(str2, 256, fp2);  //ignore header
    while(fgets(str2, 256, fp2)){
        Driver dr = parsing_driver(str2);
    }
    
    return 0;
}