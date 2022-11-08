#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>

struct Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    // 
    int sexe; // 0->Female; 1->Male
    int age; // month
    int sexualMat; // time of sexMat
    double surRate;
    double dieRate;
    int timePrYear;
}Rabbit;
