#include "cat_rides.h"
#include <stdlib.h>
#include "glib-2.0/glib.h"

struct cat_rides{
    GHashTable *rides;
};


CatRides new_cat_rides(){
    CatRides rides = malloc(sizeof(struct cat_rides));

    rides->rides = g_hash_table_new(g_str_hash, g_str_equal);

    return rides;
}

void ride_add (Ride rd, CatRides cat){
    g_hash_table_insert(cat -> rides, ride_get_id(rd), ride_clone(rd));
}

Ride ride_get(CatRides cat, char* id){
    return g_hash_table_lookup(cat -> rides, id);
}
