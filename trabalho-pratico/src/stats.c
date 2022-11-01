#include "stats.h"
#include <string.h>
#include "glib-2.0/glib.h"


typedef struct row{
    GArray *cells; // char*
};

typedef struct results{
    GArray *row; // struct row
};

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



