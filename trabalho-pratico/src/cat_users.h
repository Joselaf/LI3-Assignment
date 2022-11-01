#ifndef CAT_USERS_H
#define CAT_USERS_H

#include "user.h"


typedef struct cat_users* CatUsers;
    

CatUsers new_cat_users();

void user_add(User user, CatUsers cat);

User user_get(CatUsers cat, char* username);

void free_cat_users();


#endif
 