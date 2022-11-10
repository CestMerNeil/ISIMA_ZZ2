#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>

double BoxMuller(double mean, double stdc);
void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
long genrand_int31(void);
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);
int judgeGender(void);
int timeSexualMat(void);
double calculChanceSurvival(int ageRabbit, int sexualMat);

#define NB_MAX 1000000
#define DURATION 100
#define NUMRABBITSTART 10

struct MR // Male Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    int age; // month
    int sexualMat; // time of sexMat
    int survive; // Surviving state
    double dieRate; // Chance of death
}MR[NB_MAX]={0};

struct FR // Female Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    int age; // month
    int sexualMat; // time of sexMat
    int survive; // Surviving state
    double dieRate;
}FR[NB_MAX]={0};