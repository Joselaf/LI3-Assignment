#include "cat_rides.h"
#include <stdlib.h>
#include "glib-2.0/glib.h"
#define MONTH (10)
#define DAY (9)
#define YEAR (2022)

typedef struct user_or_driver_stats{
    int idade;
    int nr_viagens;
    int distancia;
    double score;
    double total_envolvido;
};
struct cat_rides{
    GHashTable *rides;
    GHashTable *user_or_driver_stats;
    
};


CatRides new_cat_rides(){
    CatRides rides = malloc(sizeof(struct cat_rides));

    rides->rides = g_hash_table_new(g_str_hash, g_str_equal);
    rides ->user_or_driver_stats = g_hash_table_new(g_str_hash, g_str_equal);

    return rides;
}

void ride_add (Ride rd, CatRides catR, CatDrivers catD, CatUsers catU){
    g_hash_table_insert(catR -> rides, ride_get_id(rd), ride_clone(rd));
    user_stats_add(catR, catD, catU, rd);
    driver_stats_add(catR, catD, catU, rd);

}

int user_or_driver_stats_calculate_age(Date birth){
    int idade = (YEAR - birth.year);

    if(birth.month < MONTH ){
        idade--;
    }else if(birth.month == MONTH){
        if( birth.day  < DAY){

        }else{
            idade--;
        }
    }
    return idade;

}


Ride ride_get(CatRides cat, char* id){
    return g_hash_table_lookup(cat -> rides, id);
}

void driver_stats_add(CatRides catR,CatDrivers catD,CatUsers catU,Ride rd){
    if(g_hash_table_contains(catR -> user_or_driver_stats , ride_get_driver(rd))){
        struct user_or_driver_stats *st = (struct user_or_driver_stats*)g_hash_table_lookup(catR -> user_or_driver_stats, ride_get_driver(rd));
        st -> nr_viagens++;
        st -> distancia += ride_get_distance(rd);
        st -> score += ride_get_score_driver(rd);
        CarClass c3= cat_driver_get_class(catD, ride_get_driver(rd));
        switch (c3)
        {
        case BASIC:
            st -> total_envolvido += 3.25 + ride_get_distance(rd)*0.62;
            break;
        
        case GREEN:
            st -> total_envolvido += 4 + ride_get_distance(rd)*0.79;
            break;
        case PREMIUM:
            st -> total_envolvido += 5.2 + ride_get_distance(rd)*0.94;
        }
        g_hash_table_insert(catR -> user_or_driver_stats, ride_get_driver(rd), st);

    }else{
        struct user_or_driver_stats *st =  malloc(sizeof(struct user_or_driver_stats));
        st -> idade = user_or_driver_stats_calculate_age(driver_get_birth(cat_drivers_get_driver(catD,(ride_get_driver(rd)))));
        st -> nr_viagens = 1;
        st -> distancia = ride_get_distance(rd);
        st -> score = ride_get_score_driver(rd);
        CarClass c4 = cat_driver_get_class(catD, ride_get_driver(rd));
        switch (c4)
        {
        case BASIC:
            st -> total_envolvido = 3.25 + ride_get_distance(rd)*0.62;
            break;
        
        case GREEN:
            st -> total_envolvido = 4 + ride_get_distance(rd)*0.79;
            break;
        case PREMIUM:
            st -> total_envolvido = 5.2 + ride_get_distance(rd)*0.94;
        }

        g_hash_table_insert(catR ->user_or_driver_stats, ride_get_driver(rd), st);
    }

}


void user_stats_add(CatRides catR, CatDrivers catD, CatUsers catU, Ride rd){
    if(g_hash_table_contains(catR -> user_or_driver_stats, ride_get_user(rd))){
        struct user_or_driver_stats *st = (struct user_or_driver_stats*)g_hash_table_lookup(catR -> user_or_driver_stats, ride_get_user(rd));
        st -> nr_viagens++;
        st -> distancia += ride_get_distance(rd);
        st -> score += ride_get_score_user(rd);
        CarClass c2= cat_driver_get_class(catD, ride_get_driver(rd));
        switch (c2)
        {
        case BASIC:
            st -> total_envolvido += 3.25 + ride_get_distance(rd)*0.62;
            break;
        
        case GREEN:
            st -> total_envolvido += 4 + ride_get_distance(rd)*0.79;
            break;
        case PREMIUM:
            st -> total_envolvido += 5.2 + ride_get_distance(rd)*0.94;
        }
        g_hash_table_insert(catR ->user_or_driver_stats, ride_get_user(rd), st);

    }else{
        struct user_or_driver_stats *st =  malloc(sizeof(struct user_or_driver_stats));
        st -> idade = user_or_driver_stats_calculate_age(user_get_birth(cat_users_get_user(catU,(ride_get_user(rd)))));
        st -> nr_viagens = 1;
        st -> distancia = ride_get_distance(rd);
        st -> score = ride_get_score_user(rd);
        CarClass c1 = cat_driver_get_class(catD, ride_get_driver(rd));
        switch (c1)
        {
        case BASIC:
            st -> total_envolvido = 3.25 + ride_get_distance(rd)*0.62;
            break;
        
        case GREEN:
            st -> total_envolvido = 4 + ride_get_distance(rd)*0.79;
            break;
        case PREMIUM:
            st -> total_envolvido = 5.2 + ride_get_distance(rd)*0.94;
        }

        g_hash_table_insert(catR ->user_or_driver_stats, ride_get_user(rd), st);
    }
}

int user_or_driver_stats_get_nr_viagens(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_or_driver_stats, id);

    return st -> nr_viagens;
}

int user_or_driver_stats_get_age(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_or_driver_stats, id);

    return st -> idade;
}

int user_or_driver_stats_get_distace(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_or_driver_stats, id);

    return st -> distancia;
}

double user_or_driver_stats_get_avarage_rating(CatRides catR,char *id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_or_driver_stats, id);
    return((st -> score)/(st -> nr_viagens));
}

double user_or_driver_stats_get_total(CatRides catR, char *id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_or_driver_stats, id);

    return(st -> total_envolvido);
}





