 /** ------------------------------------------------------------------- *
   * @todo       Rabbit colony simulation algorithm                      *
   * @authors    Ao XIE; Cholé BERTHOLD                                  *
   * @version    2.5.2                                                   *
   *                                                                     *
   * Updates:                                                            *
   *     1. Updated the structure model to use only one structure.       *
   *     2. Updated iterative algorithm to include a Gaussian            *
   *        distributed reproduction function.                           *
   *     3. Update the survival rate algorithm:                          *
   *         (1) The monthly survival rate of young rabbits is updated   *
   *             to 0.92, i.e. an annual survival rate of 0.35.          *
   *         (2) The monthly survival rate for adult rabbits is updated  *
   *             to 0.95, i.e. an annual survival rate of 0.6.           *
   * ------------------------------------------------------------------- */

#include "Simulation_TP4_Ao-XIE.h"

 /** ------------------------------------------------------------------- *
   * @fn         RabbitSwarmAlgo                                         *
   *                                                                     *
   * @brief      Calcul value of Pi with the Monte Carlo Simulation      *
   * ------------------------------------------------------------------- */
void RabbitSwarmAlgo(void)
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
        printf("Month:%d\t", i+1);
        printf("Numbers of little pairs: %d\t", RabbitTable[i][0]);
        printf("NUmbers of adults pairs: %d\n", RabbitTable[i][1]);
    }
}


 /** ------------------------------------------------------------------- *
   * @fn         judgeGender                                             *
   *                                                                     *
   * @brief      Generate gender with equal probability                  *
   *                                                                     *
   * @return     Sex [1-> male; 2 -> female]                             *
   * ------------------------------------------------------------------- */
int judgeGender(void)
{
    int sex;
    double random;

    random = genrand_real2();
    if(random < 0.5) sex = 1;
    else sex = 2;

    return sex;
}

 /** ------------------------------------------------------------------- *
   * @fn         timeSexualMat                                           *
   *                                                                     *
   * @brief      Random integers between 5 and 8 were generated to       *
   *             simulate the sexual maturation time of the rabbits.     *
   *                                                                     *
   * @return     Time of sexual maturity                                 *
   * ------------------------------------------------------------------- */
int timeSexualMat(void)
{
    return 3 * genrand_real2() + 5;
}

 /** ------------------------------------------------------------------- *
   * @fn         calculChanceSurvival                                    *
   *                                                                     *
   * @brief      Survival rate based on age and time to sexual maturity  *
   *                                                                     *
   * @param      ageRabbit {int} The age of the rabbit                   *
   * @param      sexualMat {int} Sexual maturity of rabbits              *
   *                                                                     *
   * @return     Survival rate of rabbits [1-> survive; 0 -> die]        *
   * ------------------------------------------------------------------- */
int calculChanceSurvival(int ageRabbit, int sexualMat)
{
    double chanceSurvival;
    double Outdo = 0;
    int surviveState = 0;


    chanceSurvival = genrand_real2();
    if(sexualMat > ageRabbit) // For underage rabbits
    {
        if(chanceSurvival<=0.92) surviveState = 1;
    }
    else
    {   
        if(ageRabbit < 120) // For rabbits who are adults but not 10 years old
        {
            if(chanceSurvival <= 0.95) surviveState = 1;
        }
        else
        {
            Outdo = ageRabbit - 120;
            if(chanceSurvival <= (0.6 - (Outdo * 0.01))) surviveState = 1;
        }
    }

    return surviveState;
}

 /** ------------------------------------------------------------------- *
   * @fn         resetArray_Rabbit                                       *
   *                                                                     *
   * @brief      Empty dead rabbits in struct array.                     *
   *                                                                     *
   * @param      Rabbit {struct Rabbit} The struct array.                *
   * @param      Rabbit_MEM {struct Rabbit} Secondary Structures         *
   * @param      countRabbit {int} Number of rabbits who are alives      *
   * ------------------------------------------------------------------- */
