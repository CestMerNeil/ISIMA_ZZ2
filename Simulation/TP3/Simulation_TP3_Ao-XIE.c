#include <stdio.h>
#include <math.h>
#include <stdlib.h> 


 /** ----------------------------------------------------------------------------------------------------------------------------------- *
  * @todo       Prepare the generator of random numbers, It's MT in the second lab.                                                      *
  * ------------------------------------------------------------------------------------------------------------------------------------ */
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

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void)
{
    return genrand_int32()*(1.0/4294967296.0); 
    /* divided by 2^32 */
}
 
 /** ----------------------------------------------------------------------------------------------------------------------------------- *
  * @fn         simPi                                                                                                                    *
  * @brief      Calcul value of Pi with the Monte Carlo Simulation                                                                       *
  * @param      times   Times of calcul.                                                                                                 *
  * @return     Value of Pi                                                                                                              *
  * @todo       It's for the question ONE                                                                                                *
  * ------------------------------------------------------------------------------------------------------------------------------------ */
double simPi(int times)
{
    double Pi;
    double x;
    double y;
    double countIn = 0;
    double countOut = 0;
    for(int i=0; i<times; i++)
    {
        x = genrand_real2();
        y = genrand_real2();
        countOut += 1;
        if(y <= sqrt(1-pow(x, 2)))
        {
            countIn += 1;
        }
    }

    Pi = (4 * countIn) / countOut;

    return Pi;
}

 /** ----------------------------------------------------------------------------------------------------------------------------------- *
  * @fn         avgPi                                                                                                                    *
  * @brief      Using the simPi() function, multiple calculations are averaged to get a more accurate value.                               *
  * @param      times   Times of calcul.                                                                                                 *
  * @return     Value of Pi                                                                                                              *
  * @todo       It's for the question TWO                                                                                                *
  * ------------------------------------------------------------------------------------------------------------------------------------ */
double avgPi(double times)
{
    double avgPi[50] = {0};
    double sumPi = 0;
    for(int i=0; i<times; i++)
    {
        avgPi[i] = simPi(1000000);
        sumPi += avgPi[i];
    }

    return sumPi / times;

}

 /** ----------------------------------------------------------------------------------------------------------------------------------- *
  * @fn         calculRange                                                                                                              *
  * @brief      Calculate confidence interval.                                                                                           *
  * @param      times   Times of calcul.                                                                                                 *
  * @return     Value of Pi                                                                                                              *
  * @todo       It's for the question TWO                                                                                                *
  * ------------------------------------------------------------------------------------------------------------------------------------ */
double calculRange(int n)
{
    double T;
    double S;
    double sum = 0;
    double avgPi[50] = {0};
    switch (n)
    {
    case 1:
        T = 12.706;
        break;
    case 2:
        T = 4.303;
        break;
    case 3:
        T = 3.182;
        break;
    case 4:
        T = 2.776;
        break;
    case 5:
        T = 2.571;
        break;
    case 6:
        T = 2.447;
        break;
    case 7:
        T = 2.365;
        break;
    case 8:
        T = 2.308;
        break;
    case 9:
        T = 2.262;
        break;
    case 10:
        T = 2.228;
        break;
    case 11:
        T = 2.201;
        break;
    case 12:
        T = 2.179;
        break;
    case 13:
        T = 2.160;
        break;
    case 14:
        T = 2.145;
        break;
    case 15:
        T = 2.131;
        break;
    case 16:
        T = 2.120;
        break;
    case 17:
        T = 2.110;
        break;
    case 18:
        T = 2.101;
        break;
    case 19:
        T = 2.093;
        break;
    case 20:
        T = 2.086;
        break;
    case 21:
        T = 2.080;
        break;
    case 22:
        T = 2.076;
        break;
    case 23:
        T = 2.069;
        break;
    case 24:
        T = 2.064;
        break;
    case 25:
        T = 2.060;
        break;
    case 26:
        T = 2.056;
        break;
    case 27:
        T = 2.052;
        break;
    case 28:
        T = 2.048;
        break;
    case 29:
        T = 2.045;
        break;
    case 30:
        T = 2.042;
        break;
    case 40:
        T = 2.021;
        break;
    case 80:
        T = 2.000;
        break;
    case 120:
        T = 1.980;
        break;
    default:
        T = 1.960;
        break;
    }

    for(int i=0; i<n; i++)
    {
        avgPi[i] = simPi(10000);
        sum += avgPi[i];
    }

    for(int i=0; i<n; i++)
    {
        S += pow(avgPi[i] - (sum / (double)n), 2);
    }

    S = S / (double)(n - 1);
    S = sqrt(S);
    return S * T;
}

int main()
{
    /* Inisiation for the ramdon generator */
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    /* Inisiation for those values */
    double times_ques2 = 40;
    double valAvgPi;
    double sum;
    int i = 0;
    double Pi[50] ={0};
    double count = 0;

    /* ------------------------------ Test of question ONE ------------------------------ */ 
    printf("/* ------------------------------ Test of question ONE ------------------------------ */\n");
    printf("%lf\t", simPi(1000));
    printf("%lf\t", simPi(1000000));
    printf("%lf\n", simPi(1000000000));
    

    /* ------------------------------ Test of question TWO ------------------------------ */
    printf(" /* ------------------------------ Test of question TWO ------------------------------ */\n");
    valAvgPi = avgPi(times_ques2);
    printf("%lf\n", valAvgPi);
    printf("Absolte error is %lf\n", M_PI - valAvgPi);
    printf("Relative error is %lf\n", M_PI / valAvgPi);
    

    /* ------------------------------ Test of question TWO ------------------------------ */
    printf("/* ------------------------------ Test of question TWO ------------------------------ */\n");
    do
    {
        /* code */
        valAvgPi = avgPi(times_ques2);
        Pi[i] = valAvgPi;
        sum += valAvgPi;
        i++;
        //printf("test of %d\t times \n",i);
    } while (i<times_ques2);

    valAvgPi = sum / times_ques2;
    sum = 0;

    for(int j = 0; count<times_ques2; j++)
    {
        if(Pi[j] < valAvgPi+calculRange(times_ques2) && Pi[j] > valAvgPi-calculRange(times_ques2))
        {
            sum += Pi[j];
            count++;
        }
    }

    valAvgPi = sum / count;

    printf("%lf\n", valAvgPi);
    printf("Absolte error is %lf\n", M_PI - valAvgPi);
    printf("Relative error is %lf\n", M_PI / valAvgPi);


    
    

    return EXIT_SUCCESS;
}