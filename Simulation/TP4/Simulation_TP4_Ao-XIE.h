#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>

struct Rabbit
{
    int sexe; // 0->Female; 1->Male
    int age; // month
    int sexualMat; // time of sexMat
    double surRate;
    double dieRate;
}Rabbit;