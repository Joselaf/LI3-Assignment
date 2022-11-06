
#include"common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char* accountStatus_translator(AccountStatus status){
    switch(status){
        case ACTIVE:
            return "active";

        case INACTIVE:
            return "inactive";
    }
    return "invalid";
}

char* pay_mathod_translator(PayMethod method){
    switch(method){
        case CASH:
            return "cash";
        case CREDIT_CARD:
            return"credit_card";
        case DEBIT_CARD:
            return "debit_card";
    }
    return "invalid";
}

char Gender_translator(Gender g){
    switch(g){
        case M :
            return 'M';
        case F :
            return 'F';
    }
    return 'I';

}

char* car_class_translator(CarClass class){
    switch (class)
    {
    case BASIC:
        return "basic";
        break;
    case GREEN:
        return "green";
        break;
    case PREMIUM:
        return "premium";
        break;
    }
}

