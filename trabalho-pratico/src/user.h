#ifndef USER_H
#define USER_H

#include "common.h"

typedef struct user* User;


User user_parsing(char* userStr);

void user_print(User sr);

void user_free(User usr);

User user_clone(User original);

char* user_get_username(User sr);

char* user_get_gender(User sr);

Date user_get_birth(User sr);

#endif 