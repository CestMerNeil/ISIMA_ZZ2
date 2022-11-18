#include "Simulation_TP4_Ao-XIE.h"

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
        printf("In the %d\teme month, we have %d\t little pair, %d\t adult pair \n", i+1, RabbitTable[i][0], RabbitTable[i][1]);
    }
}


 /** ------------------------------------------------------------------- *
   * @fn         RabbitSwarmAlgo                                         *
   *                                                                     *
   * @brief            *
   * @return 1-> male; 0 -> female                             *
   * @todo
   * ------------------------------------------------------------------- */
int judgeGender(void)
{
    int sex;
    double random;

    random = genrand_real2();
    if(random < 0.5)
    {
        sex = 1;
        }
    else
    {
        sex = 0;
    }

    return sex;
}

int timeSexualMat(void)
{
    return 3 * genrand_real2() + 5;
}

 /** ------------------------------------------------------------------- *
   * @fn         calculChanceSurvival                                         *
   *                                                                     *
   * @brief            *
   * @return 1-> survive; 0 -> die                             *
   * @todo
   * ------------------------------------------------------------------- */
int calculChanceSurvival(int ageRabbit, int sexualMat)
{
    double chanceSurvival;
    double Outdo = 0;
    int surviveState = 0;


    chanceSurvival = genrand_real2();
    if(sexualMat > ageRabbit) // For underage rabbits
    {
        if(chanceSurvival<0.6) surviveState = 1;
    }
    else
    {   
        if(ageRabbit < 120) // For rabbits who are adults but not 10 years old
        {
            if(chanceSurvival < 0.6) surviveState = 1;
        }
        else
        {
            Outdo = ageRabbit - 120;
            if(chanceSurvival < 0.5 - ((0.1 / 12) * Outdo)) surviveState = 1;
        }
    }

    return surviveState;
}

 /** ------------------------------------------------------------------- *
   * @fn         resetArray_MR                                              *
   *                                                                     *
   * @brief      Empty dead rabbits in struct array.                     *  
   *                                                                     *
   * @param      MR {struct MR} The struct array.                        *
   * @param      countRabbit {int} Number of rabbits who are alives      *
   * ------------------------------------------------------------------- */
void resetArray_MR(struct MR *MR, int countRabbit)
{
    int i = 0;
    int j = 0;
    int k = 0;
    do    // Copy those rabbits alive to another structure -> MR_MEM
    {
        if(MR[j].survivalState == 1)
        {
            MR_MEM[i].age = MR[j].age;
            MR_MEM[i].survivalState = MR[j].survivalState;
            MR_MEM[i].sexualMat = MR[j].sexualMat;
            i++;
        }
        j++;
    }while(i < countRabbit);

    for(; k<countRabbit; k++)    // Back the data to the array original
    {
        MR[k].age = MR_MEM[k].age;
        MR[k].survivalState = MR_MEM[k].survivalState;
        MR[k].sexualMat = MR_MEM[k].sexualMat;
    }
    for(;k<NB_MAX;k++)    // Zero out subsequent structures
    {
        MR[k].age = 0;
        MR[k].survivalState = 0;
        MR[k].sexualMat = 0;
    }
    for(int l =0; l<NB_MAX; l++) // reset the array ME_MEM
    {
        MR_MEM[l].age = 0;
        MR_MEM[l].survivalState = 0;
        MR_MEM[l].sexualMat = 0;
    }
}

 /** ------------------------------------------------------------------- *
   * @fn         resetArray_FR                                           *
   *                                                                     *
   * @brief      Empty dead rabbits in struct array.                     *  
   *                                                                     *
   * @param      FR {struct FR} The struct array.                        *
   * @param      countRabbit {int} Number of rabbits who are alives      *
   * ------------------------------------------------------------------- */
