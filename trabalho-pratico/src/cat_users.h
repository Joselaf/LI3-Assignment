#ifndef CAT_USRS_H
#define CAT_USRS_H

#include "user.h"


typedef struct cat_users* CatUsers;
    

CatUsers new_cat_users();

void add_user(User user, CatUsers cat);

User get_user(CatUsers cat, char* username);

void free_cat_users();


#endif
