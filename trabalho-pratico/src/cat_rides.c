#include "cat_rides.h"
#include <stdlib.h>
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

typedef struct city_stats{
    Date date;
    int nr_viagens;
    int distance;
    double total;
};

struct cat_rides{
    GHashTable *rides;
    GHashTable *user_stats;
    GHashTable *driver_stats;
    GHashTable *city_stats;

    
};


CatRides new_cat_rides(){
    CatRides rides = malloc(sizeof(struct cat_rides));

    rides->rides = g_hash_table_new(g_str_hash, g_str_equal);
    rides ->user_stats = g_hash_table_new(g_str_hash, g_str_equal);
    rides -> driver_stats = g_hash_table_new(g_str_hash, g_str_equal);
    rides -> city_stats = g_hash_table_new(g_str_hash, g_str_equal);


    return rides;
}

void ride_add (Ride rd, CatRides catR, CatDrivers catD, CatUsers catU){
    g_hash_table_insert(catR -> rides, ride_get_id(rd), ride_clone(rd));
    user_stats_add(catR, catD, catU, rd);
    driver_stats_add(catR, catD, catU, rd);
    city_stats_add(catR, catD, catU, rd);


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
    if(g_hash_table_contains(catR -> driver_stats , ride_get_driver(rd))){
        struct user_or_driver_stats *st = (struct user_or_driver_stats*)g_hash_table_lookup(catR -> driver_stats, ride_get_driver(rd));
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
        g_hash_table_insert(catR -> driver_stats, ride_get_driver(rd), st);

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

        g_hash_table_insert(catR ->driver_stats, ride_get_driver(rd), st);
    }

}


void user_stats_add(CatRides catR, CatDrivers catD, CatUsers catU, Ride rd){
    if(g_hash_table_contains(catR -> user_stats, ride_get_user(rd))){
        struct user_or_driver_stats *st = (struct user_or_driver_stats*)g_hash_table_lookup(catR -> user_stats, ride_get_user(rd));
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
        g_hash_table_insert(catR ->user_stats, ride_get_user(rd), st);

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

        g_hash_table_insert(catR ->user_stats, ride_get_user(rd), st);
    }
}

void city_stats_add(CatRides catR, CatDrivers catD, CatUsers catU, Ride rd){
    char * city = ride_get_city(rd);

    if(g_hash_table_contains(catR -> city_stats, rd)){
        struct city_stats *st = (struct city_stats*)g_hash_table_lookup(catR -> city_stats, city);

        st -> nr_viagens++;
        st -> distance += ride_get_distance(rd);

        CarClass c1 = cat_driver_get_class(catD, ride_get_driver(rd));
        switch (c1)
        {
        case BASIC:
            st -> total += 3.25 + ride_get_distance(rd)*0.62;
            break;
        
        case GREEN:
            st -> total += 4 + ride_get_distance(rd)*0.79;
            break;
        case PREMIUM:
            st -> total += 5.2 + ride_get_distance(rd)*0.94;
        }
        g_hash_table_insert(catR -> city_stats, city, st);
        
    }else{
        struct city_stats *st = malloc(sizeof(struct city_stats));
            st -> nr_viagens = 1;
            st -> distance = ride_get_distance(rd);
             CarClass c1 = cat_driver_get_class(catD, ride_get_driver(rd));
        switch (c1){
        case BASIC:
            st -> total = 3.25 + ride_get_distance(rd)*0.62;
            break;
        
        case GREEN:
            st -> total = 4 + ride_get_distance(rd)*0.79;
            break;
        case PREMIUM:
            st -> total = 5.2 + ride_get_distance(rd)*0.94;

        }
        g_hash_table_insert(catR -> city_stats, city, st);
        
    }


}



int user_stats_get_nr_viagens(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_stats, id);

    return st -> nr_viagens;
}

int driver_stats_get_nr_viagens(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> driver_stats, id);

    return st -> nr_viagens;
}

int user_stats_get_age(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_stats, id);

    return st -> idade;
}

int driver_stats_get_age(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> driver_stats, id);

    return st -> idade;
}


int user_stats_get_distace(CatRides catR, char* id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_stats, id);

    return st -> distancia;
}

double user_stats_get_avarage_rating(CatRides catR,char *id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_stats, id);
    return((st -> score)/(st -> nr_viagens));
}

double driver_stats_get_avarage_rating(CatRides catR,char *id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> driver_stats, id);
    return((st -> score)/(st -> nr_viagens));
}

double user_stats_get_total(CatRides catR, char *id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> user_stats, id);

    return(st -> total_envolvido);
}

double driver_stats_get_total(CatRides catR, char *id){
    struct user_or_driver_stats *st = g_hash_table_lookup(catR -> driver_stats, id);

    return(st -> total_envolvido);
}

int city_stats_get_distance(CatRides catR, char* city){
    struct city_stats *st = g_hash_table_lookup(catR -> city_stats, city);
    return(st -> distance);
}

int city_stats_get_nr_viagens(CatRides catR, char *city){
   struct city_stats *st = g_hash_table_lookup(catR -> city_stats, city);
   return(st -> nr_viagens);
}

double city_stats_get_total(CatRides catR, char* city){
    struct city_stats *st = g_hash_table_lookup(catR -> city_stats, city);

    return(st -> total);
}


void hash_table_to_array(gpointer key, gpointer value, gpointer array){
    g_array_append_val(array, *(struct user_or_driver_stats*)value);
}

GArray* get_top_drivers(CatRides catR){
    GArray *n_drivers = g_array_new(FALSE, FALSE, sizeof(struct user_or_driver_stats));
    g_hash_table_foreach(catR -> driver_stats, hash_table_to_array , n_drivers );

    
}