void resetArray_Rabbit(struct Rabbit *Rabbit, struct Rabbit *Rabbit_MEM, int countRabbit)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < countRabbit)    // Copy those rabbits alive to another structure -> Rabbit_MEM
    {
        if((Rabbit+j)->survivalState == 1)
        {
            (Rabbit_MEM+i)->age = (Rabbit+j)->age;
            (Rabbit_MEM+i)->sex = (Rabbit+j)->sex;
            (Rabbit_MEM+i)->survivalState = (Rabbit+j)->survivalState;
            (Rabbit_MEM+i)->sexualMat = (Rabbit+j)->sexualMat;
            (Rabbit_MEM+i)->timesChildYear = (Rabbit+j)->timesChildYear;
            i++;
        }
        j++;
    }

    for(; k<countRabbit; k++)    // Back the data to the array original
    {
        (Rabbit+k)->age = (Rabbit_MEM+k)->age;
        (Rabbit+k)->sex = (Rabbit_MEM+k)->sex;
        (Rabbit+k)->survivalState = (Rabbit_MEM+k)->survivalState;
        (Rabbit+k)->sexualMat = (Rabbit_MEM+k)->sexualMat;
        (Rabbit+k)->timesChildYear = (Rabbit_MEM+k)->timesChildYear;
    }
    for(;k<NB_MAX;k++)    // Zero out subsequent structures
    {
        (Rabbit+k)->age = 0;
        (Rabbit+k)->sex = 0;
        (Rabbit+k)->survivalState = 0;
        (Rabbit+k)->sexualMat = 0;
        (Rabbit+k)->timesChildYear =0;
    }
}



 /** ------------------------------------------------------------------- *
   * @fn        BoxMuller                                                *
   *                                                                     *
   * @brief     Used to generate a standard Gaussian distribution of     *
   *            random numbers.                                          *
   *                                                                     *
   * @return    A random value in a standard Gaussian distribution       *
   * ------------------------------------------------------------------- */
double BoxMuller(void)
{
    static double u;
    static double v;
    static int phase = 0;
    double z;
    if(phase == 0)
    {
        u = genrand_real2();
        v = genrand_real2();
        z = sqrt(-2.0 * log(u)) * sin(2.0 * PI * v);
    }
    else
    {
        z = sqrt(-2.0 * log(u)) * cos(2.0 * PI * v);
    }
    phase = 1 - phase;
    return z;
}

 /** ------------------------------------------------------------------- *
   * @fn        getTimeChildYear                                         *
   *                                                                     *
   * @brief     Randomly generate the number of times a female rabbit    *
   *            reproduces in a year                                     *
   *                                                                     *
   * @return    Number of reproduction in normal distribution            *
   * ------------------------------------------------------------------- */
int getTimesChildYear()
{
    int times;
    double num;

    num = BoxMuller() + 6;
    if(3.5 <= num && num < 4.5) times = 4;
    else if(4.5 <= num && num < 5.5) times = 5;
    else if(5.5 <= num && num < 6.5) times = 6;
    else if(6.5 <= num && num < 7.5) times = 7;
    else times = 8;

    return times;
}

 /** ------------------------------------------------------------------- *
   * @fn        getNbBaby                                                *
   *                                                                     *
   * @brief     Generate an integer between 3 and 6 with equal           *
   *            probability                                              *
   *                                                                     *
   * @return    An integer variable between 3 and 6                      *
   * ------------------------------------------------------------------- */
int getNbBaby(void)
{
    return 3 + (genrand_real2() * 3);
}


 /** ------------------------------------------------------------------- *
   * @fn         RealRabbit                                              *
   *                                                                     *
   * @brief      An algorithm for realistic simulation of rabbit         *
   *             populations                                             *
   *                                                                     *
   * @param      Rabbit {struct Rabbit} The struct array.                *
   * @param      Rabbit_MEM {struct Rabbit} Secondary Structures         *
   * @param      numStart {int} Number of rabbits at the start           *
   * @param      duration {int} Duration of the simulation               *
   * ------------------------------------------------------------------- */
