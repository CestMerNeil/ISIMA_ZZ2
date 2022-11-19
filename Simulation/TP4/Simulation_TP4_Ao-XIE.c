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
   * @fn         judgeGender                                         *
   *                                                                     *
   * @brief            *
   * @return 1-> male; 2 -> female                             *
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
        sex = 2;
    }

    return sex;
}


 /** ------------------------------------------------------------------- *
   * @fn         timeSexualMat                                         *
   *                                                                     *
   * @brief      Random integers between 5 and 8 were generated to 
   *             simulate the sexual maturation time of the rabbits.      *
   * @return 1-> male; 2 -> female                             *
   * @todo
   * ------------------------------------------------------------------- */
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
   * @fn         resetArray_Rabbit                                              *
   *                                                                     *
   * @brief      Empty dead rabbits in struct array.                     *  
   *                                                                     *
   * @param      Rabbit {struct Rabbit} The struct array.                        *
   * @param      countRabbit {int} Number of rabbits who are alives      *
   * ------------------------------------------------------------------- */
void resetArray_Rabbit(struct Rabbit *Rabbit, int countRabbit)
{
    int i = 0;
    int j = 0;
    int k = 0;
    do    // Copy those rabbits alive to another structure -> Rabbit_MEM
    {
        if(Rabbit[j].survivalState == 1)
        {
            Rabbit_MEM[i].age = Rabbit[j].age;
            Rabbit_MEM[i].sex = Rabbit[i].sex;
            Rabbit_MEM[i].survivalState = Rabbit[j].survivalState;
            Rabbit_MEM[i].sexualMat = Rabbit[j].sexualMat;
            i++;
        }
        j++;
    }while(i < countRabbit);

    for(; k<countRabbit; k++)    // Back the data to the array original
    {
        Rabbit[k].age = Rabbit_MEM[k].age;
        Rabbit[k].sex = Rabbit_MEM[k].sex;
        Rabbit[k].survivalState = Rabbit_MEM[k].survivalState;
        Rabbit[k].sexualMat = Rabbit_MEM[k].sexualMat;
    }
    for(;k<NB_MAX;k++)    // Zero out subsequent structures
    {
        Rabbit[k].age = 0;
        Rabbit[k].sex = 0;
        Rabbit[k].survivalState = 0;
        Rabbit[k].sexualMat = 0;
    }
    for(int l =0; l<NB_MAX; l++) // reset the array ME_MEM
    {
        Rabbit_MEM[l].age = 0;
        Rabbit_MEM[l].survivalState = 0;
        Rabbit_MEM[l].sexualMat = 0;
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
    int countRabbit = NURabbitABBITSTART; // number of male rabbits
    int countRabbit_MEM = NURabbitABBITSTART;
    int countRabbit = NURabbitABBITSTART; // number of female rabbits
    int countRabbit_MEM = NURabbitABBITSTART;
    int countRabbit_CHILDBITRH = 0; // number of female rabbits suitable for childbirth

    // In the first month, there was NUMBERSTART male rabbits and NUMBERSTART female rabbits by default
    for(int i=0; i<NURabbitABBITSTART; i++)
    {
        Rabbit[i].age = 1;
        Rabbit[i].age = 1;

        Rabbit[i].sexualMat = timeSexualMat();
        Rabbit[i].sexualMat = timeSexualMat();

        Rabbit[i].survivalState = calculChanceSurvival(Rabbit[i].age, Rabbit[i].sexualMat);
        Rabbit[i].survivalState = calculChanceSurvival(Rabbit[i].age, Rabbit[i].sexualMat);
    }

    // Delete the rabbit that died in the first month
    for(int i=0; i<countRabbit; i++)
    {
        if(Rabbit[i].survivalState == 0)
        {
            countRabbit_MEM--;
        }
    }
    for(int i=0; i<countRabbit; i++)
    {
        if(Rabbit[i].survivalState == 0)
        {
            countRabbit_MEM--;
        }
    }

    // Synchronisation number the rabbits
    printf("In this month, %d male rabbits has dead, %d female\n", countRabbit - countRabbit_MEM, countRabbit - countRabbit_MEM);
    countRabbit = countRabbit_MEM;
    countRabbit = countRabbit_MEM;

    // reset the array
    resetArray_Rabbit(Rabbit, countRabbit);
    resetArray_Rabbit(Rabbit, countRabbit);

    printf("In the 1\teme month, we have %d\tmale rabbits and %d\tfemale rabbits\n", countRabbit_MEM, countRabbit_MEM);

    for(int month = 2; month <= DURATION; month++)
    {
        // Update the age
        for(int i=0; i<countRabbit; i++)
        {
            Rabbit[i].age++;
        }
        for(int i=0; i<countRabbit; i++)
        {
            Rabbit[i].age++;
        }

        // Update the chance of death
        for(int i=0; i<countRabbit; i++)
        {
            Rabbit[i].survivalState = calculChanceSurvival(Rabbit[i].age, Rabbit[i].sexualMat);
        }
        for(int i=0; i<countRabbit; i++)
        {
            Rabbit[i].survivalState = calculChanceSurvival(Rabbit[i].age, Rabbit[i].sexualMat);
        }

        // Delete the rabbit died
        for(int i=0; i<countRabbit; i++)
        {
            if(Rabbit[i].survivalState == 0)
            {
                countRabbit_MEM--;
            }
        }
        for(int i=0; i<countRabbit; i++)
        {
            if(Rabbit[i].survivalState == 0)
            {
                countRabbit_MEM--;
            }
        }

        // Synchronisation number the rabbits
        countRabbit = countRabbit_MEM;
        countRabbit = countRabbit_MEM;

        // reset the array
        resetArray_Rabbit(Rabbit, countRabbit);
        resetArray_Rabbit(Rabbit, countRabbit);

        /* Calculate fertility*/
        // For rabbits, the number of males and females isn't taken into account
        // So, it have to use countRabbit and countRabbit_MEM for calcul

        // All in all, calculate the number of rabbits suitable for childbirth
        for(int i=0; i<countRabbit; i++)
        {
            if((Rabbit[i].sexualMat <= Rabbit[i].age) && countRabbit != 0)
            {
                countRabbit_CHILDBITRH+=3;
            }
        }
        //printf("this month, you have %d baby rabbits\n", countRabbit_CHILDBITRH);

        // In this programme, fertility rate is not taken into account
        // Suppose each female of school age gives birth to one rabbit
        for(int i=0; i<countRabbit_CHILDBITRH; i++)
        {
            int sex = judgeGender();
            if(sex == 1)
            {
                Rabbit[countRabbit_MEM].age = 1;
                Rabbit[countRabbit_MEM].sexualMat = timeSexualMat();
                Rabbit[countRabbit_MEM].survivalState = calculChanceSurvival(Rabbit[countRabbit_MEM].age, Rabbit[countRabbit_MEM].sexualMat);
                countRabbit_MEM++;
            }
            if(sex == 0)
            {
                Rabbit[countRabbit_MEM].age = 1;
                Rabbit[countRabbit_MEM].sexualMat = timeSexualMat();
                Rabbit[countRabbit_MEM].survivalState = calculChanceSurvival(Rabbit[countRabbit_MEM].age, Rabbit[countRabbit_MEM].sexualMat);
                countRabbit_MEM++;
            }
        }

        // reset number of baby in the next month
        countRabbit_CHILDBITRH = 0;

        // Synchronisation number the rabbits
        countRabbit = countRabbit_MEM;

        
        // Delete the rabbit that died in this month
        for(int i=0; i<countRabbit; i++)
        {
            if(Rabbit[i].survivalState == 0)
            {
                countRabbit_MEM--;
            }
        }
        for(int i=0; i<countRabbit; i++)
        {
            if(Rabbit[i].survivalState == 0)
            {
                countRabbit_MEM--;
            }
        }
        //printf("In this month, %d male rabbits has dead, %d female\n", countRabbit - countRabbit_MEM, countRabbit - countRabbit_MEM);
        // Synchronisation number the rabbits
        countRabbit = countRabbit_MEM;


        // reset the array
        resetArray_Rabbit(Rabbit, countRabbit);

        //printf("In the %d\teme month, we have %d\tmale rabbits and %d\tfemale rabbits\n", month, countRabbit_MEM, countRabbit_MEM);
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