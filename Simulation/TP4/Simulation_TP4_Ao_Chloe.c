 /** ------------------------------------------------------------------- *
   * @todo       Rabbit colony simulation algorithm                      *
   * @authors    Ao XIE; Cholé BERTHOLD                                  *
   * @version    3.0.1                                                   *
   *                                                                     *
   * Updates:                                                            *
   *     1. Updating the simple rabbit swarm algorithm from a fictional  *
   *        to a Fibonacci algorithm to simplify the complexity of the   *
   *        algorithm.                                                   *
   *     2. Update to calcul by year.                                    *
   * ------------------------------------------------------------------- */

#include "Simulation_TP4_Ao_Chloe.h"

 /** ------------------------------------------------------------------- *
   * @fn       RabbitSwarmAlgo                                           *
   *                                                                     *
   * @brief    Calcul value of Pi with the Monte Carlo Simulation        *
   *                                                                     *
   * @param    n {int}    Duration of this algo.                         *
   * ------------------------------------------------------------------- */
void RabbitSwarmAlgo(int n)
{
    int i;
    int s1, s2;
    if(n==1 || n==2)
    {
         printf("year: %d\tNumber of rabbits: 1\n", n);
    }
    s1 = 1;
    s2 = 1;
    for(i=3; i<=n; i++)
    {
        s2 = s1 + s2; //Tumbling and adding method
        s1 = s2 - s1;
        printf("year: %d\tNumber of rabbits: %d\n", i, s2);
    }
}

 /** ------------------------------------------------------------------- *
   * @fn         judgeGender                                             *
   *                                                                     *
   * @brief      Generate gender with equal probability                  *
   *                                                                     *
   * @return     Sex [1-> male; 0 -> female]                             *
   * ------------------------------------------------------------------- */
