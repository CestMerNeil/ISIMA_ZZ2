
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>

#define NB_MAX 50000000
#define DURATION 80
#define NUMRABBITSTART 1000000
#define SizeRabbit 100

#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
long genrand_int31(void);
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);
double BoxMuller(double mean, double stdc);

int judgeGender(void);
int timeSexualMat(void);
int calculChanceSurvival(int ageRabbit, int sexualMat);
void resetArray(struct MR *MR, int countRabbit);


struct MR // Male Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    int age; // month
    int sexualMat; // time of sexMat
    int survivalState; // Chance of death
}MR[NB_MAX]={0};

struct FR // Female Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    int age; // month
    int sexualMat; // time of sexMat
    int survivalState;
}FR[NB_MAX]={0};

struct MR_MEM // Male Rabbit
{
    // Each time, we create a rabbit
    // Then, we have to init all the random number for this rabbit.
    int age; // month
    int sexualMat; // time of sexMat
    int survivalState; // Chance of death
}MR_MEM[NB_MAX]={0};