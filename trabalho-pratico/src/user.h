#ifndef USER_H
#define USER_H

#include "common.h"

typedef struct user* User;


User parsing_user(char* userStr);

void print_user(User sr);

void free_user(User usr);

User clone_user(User original);

char* get_username(User sr);

#endif 