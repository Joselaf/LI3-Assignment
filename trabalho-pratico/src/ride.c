#include "ride.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ride{
    char id[16];
    Date date;
    char driver[16];
    char user[32];
    char city[16];
    int distance;
    int score_user;
    int score_driver;
    double tip;
    char comment[128];

};

Ride parsing_ride(char *rideStr){
    Ride rd = malloc(sizeof(struct ride));
    char *chunck;
    char *rest = NULL;

    chunck = strtok_r(rideStr, ";", &rest);
    strcpy(rd -> id, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd -> date = parsing_date(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(rd -> driver, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(rd -> user, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    strcpy(rd -> city, chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd -> distance = atoi(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd -> score_user = atoi(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd -> score_driver = atoi(chunck);

    chunck = strtok_r(NULL, ";", &rest);
    rd -> tip = atof(chunck);

    chunck = strtok_r(NULL, "\n", &rest);
    if(chunck) {
        strcpy(rd -> comment, chunck);
    } else {
        rd -> comment[0] = '\0';
    }


    return rd;

}

void print_ride(Ride rd){

    printf("id = %s, date = %d/%d/%d, driver = %s, city = %s,  distance = %d, score_user = %d, score_driver = %d, tip = %f, comment = %s \n",
        rd -> id,
        rd -> date.day,
        rd ->date.month,
        rd ->date.year,
        rd -> driver,
        rd -> city,
        rd ->distance,
        rd -> score_user,
        rd -> score_driver,
        rd -> tip,
        rd -> comment);
}

void free_ride(Ride rd){
    free(rd);
}

Ride clone_ride(Ride original){
    Ride copy = malloc(sizeof(struct ride));

    memcpy(copy, original, sizeof(struct ride));

    return copy;
}

