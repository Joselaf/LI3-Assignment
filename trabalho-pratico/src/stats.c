#include "stats.h"
#include <string.h>
#include "glib-2.0/glib.h"



 struct stats{
    CatUsers cat_users;
    CatDrivers cat_drivers;
    CatRides cat_rides;
};

typedef struct row{
    GArray *cells; // char*
};

typedef struct results{
    GArray *row; // struct row
};

Stats stats_new(CatUsers catU, CatDrivers catD, CatRides catR){
    Stats s = malloc(sizeof(struct stats));
    s->cat_users = catU;
    s->cat_drivers = catD;
    s->cat_rides = catR; 


    return s;
}


Results stats_result_new(){
    Results res = malloc(sizeof(struct results));
    res->row = g_array_new(FALSE, FALSE, sizeof(struct row));
    return res;
}

void stats_results_add_row(Results res){
    struct row new_row;
    new_row.cells = g_array_new(FALSE, FALSE, sizeof(char*));
    g_array_append_val(res -> row, new_row);
}

void stats_results_add_cell(Results res, char* cell){
    struct row last = g_array_index(res -> row, struct row, res -> row -> len - 1);
    g_array_append_val(last.cells, cell);
}

char* stats_results_get_cell(Results res, int rowIdx, int colIdx){
    struct row r = g_array_index(res -> row, struct row, rowIdx);
    char * cell = g_array_index(r.cells, char*, colIdx );
    return strdup(cell);
}

Results Q1_get_user_or_driver(Stats s, char* id){
    Results resp = stats_result_new();

    if((user_get(s->cat_users, id)) != NULL){
        stats_results_add_row(resp);
        User u = user_get(s->cat_users, id);
        stats_results_add_cell(resp,user_get_username(u));
        stats_results_add_cell(resp, user_get_gender(u));
    }else{
        stats_results_add_row(resp);
        Driver dr = driver_get(s->cat_drivers, id);
        stats_results_add_cell(resp,driver_get_id(dr));
        stats_results_add_cell(resp,driver_get_gender(dr));
    }
    return resp;

}