void resetArray_FR(struct FR *FR, int countRabbit)
{
    int i = 0;
    int j = 0;
    int k = 0;
    do    // Copy those rabbits alive to another structure -> MR_MEM
    {
        if(FR[j].survivalState == 1)
        {
            MR_MEM[i].age = MR[j].age;
            MR_MEM[i].survivalState = MR[j].survivalState;
            MR_MEM[i].sexualMat = MR[j].sexualMat;
            i++;
        }
        j++;
    }while(i < countRabbit);

    for(; k<countRabbit; k++)    // Back the data to the array original
    {
        FR[k].age = MR_MEM[k].age;
        FR[k].survivalState = MR_MEM[k].survivalState;
        FR[k].sexualMat = MR_MEM[k].sexualMat;
    }
    for(;k<NB_MAX;k++)    // Zero out subsequent structures
    {
        FR[k].age = 0;
        FR[k].survivalState = 0;
        FR[k].sexualMat = 0;
    }
    for(int l =0; l<NB_MAX; l++) // reset the array ME_MEM
    {
        MR_MEM[l].age = 0;
        MR_MEM[l].survivalState = 0;
        MR_MEM[l].sexualMat = 0;
    }
}

 /** ------------------------------------------------------------------- *
   * @todo       Prepare the generator of random numbers, It's MT in the *
   *             second lab.                                             *
   * ------------------------------------------------------------------- */
/* Period parameters */  

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
        /* for >32 bit machines */
    }
}

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

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void)
{
    return (long)(genrand_int32()>>1);
}

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void)
{
    return genrand_int32()*(1.0/4294967295.0); 
    /* divided by 2^32-1 */ 
}

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void)
{
    return genrand_int32()*(1.0/4294967296.0); 
    /* divided by 2^32 */
}

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void)
{
    return (((double)genrand_int32()) + 0.5)*(1.0/4294967296.0); 
    /* divided by 2^32 */
}

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void) 
{ 
    unsigned long a=genrand_int32()>>5, b=genrand_int32()>>6; 
    return(a*67108864.0+b)*(1.0/9007199254740992.0); 
} 
/* These real versions are due to Isaku Wada, 2002/01/09 added */

 /** ----------------------------------------------------------------------------------------------------------------------------------- *
   * @fn        BoxMuller                                                                                                                *
   * @brief     A high quality random number generator                                                                                   *
   * @param     mean    Generate the middle of the range                                                                                 *
   * @param     stdc    Generate range                                                                                                   *                                    
   * @return    A random number                                                                                                          *
   * @todo      It's for the question FIVE PART TWO                                                                                      *
   * ----------------------------------------------------------------------------------------------------------------------------------- */
double BoxMuller(void)
{
    static double u;
    static double v;
    static int phase = 0;
    double z;
    if(phase == 0)
    {
        u = genrand_real2() / (RAND_MAX + 1.0);
        v = genrand_real2() / (RAND_MAX + 1.0);
        z = sqrt(-2.0 * log(u)) * cos(2.0 * PI * v);
    }
    else
    {
        z = sqrt(-2.0 * log(u)) * cos(2.0 * PI * v);
    }
    phase = 1 - phase;
    return z;
}

