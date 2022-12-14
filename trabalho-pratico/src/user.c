#include "user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
    char username[64];
    char name[64];
    Gender gender;
    Date birth_date;
    Date account_creation;
    PayMethod pay_method;
    AccountStatus account_status;
} ;


User user_parsing(char* userStr){
    User user = malloc(sizeof(struct user));
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(userStr, ";", &rest);
    strcpy(user -> username, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(user -> name, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    if(chunck[0] == 'M'){
        user -> gender = M;
    }else{
        user -> gender = F;
    }

    chunck = strtok_r(NULL, ";", &rest);
    user -> birth_date = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    user -> account_creation = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    if(!strcmp(chunck, "cash")){
        user ->pay_method = CASH;

    }else if(!strcmp(chunck, "credit_card")){
        user ->pay_method = CREDIT_CARD;

    }else{
        user ->pay_method = DEBIT_CARD;
    }

    chunck = strtok_r(NULL, "\n", &rest);
    if(!strcmp(chunck,"active")){
        user -> account_status = ACTIVE;
    }else{
        user -> account_status = INACTIVE;
    }
         
    return user;
}

void user_print(User sr){
    if(sr == NULL){
        printf("NULL user\n");
    }else{
        printf("username = %s, name = %s, gender=%c, birth_date = %d/%d/%d, account_date = %d/%d/%d, paymethod = %s, account_status = %s\n", 
            sr -> username, 
            sr -> name, 
            Gender_translator(sr -> gender), 
            sr -> birth_date.day, 
            sr -> birth_date.month, 
            sr -> birth_date.year, 
            sr -> account_creation.day,
            sr -> account_creation.month, 
            sr -> account_creation.year,
            pay_mathod_translator(sr -> pay_method),
        accountStatus_translator(sr -> account_status));

    }

}
 void user_free(User usr){
      free(usr);
 }

 User user_clone(User original){
    User copy = malloc(sizeof(struct user));

    memcpy(copy,original, sizeof(struct user));

    return copy;
 }

 char* user_get_username(User sr){
    return strdup(sr->username);
 }

 char* user_get_gender(User sr){
    switch (sr->gender)
    {
    case M:
        return strdup("M");
        break;
    case F:
        return strdup("F");
        break;
    default:
        return strdup("I");
        break;
    }
 }

Date user_get_birth(User sr){
    return sr ->birth_date;
} 