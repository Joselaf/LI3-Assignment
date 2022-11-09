#ifndef COMMON_H
#define COMMON_H

typedef enum carClass{
    BASIC = 0,
    GREEN = 1,
    PREMIUM = 2
} CarClass;

typedef enum accountStatus {
    ACTIVE = 0, 
    INACTIVE = 1
} AccountStatus;

typedef enum gender{
    M = 0,
    F = 1
} Gender;

typedef enum payMethod {
    CASH = 0, 
    CREDIT_CARD = 1,
    DEBIT_CARD = 2,
} PayMethod;

typedef struct date{
    int day;
    int month;
    int year;
} Date;

char* accountStatus_translator(AccountStatus status);

Date parsing_date(char* dateStr);

char* pay_mathod_translator(PayMethod method);

char Gender_translator(Gender g);

char* car_class_translator(CarClass class);

int Datecmp(Date d1, Date d2);

#endif
