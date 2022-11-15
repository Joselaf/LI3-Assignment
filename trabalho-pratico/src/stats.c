#include <stdio.h>
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

void stats_results_add_cell_double(Results res, double value){
 char str[64];
 sprintf(str, "%.3f", value);
 stats_results_add_cell(res, strdup(str));
}

void stats_resuts_add_cell_int(Results res, int value){
    char str[12];
    sprintf(str, "%d", value);
    stats_results_add_cell(res, strdup(str));
}

char* stats_results_get_cell(Results res, int rowIdx, int colIdx){
    struct row r = g_array_index(res -> row, struct row, rowIdx);
    char *cell = g_array_index(r.cells, char*, colIdx );
    return strdup(cell);
}

Results Q1_get_user_or_driver(Stats s, char* id){
    Results resp = stats_result_new();
    if(cat_users_get_user(s -> cat_users, id) == NULL && cat_drivers_get_driver(s -> cat_drivers, id) == NULL){
       return resp;

    }else if((cat_users_get_user(s->cat_users, id)) != NULL){
        stats_results_add_row(resp);
        User u = cat_users_get_user(s->cat_users, id);
        stats_results_add_cell(resp,user_get_username(u));
        stats_results_add_cell(resp, user_get_gender(u));
        stats_resuts_add_cell_int(resp, user_stats_get_age(s -> cat_rides, id));
        stats_results_add_cell_double(resp, user_stats_get_avarage_rating(s -> cat_rides, id));
        stats_resuts_add_cell_int(resp, user_stats_get_nr_viagens(s -> cat_rides, id));
        stats_results_add_cell_double(resp, user_stats_get_total(s -> cat_rides, id));
    }else{
        stats_results_add_row(resp);
        Driver dr = cat_drivers_get_driver(s->cat_drivers, id);
        stats_results_add_cell(resp,driver_get_id(dr));
        stats_results_add_cell(resp,driver_get_gender(dr));
        stats_resuts_add_cell_int(resp, driver_stats_get_age(s -> cat_rides, id));
        stats_results_add_cell_double(resp,driver_stats_get_avarage_rating(s -> cat_rides, id));
        stats_resuts_add_cell_int(resp, driver_stats_get_nr_viagens(s -> cat_rides, id));
        stats_results_add_cell_double(resp,driver_stats_get_total(s -> cat_rides, id));

    }
    return resp;

}

Results Q2_get_N_drivers( Stats s, int n_drivers){
   GArray *drivers_ids = get_top_drivers(s -> cat_rides);

    Results res = stats_result_new();


        for(int i = 0; i < n_drivers; i++){
            stats_results_add_row(res);
            char * drv_id = g_array_index(drivers_ids, char*, i);
            Driver drv = cat_drivers_get_driver(s -> cat_drivers, g_array_index(drivers_ids, char*, i));
            stats_results_add_cell(res, driver_get_id(drv));
            stats_results_add_cell(res, driver_get_name(drv));
            stats_results_add_cell_double(res, cat_rides_get_driver_avarage_score(s -> cat_rides, drv_id));
        }

    return res;
    
}

Results Q4_get_avarage_price_city( Stats s, char* city){
    Results res = stats_result_new();
    stats_results_add_row(res);

    double result = city_stats_get_total(s -> cat_rides, city)/ city_stats_get_nr_viagens(s -> cat_rides, city);

    stats_results_add_cell_double(res, result); 

    return res;

}

void queries_file(Stats s, char *file_path){
    Results res = stats_result_new();
    
    FILE* fp = fopen(file_path, "r");

    char query[256];

    while(fgets(query,256,fp)){
        //limpesa query
        if(query[strlen(query)-1]== '\n'){
            query[strlen(query)-1]= '\0';
        }
        switch(query[0]){
            case '1':
            res = Q1_get_user_or_driver(s, &query[2]);
            print_table(res, stdout);
            break;
            case '4':
            res = Q4_get_avarage_price_city(s, &query[2]);
            print_table(res, stdout);
            break;
            case '2':
            res = Q2_get_N_drivers(s, atoi(&query[2]));
            print_table(res, stdout);
            break;
        }
    }

    return;

}

void print_table(Results res, FILE *file){
    int n_rows = res ->row ->len;

    for(int i = 0; i < n_rows; i++){
        print_row(res, file, i);
    }

}

void print_row(Results res, FILE *file, int row){
    struct row r = g_array_index(res -> row, struct row, row);

    for(int i = 0; i < r.cells -> len ; i++){
        if(i == r.cells -> len - 1){
            fprintf(file, "%s", g_array_index(r.cells, char*, i));
        }else{
            fprintf(file, "%s;", g_array_index(r.cells, char*, i));
        }
    }
    fprintf(file, "\n");
}





