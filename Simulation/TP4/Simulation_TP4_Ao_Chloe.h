#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <string.h>

#define DURATION 30
#define NUMRABBITSTART 2
#define PI 3.141592653589793

#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

//void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
long genrand_int31(void);
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);
double BoxMuller(void);

typedef struct Rabbit
{
    long long int males[16]; // Arrays in which to store the numbers of rabbits, each cell representing the age of the rabbits
                             // [0] -> baby rabbits, [1] -> 1-year-old rabbits, ...
    long long int females[16];
}Rabbit;