int getNbBaby(void)
{
    return 3 + (genrand_real2() * 3);
}

 /** ------------------------------------------------------------------- *
   * @fn         RealRabbit                                         *
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
    int countFR_CHILDBITRH = 0; // number of female rabbits suitable for childbirth

    // In the first month, there was NUMBERSTART male rabbits and NUMBERSTART female rabbits by default
    for(int i=0; i<NUMRABBITSTART; i++)
    {
        MR[i].age = 1;
        FR[i].age = 1;

        MR[i].sexualMat = timeSexualMat();
        FR[i].sexualMat = timeSexualMat();

        MR[i].survivalState = calculChanceSurvival(MR[i].age, MR[i].sexualMat);
        FR[i].survivalState = calculChanceSurvival(FR[i].age, FR[i].sexualMat);
    }

    // Delete the rabbit that died in the first month
    for(int i=0; i<countMR; i++)
    {
        if(MR[i].survivalState == 0)
        {
            countMR_MEM--;
        }
    }
    for(int i=0; i<countFR; i++)
    {
        if(FR[i].survivalState == 0)
        {
            countFR_MEM--;
        }
    }

    // Synchronisation number the rabbits
    printf("In this month, %d male rabbits has dead, %d female\n", countMR - countMR_MEM, countFR - countFR_MEM);
    countMR = countMR_MEM;
    countFR = countFR_MEM;

    // reset the array
    resetArray_MR(MR, countMR);
    resetArray_FR(FR, countFR);

    printf("In the 1\teme month, we have %d\tmale rabbits and %d\tfemale rabbits\n", countMR_MEM, countFR_MEM);

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

        // Update the chance of death
        for(int i=0; i<countMR; i++)
        {
            MR[i].survivalState = calculChanceSurvival(MR[i].age, MR[i].sexualMat);
        }
        for(int i=0; i<countFR; i++)
        {
            FR[i].survivalState = calculChanceSurvival(FR[i].age, FR[i].sexualMat);
        }

        // Delete the rabbit died
        for(int i=0; i<countMR; i++)
        {
            if(MR[i].survivalState == 0)
            {
                countMR_MEM--;
            }
        }
        for(int i=0; i<countFR; i++)
        {
            if(FR[i].survivalState == 0)
            {
                countFR_MEM--;
            }
        }

        // Synchronisation number the rabbits
        countMR = countMR_MEM;
        countFR = countFR_MEM;

        // reset the array
        resetArray_MR(MR, countMR);
        resetArray_FR(FR, countFR);

        /* Calculate fertility*/
        // For rabbits, the number of males and females isn't taken into account
        // So, it have to use countFR and countFR_MEM for calcul

        // All in all, calculate the number of rabbits suitable for childbirth
        for(int i=0; i<countFR; i++)
        {
            if((FR[i].sexualMat <= FR[i].age) && countMR != 0)
            {
                countFR_CHILDBITRH+=3;
            }
        }
        printf("this month, you have %d baby rabbits\n", countFR_CHILDBITRH);

        // In this programme, fertility rate is not taken into account
        // Suppose each female of school age gives birth to one rabbit
        for(int i=0; i<countFR_CHILDBITRH; i++)
        {
            int sex = judgeGender();
            if(sex == 1)
            {
                MR[countMR_MEM].age = 1;
                MR[countMR_MEM].sexualMat = timeSexualMat();
                MR[countMR_MEM].survivalState = calculChanceSurvival(FR[countMR_MEM].age, FR[countMR_MEM].sexualMat);
                countMR_MEM++;
            }
            if(sex == 0)
            {
                FR[countFR_MEM].age = 1;
                FR[countFR_MEM].sexualMat = timeSexualMat();
                FR[countFR_MEM].survivalState = calculChanceSurvival(FR[countFR_MEM].age, FR[countFR_MEM].sexualMat);
                countFR_MEM++;
            }
        }

        // reset number of baby in the next month
        countFR_CHILDBITRH = 0;

        // Synchronisation number the rabbits
        countMR = countMR_MEM;
        countFR = countFR_MEM;
        
        
        // Delete the rabbit that died in this month
        for(int i=0; i<countMR; i++)
        {
            if(MR[i].survivalState == 0)
            {
                countMR_MEM--;
            }
        }
        for(int i=0; i<countFR; i++)
        {
            if(FR[i].survivalState == 0)
            {
                countFR_MEM--;
            }
        }
        printf("In this month, %d male rabbits has dead, %d female\n", countMR - countMR_MEM, countFR - countFR_MEM);
        // Synchronisation number the rabbits
        countMR = countMR_MEM;
        countFR = countFR_MEM;

        // reset the array
        resetArray_MR(MR, countMR);
        resetArray_FR(FR, countFR);

        printf("In the %d\teme month, we have %d\tmale rabbits and %d\tfemale rabbits\n", month, countMR_MEM, countFR_MEM);
    }

}

int main()
{
    /* Inisiation for the ramdon generator */
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    RealRabbit();
    //RabbitSwarmAlgo();

    return EXIT_SUCCESS;
}