#include "Simulation_TP4_Ao-XIE.h"

#define SizeRabbit 40

 /** ------------------------------------------------------------------- *
   * @fn         RabbitSwarmAlgo                                         *
   *                                                                     *
   * @brief      Calcul value of Pi with the Monte Carlo Simulation      *
   * @todo       It's for the question ONE                               *
   * ------------------------------------------------------------------- */
void RabbitSwarmAlgo()
{
    int RabbitTable[SizeRabbit][2] = {0};
    RabbitTable[0][0] = 1;
    // RabbitTable[SizeRabbit][0] -> little
    // RabbitTable[SizeRabbit][1] -> adult
    for(int i=0; i<SizeRabbit-1; i++)
    {
        RabbitTable[i+1][0] = RabbitTable[i][1];    //little
        RabbitTable[i+1][1] = RabbitTable[i][0] + RabbitTable[i][1];    //adult
    }

    for(int i = 0; i < SizeRabbit; i++)
    {
        printf("In the %deme month, we have %d little, %d adult \n", i+1, RabbitTable[i][0], RabbitTable[i][1]);
    }
}

 /** ------------------------------------------------------------------- *
   * @fn         RabbitSwarmAlgo                                         *
   *                                                                     *
   * @brief            *
   * @todo       It's for the question TWO                               *
   * ------------------------------------------------------------------- */
void RealRabbit()
{
    int countMR = NUMRABBITSTART; // number of male rabbits
    int countMR_MEM = NUMRABBITSTART;
    int countFR = NUMRABBITSTART; // number of female rabbits
    int countFR_MEM = NUMRABBITSTART;

    // In the first month, there was 5 male rabbits and 5 female rabbits by default
    for(int i=0; i<NUMRABBITSTART; i++)
    {
        MR[i].age = 1;
        FR[i].age = 1;

        MR[i].sexualMat = timeSexualMat();
        FR[i].sexualMat = timeSexualMat();

        MR[i].survive = 1;
        FR[i].survive = 1;

        MR[i].dieRate = calculChanceSurvival(MR[i].age, MR[i].sexualMat);
        FR[i].dieRate = calculChanceSurvival(FR[i].age, FR[i].sexualMat);
    }

    // Delete the rabbit that died in the first month
    for(int i=0; i<countMR; i++)
    {
        if(MR[i].dieRate < 0.5)
        {
            countMR_MEM--;
            MR[i].survive = 0;
        }
    }
    for(int i=0; i<countFR; i++)
    {
        if(FR[i].dieRate < 0.5)
        {
            countFR_MEM--;
            FR[i].survive = 0;
        }
    }

    // Synchronisation number the rabbits
    countMR = countMR_MEM;
    countFR = countFR_MEM;

    for(int month = 2; month <= DURATION; month++)
    {
        // Update the age
        for(int i=0; i<countMR; i++)
        {
            MR[i].age++;
        }
        for(int i=0; i<countFR; i++)
        {
            FR[i].age++;
        }

        // Update the chance of daath
        for(int i=0; i<countMR; i++)
        {
            MR[i].dieRate = calculChanceSurvival(MR[i].age, MR[i].sexualMat);
        }
        for(int i=0; i<countFR; i++)
        {
            FR[i].dieRate = calculChanceSurvival(FR[i].age, FR[i].sexualMat);
        }

        // Delete the rabbit died
        for(int i=0; i<countMR; i++)
        {
            if(MR[i].dieRate < 0.5)
            {
                countMR_MEM--;
                MR[i].survive = 0;
            }
        }
        for(int i=0; i<countFR; i++)
        {
            if(FR[i].dieRate < 0.5)
            {
                countFR_MEM--;
                FR[i].survive = 0;
            }
        }

        // Synchronisation number the rabbits
        countMR = countMR_MEM;
        countFR = countFR_MEM;

        /* Calculate fertility*/
        // For rabbits, the number of males and females isn't taken into account


    }

}
 /** ------------------------------------------------------------------- *
   * @fn         RabbitSwarmAlgo                                         *
   *                                                                     *
   * @brief            *
   * @return 1-> male; 0 -> female                             *
   * @todo
   * ------------------------------------------------------------------- */
int judgeGender()
{
    int sex;
    double random;

    random = genrand_int32();
    if(random < 0.5){sex = 1;}
    else{sex = 0;}

    return sex;
}

int timeSexualMat()
{
    return 3 * genrand_int32() + 5;
}

double calculChanceSurvival(int ageRabbit, int sexualMat)
{
    double chanceSurvival;

    if(sexualMat < ageRabbit)
    {
        chanceSurvival = 0.35 * genrand_int32();
    }
    else
    {   
        if(ageRabbit < 120)
        {
            chanceSurvival = 0.6 * genrand_int32();
        }
        else
        {
            chanceSurvival = 50 - (ageRabbit - 120) * (50.0 / 60.0);
            chanceSurvival = chanceSurvival / 100.0 * genrand_int32();
        }
    }

    return chanceSurvival;
}



int main()
{
    /* Inisiation for the ramdon generator */
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    /* Inisiation for those values */

    return EXIT_SUCCESS;
}


 /** ------------------------------------------------------------------- *
   * @todo       Prepare the generator of random numbers, It's MT in the *
   *             second lab.                                             *
   * ------------------------------------------------------------------- */
/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */

/* initializes mt[N] with a seed */
void init_genrand(unsigned long s)
{
    mt[0]= s & 0xffffffffUL;
    for (mti=1; mti<N; mti++) {
        mt[mti] = 
	    (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;

/* initialize by an array with array-length */
/* init_key is the array for initializing keys */
/* key_length is its length */
/* slight change for C++, 2004/2/26 */
void init_by_array(unsigned long init_key[], int key_length)
{
    int i, j, k;
    init_genrand(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
    }

    mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */ 
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void)
{
    unsigned long y;
    static unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if init_genrand() has not been called, */
            init_genrand(5489UL); /* a default initial seed is used */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }
  
    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void)
{
    return genrand_int32()*(1.0/4294967296.0); 
    /* divided by 2^32 */
}

 /** ----------------------------------------------------------------------------------------------------------------------------------- *
   * @fn        BoxMuller                                                                                                                *
   * @brief     A high quality random number generator                                                                                   *
   * @param     mean    Generate the middle of the range                                                                                 *
   * @param     stdc    Generate range                                                                                                   *                                    
   * @return    A random number                                                                                                          *
   * @todo      It's for the question FIVE PART TWO                                                                                      *
   * ----------------------------------------------------------------------------------------------------------------------------------- */
double BoxMuller(double mean, double stdc)
{
    double v1 = 0;
    double v2 = 0;
    double s = 0;
    int phase = 0;
    double x;
    if(phase == 0)
    {
        do
        {
            double u1 = genrand_real2() / RAND_MAX;
            double u2 = genrand_real2() / RAND_MAX;

            v1 = 2 * u1 - 1;
            v2 = 2 * u2 - 1;
            s = v1 * v1 + v2 * v2;
        }while(s >= 1 || s ==0);

        x = v1 * sqrt(-2 * log(s) / s);
    }
    else
    {
        x = v2 * sqrt(-2 * log(s) / s);
    }

    phase = 1 - phase;

    return mean + x * stdc;
}