int judgeGender(void)
{
    int sex;
    double random;

    random = genrand_real2();
    if(random < 0.5) sex = 1;
    else sex = 0;

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
   *                                                                     *
   * @return     Survival rate of rabbits [1-> survive; 0 -> die]        *
   * ------------------------------------------------------------------- */
int calculChanceSurvival(int ageRabbit)
{
    double chanceSurvival;
    double Outdo = 0;
    int surviveState = 0;


    chanceSurvival = genrand_real2();
    if(ageRabbit == 0) // For underage rabbits
    {
        if(chanceSurvival<=0.35) surviveState = 1;
    }
    else
    {   
        if(ageRabbit < 10) // For rabbits who are adults but not 10 years old
        {
            if(chanceSurvival <= 0.6) surviveState = 1;
        }
        else
        {
            Outdo = ageRabbit - 9;
            if(chanceSurvival <= (0.6 - (Outdo * 0.1))) surviveState = 1;
        }
    }

    return surviveState;
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
    if(num < 4.5) times = 4;
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
   * @fn         getDeaths                                               *
   *                                                                     *
   * @brief      Updates the number of rabbits after one year according  *
   *             to their age and survival rate                          *
   *                                                                     *
   * @param      start {Rabbit *} The arrays of rabbits                  *
   *                                                                     *
   * @return     Survival rate of rabbits [1-> survive; 0 -> die]        *
   * ------------------------------------------------------------------- */
void getDeaths(Rabbit * start){
    int rabbit;
    
    start->females[15] = 0;
    start->males[15] = 0;
    
    for(int age = 14; age > -1; age --){

        for(rabbit = 0; rabbit < start->females[age]; rabbit ++){
            start->females[age + 1] += calculChanceSurvival(age);
        }

        start->females[age] = 0;

        for(rabbit = 0; rabbit < start->males[age]; rabbit ++){
            start->males[age + 1] += calculChanceSurvival(age);
        }

        start->males[age] = 0;
    }
}

 /** ------------------------------------------------------------------- *
   * @fn         getAdultFemales                                         *
   *                                                                     *
   * @brief      Get the number of females adults rabbits.               *
   *                                                                     *
   * @param      rabbit {Rabbit} Struct for the rabbits.                 *
   * @return     Number of females adults rabbits.                       *
   * ------------------------------------------------------------------- */
long long int getAdultFemales(Rabbit * rabbits){
    long long int females = 0;

    for(int age = 1; age < 16; age++){
        females += rabbits->females[age];
    }

    return females;
}

 /** ------------------------------------------------------------------- *
   * @fn         getAdultMale                                            *
   *                                                                     *
   * @brief      Count if there is at least one male rabbit.             *
   *                                                                     *
   * @param      rabbit {Rabbit} Struct for the rabbits.                 *
   * @return     State of number the male rabbit. [1->Yes; 0->No]        *
   * ------------------------------------------------------------------- */
int getAdultMale(Rabbit * rabbits){
    int age = 1;

    while(age < 16 && rabbits->males[age] == 0){
        age ++;
    }

    return (age == 16)? 0 : 1;
}

 /** ------------------------------------------------------------------- *
   * @fn         realRabbit                                              *
   *                                                                     *
   * @brief      An algorithm for realistic simulation of rabbit         *
   *             populations                                             *
   *                                                                     *
   * @param      numStartBaby {int} Number of babies rabbits at first.   *
   * @param      numStartAdult {int} Number of adults rabbits at first.  *
   * @param      rabbit {Rabbit} Struct for the rabbits.                 *
   * @param      duration {int} Duration of the simulation               *
   * ------------------------------------------------------------------- */
void realRabbit(int numStartBaby, int numStartAdult, Rabbit *rabbit, int duration)
{

    // DEFINE RABBITS -------------------------------------------------------------------
    // Define those baby rabbits at start
    for(int i=0; i<numStartBaby; i++)
    {
        int sex = judgeGender();
        if(sex == 1) rabbit->females[0] ++;
        else rabbit->females[0]++;
    }
    
    // Define those adults rabbits at start
    for(int i=0; i<numStartAdult; i++)
    {
        int sex = judgeGender();
        if(sex == 1)
        {
            int age = genrand_real2() * 4;
            rabbit->males[age]++;
        }
        else{
            int age = genrand_real2() * 4;
            rabbit->females[age]++;
        }
    }

    // Simulation for every year -------------------------------------------------------------------
    for(int year=0; year<duration; year++)
    {
        // First, give birth to those little
        // For rabbits, the number of males and females isn't taken into account
        // So, it have to use countRabbit and countRabbit_MEM for calcul
        // All in all, calculate the number of rabbits suitable for childbirth
        // As long as there are male rabbits, there must be female rabbits !!!
        long long int numAdultFemales = getAdultFemales(rabbit);
        int stateMale = getAdultMale(rabbit);
        long int babyThisYear = 0;
        long int babies[2] = {0};
    
        if(stateMale){
            for(int i=0; i<numAdultFemales; i++)
            {
                int timeThisYear = getTimesChildYear();
                for(int j=0; j<timeThisYear; j++)
                {
                    babyThisYear += getNbBaby();
                }
            }

            for(int i=0; i<babyThisYear; i++)
            {
                int sex = judgeGender();
                babies[sex] ++;
            }
        }

        // second, those who need to die >_<
        getDeaths(rabbit);

        // Add those baby (._.)
        rabbit->males[0] = babies[1];
        rabbit->females[0] = babies[0];

        // show off !_! our rabbits
        long long int numMales = 0;
        long long int numFemales = 0;
        for(int i=0; i<=16; i++)
        {
            numMales += rabbit->males[i];
            numFemales += rabbit->females[i];
        }

        printf("Year: %2d\t", year+1);
        printf("Number of males rabbits: %lld\t", numMales);
        printf("Number of females rabbits: %lld\n", numFemales);
    }
}

 /** ------------------------------------------------------------------- *
   * @todo       Prepare the generator of random numbers, It's MT in the *
   *             second lab.                                             *
   * ------------------------------------------------------------------- */
/* Period parameters */  

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
    static struct Rabbit Rabbit;
    for(int i=0; i<=16; i++)
    {
        Rabbit.females[i] = 0;
        Rabbit.males[i] = 0;
    }

    //RabbitSwarmAlgo(DURATION);
    realRabbit(2, 2, &Rabbit, DURATION);
    
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