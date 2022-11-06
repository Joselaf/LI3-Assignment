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

void driver_add(Driver drv,CatDrivers cat){
    g_hash_table_insert(cat -> drivers, driver_get_id(drv), driver_clone(drv));
}

Driver cat_drivers_get_driver(CatDrivers cat , char* id){
    return g_hash_table_lookup(cat -> drivers, id);
}

CarClass cat_driver_get_class(CatDrivers cat, char*id){
    Driver r =(g_hash_table_lookup(cat -> drivers, id) );
    return driver_get_car_class(r);
}