#include "cat_users.h"
#include <stdlib.h>
#include "glib-2.0/glib.h"


struct cat_users{
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
    
    g_hash_table_insert(cat->users, get_username(user), clone_user(user));
}

User get_user(CatUsers cat, char* username){
    return g_hash_table_lookup(cat->users,username);
}