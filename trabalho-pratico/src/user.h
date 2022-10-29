#ifndef USER_H
#define USER_H

#include "common.h"

typedef struct user {
    char username[64];
    char name[64];
    Gender gender;
    Date birth_date;
    Date account_creation;
    PayMethod pay_method;
    AccountStatus account_status;
} User;


User parsing_user(char* userStr);

void print_user(User sr);

#endif 