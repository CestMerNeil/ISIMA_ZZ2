#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include "Random.c"

#define NB_MAX 9999999999
#define DURATION 20
#define NUMRABBITSTART 10

struct Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    int age; // month
    int sexualMat; // time of sexMat
    int survive; // Surviving state
    double dieRate; // Chance of death
    int timePrYear;
}MR[NB_MAX];

struct Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    int age; // month
    int sexualMat; // time of sexMat
    int survive; // Surviving state
    double dieRate;
    int timePrYear;
}FR[NB_MAX];