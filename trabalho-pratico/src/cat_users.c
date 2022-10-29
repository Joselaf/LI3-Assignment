#include "cat_users.h"
#include <stdlib.h>
#include "glib-2.0/glib.h"


typedef struct cat_users{
    GHashTable *users;
};

/*
querie 1 
    user by id

querie 8
    uses by account age
    users by gender
querie 9
    
*/


CatUsers new_cat_users(){
    CatUsers users = malloc(sizeof(struct cat_users));
    users->users = g_hash_table_new(g_str_hash, g_str_equal);
    return users;
}

void add_user(User user, CatUsers cat){
    User *user_ptr = malloc(sizeof(User));
    memcpy(user_ptr, &user, sizeof(User));
    g_hash_table_insert(cat->users,strdup(user.username), user_ptr);
}

User get_user(CatUsers cat, char* username){
    User u;

    u = *(User*)g_hash_table_lookup(cat->users,username);

    return u;

}