#include "cat_users.h"
#include "cat_drivers.h"
#include "cat_rides.h"

typedef struct stats *Stats;
typedef struct results *Results; 

Stats stats_new(CatUsers catU, CatDrivers catD, CatRides catR);

Results stats_result_new();

void stats_results_add_row(Results res);

void stats_results_add_cell(Results res, char* cell);

char* stats_results_get_cell(Results res, int rowIdx, int colIdx);


Results Q1_get_user_or_driver(Stats s, char* id);