void RealRabbit(struct Rabbit *Rabbit, struct Rabbit *Rabbit_MEM, int numStart, int duration)
{
    int countRabbit = numStart; // number of male rabbits
    int countRabbit_MEM = numStart;
    int countRabbit_CHILDBITRH = 0; // number of female rabbits suitable for childbirth
    int oneMale = 0;

    // In the first month, there was NUMBERSTART male rabbits and NUMBERSTART female rabbits by default
    for(int i=0; i<numStart; i++)
    {
        (Rabbit+i)->age = 1;
        (Rabbit+i)->sex = judgeGender();
        (Rabbit+i)->sexualMat = timeSexualMat();
        (Rabbit+i)->survivalState = calculChanceSurvival((Rabbit+i)->age, (Rabbit+i)->sexualMat);
        if((Rabbit+i)->sex == 2) (Rabbit+i)->timesChildYear = getTimesChildYear();
    }

    // Delete the rabbit that died in the first month
    for(int i=0; i<countRabbit; i++)
    {
        if((Rabbit+i)->survivalState == 0)
        {
            countRabbit_MEM--;
        }
    }

    

    // Synchronisation number the rabbits
    countRabbit = countRabbit_MEM;

    // reset the array
    resetArray_Rabbit(Rabbit, Rabbit_MEM, countRabbit);

    

    for(int month = 0; month < duration; month++)
    {
        // Update the age
        for(int i=0; i<countRabbit; i++)
        {
            (Rabbit+i)->age++;
        }

        // Calculate fertility
        // For rabbits, the number of males and females isn't taken into account
        // So, it have to use countRabbit and countRabbit_MEM for calcul
        // All in all, calculate the number of rabbits suitable for childbirth
        // As long as there are male rabbits, there must be female rabbits !!!
        for(int i=0; i<countRabbit; i++)
        {
            if((Rabbit+i)->sex == 1)
            {
                oneMale = 1;
                break;
            }
        }

        for(int i=0; i<countRabbit; i++)
        {
            
            if(((Rabbit+i)->sex == 2) && ((Rabbit+i)->sexualMat <= (Rabbit+i)->age) && (oneMale == 1))
            {
                double probability = genrand_real2();
                if((((double)(Rabbit+i)->timesChildYear / (double)12)) >= probability)
                {
                    countRabbit_CHILDBITRH += getNbBaby();
                    (Rabbit+i)->timesChildYear --;
                    
                
                //printf("countRabbit_CHILDBITRH: %d\n", countRabbit_CHILDBITRH);
            }
        }

        for(int i=0; i<countRabbit_CHILDBITRH; i++)
        {
            (Rabbit+countRabbit_MEM)->sex = judgeGender();
            (Rabbit+countRabbit_MEM)->age = 1;
            (Rabbit+countRabbit_MEM)->sexualMat = timeSexualMat();
            (Rabbit+countRabbit_MEM)->survivalState = calculChanceSurvival(
                (Rabbit+countRabbit_MEM)->age, (Rabbit+countRabbit_MEM)->sexualMat);
            (Rabbit+countRabbit_MEM)->timesChildYear = getTimesChildYear();
            countRabbit_MEM++;
        }

        // Synchronisation number the rabbits
        countRabbit = countRabbit_MEM;

        // Update the chance of death
        for(int i=0; i<countRabbit; i++)
        {
            (Rabbit+i)->survivalState = calculChanceSurvival((Rabbit+i)->age, (Rabbit+i)->sexualMat);
        }

        // Delete the rabbit died
        for(int i=0; i<countRabbit; i++)
        {
            if((Rabbit+i)->survivalState == 0)
            {
                countRabbit_MEM--;
            }
        }

        printf("Month: %d\t", month+1);
        printf("Number of rabbits: %d\t",countRabbit_MEM);
        printf("Number of death: %d\t", countRabbit - countRabbit_MEM);
        printf("Number of birth: %d\n", countRabbit_CHILDBITRH);

        // Synchronisation number the rabbits
        countRabbit = countRabbit_MEM;

        // reset the array
        resetArray_Rabbit(Rabbit, Rabbit_MEM, countRabbit);

        // Annual refresh of the number of births to female rabbits
        for(int i=0; i<countRabbit; i++)
        {
            if((Rabbit+i)->age % 12 == 0 && (Rabbit+i)->sex == 2)
            {
                (Rabbit+i)->timesChildYear = getTimesChildYear();
            }
        }

        // reset number of baby in the next month
        countRabbit_CHILDBITRH = 0;

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

int main()
{
    /* Inisiation for the ramdon generator */
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    /*INIT*/
    static struct Rabbit Rabbit[NB_MAX]={0};
    static struct Rabbit Rabbit_MEM[NB_MAX]={0};

    //RabbitSwarmAlgo();
    RealRabbit(Rabbit, Rabbit_MEM, NUMRABBITSTART, DURATION);
    
    /*
    // Test of fonctions
    for(int i=0; i<20; i++)
    {
        printf("JudgeGender:%d\t", judgeGender());
        printf("timeSexualMat:%d\t", timeSexualMat());
        printf("getTimesChildYear:%d\t", getTimesChildYear());
        printf("getNbBaby:%d\n", getNbBaby());
    }
    */
    return EXIT_SUCCESS;
}