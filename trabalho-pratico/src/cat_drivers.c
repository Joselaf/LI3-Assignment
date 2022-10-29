#include "cat_drivers.h"
#include <stdlib.h>
#include "glib-2.0/glib.h"


 struct cat_drivers{
    GHashTable *drivers;

};


CatDrivers new_cat_driver(){
    CatDrivers drivers = malloc(sizeof(struct cat_drivers));
    drivers -> drivers = g_hash_table_new(g_str_hash, g_str_equal);

    return drivers;
}

void add_driver(Driver drv,CatDrivers cat){
    g_hash_table_insert(cat -> drivers, get_id(drv), clone_driver(drv));
}

Driver get_driver(CatDrivers cat , char* name){
    return g_hash_table_lookup(cat -> drivers, name);
}
