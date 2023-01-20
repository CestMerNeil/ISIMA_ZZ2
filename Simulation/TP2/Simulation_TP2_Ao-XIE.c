/* 
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using init_genrand(seed)  
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.                          

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote 
        products derived from this software without specific prior written 
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
   email: m-mat @ math.sci.hiroshima-u.ac.jp (remove space)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

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
  * @fn         uniform                                                                                                                 *
  * @brief      Randomly generate a pseudo-number between a_rangeMin and b_rangeMax.                                                    *
  * @param      a_rangeMin  Minimun value in the range                                                                                  *
  * @param      b_rangeMax  Maxmun value in the range                                                                                   *
  * @return     A pseudo-random number between a_rangeMin and b_rangeMax.                                                               *
  * @todo       It's for the question TWO                                                                                               *
  * ----------------------------------------------------------------------------------------------------------------------------------- */
double uniform(double a_rangeMin, double b_rangeMax)
{
    return a_rangeMin + (b_rangeMax - a_rangeMin) * genrand_real2();
}

/** ----------------------------------------------------------------------------------------------------------------------------------- *
  * @fn         Ques3_A_numTest                                                                                                         *
  * @brief      Install the three ratios entered to generate a pseudo-random number.                                                    *
  * @param      testTimes   Number of random numbers generated.                                                                         * 
  * @param      ratio1ST    The first ratio                                                                                             *
  * @param      ratio2NE    The secong ratio                                                                                            *       
  * @param      ratio3ND    THe third ratio                                                                                             *
  * @return     An address that points to the result                                                                                    *
  * @todo       It's for the question THREE PART A                                                                                      *
  * ----------------------------------------------------------------------------------------------------------------------------------- */
int * Ques3_A_proportionPseudoNumber(int testTimes, int ratio1ST, int ratio2ND, int ratio3ND)
{
    /* Deckaring local variables */
    static int resultQues3[3] = {0};
    int sum = ratio1ST + ratio2ND + ratio3ND;


    for(int i=0; i<testTimes; i++)
    {
        /* Generate random numbers */
        int val = genrand_real2() * sum;    // For a random number between 0 and sum

        /* Categorized random numbers */
        if(val < ratio1ST){
            resultQues3[0] += 1; 
        }
        else if(val >= (ratio1ST + ratio2ND)){  // Only retio3ND remians in the range sum
            resultQues3[2] += 1;
        }
        else{
            resultQues3[1] += 1;
        }
    }

    return resultQues3;
}

/** ----------------------------------------------------------------------------------------------------------------------------------- *
  * @fn         Ques3_B_HDL                                                                                                             *
  * @brief      Install the three ratios entered to generate a pseudo-random number.                                                    *
  * @param      size   Number of random numbers generated.                                                                              * 
  * @param      array    The first ratio                                                                                                *
  * @return     An address that points to the result                                                                                    *
  * @todo       It's for the question THREE PART B                                                                                      *
  * ----------------------------------------------------------------------------------------------------------------------------------- */
double * Ques3_B_HDL(int size, int *array)
{
    /* Deckaring local variables */
    static double resultQues3B[1000000] = {0};  // Use the first address of the output to store the number of arrays
    double sum = 0;    // The sum of the numbers in the array
    int i = 0;

    /* Calcul the sum */
    for(i=0; i<size; i++)
    {
        sum += array[i];
    }

    /* Store the numbers of the array */
    resultQues3B[0] = i + 1; 

    /* Another method to calcul the sum */
    /*
    int i = 0;
    while(array[i] != '\0')
    {
         sum += array[i];
         i++;   // Number of the classes
    }
    */
    
    /* Calculate the probability of each class*/
    for(int j=1; j<=size; j++)
    {
        resultQues3B[j] = array[j-1] / sum;
    }

    return resultQues3B;
    
}

/** ----------------------------------------------------------------------------------------------------------------------------------- *
  * @fn         negExp                                                                                                                  *
  * @brief      A random number generator with continuous distribution                                                                  *
  * @param      Mean    Generate the average of the random numbers                                                                      * 
  * @return     Result of the generated random number.                                                                                  *
  * @todo       It's for the question FOUR                                                                                              *
  * ----------------------------------------------------------------------------------------------------------------------------------- */
 double negExp(double Mean)
 {
    return - Mean * log(1.0 - uniform(0, 1));
 }



 /** ----------------------------------------------------------------------------------------------------------------------------------- *
   * @fn        normalDis                                                                                                                *
   * @brief     Gaussian function calculator                                                                                             *
   * @param     x        x in Gaussian function                                                                                          *
   * @param     mu                                                                                                                       *      
   * @param     sita                                                                                                                     * 
   * @return    Result of x in Gaussian function.                                                                                        *
   * @todo      Prepare for question 5                                                                                                   *
   * ----------------------------------------------------------------------------------------------------------------------------------- */
 double normalDis(double x, double mu, double sita)
 {
    double Pi = acos(-1.0);
    double e = 2.71828182;
    double fx;
    fx  = (1 / (sqrt(2 * Pi) * sita)) * pow(e, -1 * (pow(x-mu, 2) / (2 * (pow(sita, 2)))));

    return fx;
 }

 /** ----------------------------------------------------------------------------------------------------------------------------------- *
   * @fn        rejectionAlgo                                                                                                            *
   * @brief     A Gaussian distributed random number generator.                                                                          *
   * @param     MinX    Minimun value of X                                                                                               *
   * @param     MaxX    Maximum value of X                                                                                               *                  
   * @param     MaxY    Maximum value of Y                                                                                               * 
   * @return    Result of the generated random number.                                                                                   *
   * @todo      It's for the question FIVE POINT ONE                                                                                     *
   * ----------------------------------------------------------------------------------------------------------------------------------- */
double rejectionAlgo(double MinX, double MaxX, double MaxY)
{
    double x;
    double y;
    double naOne;
    double naTwo;
    double res;
    double realY;

    do
    {
        naOne = uniform(0.0, 1.0);
        naTwo = uniform(0.0, 1.0);
        x = MinX + naOne * (MaxX - MinX);
        y = MaxY * naTwo;
        realY = normalDis(x, (MaxX - MinX) / 2, 20);
        if(y <= realY)
        //((1 / (sqrt(2 * pi))) * pow(2.71828182, -1 * (pow(x, 2) / 2))))
        {
            res = x;
            break;
        }
    }while(1);


    return res;
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


int main(void)
{

    
    int i;
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);
    printf("1000 outputs of genrand_int32()\n");
    for (i=0; i<1000; i++) {
      printf("%10lu ", genrand_int32());
      if (i%5==4) printf("\n");
    }
    printf("\n1000 outputs of genrand_real2()\n");
    for (i=0; i<1000; i++) {
      printf("%10.8f ", genrand_real2());
      if (i%5==4) printf("\n");
    }
    

    /* ------------------------------ Test of question TWO ------------------------------ */
    
    double min = -89.2;
    double max = 56.7;
    for(int i=0; i<50; i++){
        printf("%.2f °C\n", uniform(min, max));
    }
    
    


    /* ------------------------------ Test of question THREE PART A ------------------------------ */
    
    // Test of 1,000 times
    int *p;
    p = Ques3_A_proportionPseudoNumber(1000, 35, 45, 20);
    printf("Question 3 A for %d times\n", 1000);
    printf("Number of A: %d\n", *p);
    printf("Number of B: %d\n", *(p + 1));
    printf("Number of C: %d\n\n", *(p + 2));

    // Test of 10,000 times
    p = Ques3_A_proportionPseudoNumber(10000, 35, 45, 20);
    printf("Question 3 A for %d times\n", 10000);
    printf("Number of A: %d\n", *p);
    printf("Number of B: %d\n", *(p + 1));
    printf("Number of C: %d\n\n", *(p + 2));

    // Test of 100,000 times
    p = Ques3_A_proportionPseudoNumber(100000, 35, 45, 20);
    printf("Question 3 A for %d times\n", 100000);
    printf("Number of A: %d\n", *p);
    printf("Number of B: %d\n", *(p + 1));
    printf("Number of C: %d\n\n", *(p + 2));

    // Test of 1,000,000 times
    p = Ques3_A_proportionPseudoNumber(1000000, 35, 45, 20);
    printf("Question 3 A for %d times\n", 1000000);
    printf("Number of A: %d\n", *p);
    printf("Number of B: %d\n", *(p + 1));
    printf("Number of C: %d\n\n", *(p + 2));
    
    

    /* ------------------------------ Test of question THREE PART B ------------------------------ */
    
    // Input Arrays
    int array1[100] = {600, 400, 400, 200, 100, 100, 500, 1500, 500, 600};
    int array2[100] = {498484, 849484, 38398, 48493, 872739, 73837};
    int array3[1000] = {0};
    int array4[1000000] = {0};
    double *p;
    
    // Test of subpart A
    p = Ques3_B_HDL(10, array1);
    printf("Result of question THREE PART B SUBPART A\n");
    printf("There are %.0f values in the array\n", *p - 1);
    for(int i=1; i<*p; i++)
    {
        printf("The probability of category %d is %.2lf\n", i, *(p+i));
    }

    // Test of subpart B
    p = Ques3_B_HDL(6, array2);
    printf("Result of question THREE PART B SUBPART B\n");
    printf("There are %.0f values in the array\n", *p - 1);
    for(int i=1; i<*p; i++)
    {
        printf("The probability of category %d is %.2lf\n", i, *(p+i));
    }

    // Test of subpart C
    for(int i=0; i<1000; i++)
    {
        array3[i] = genrand_real2() * 1000;
    }
    for(int i=0; i<1000000; i++)
    {
        array4[i] = genrand_real2() * 1000000;
    }

    p = Ques3_B_HDL(1000, array3);
    printf("Result of question THREE PART B SUBPART C\n");
    printf("There are %.0f values in the array\n", *p - 1);
    for(int i=1; i<*p; i++)
    {
        printf("The probability of category %d is %lf\n", i, *(p+i));
    }

    p = Ques3_B_HDL(1000000, array4);
    printf("Result of question THREE PART B SUBPART C\n");
    printf("There are %.0f values in the array\n", *p - 1);
    for(int i=1; i<*p; i++)
    {
        printf("The probability of category %d is %lf\n", i, *(p+i));
    }
    

    /* ------------------------------ Test of question FOUR ------------------------------ */
    
    // Test of part B
    double testQues4_B_1000[1000];
    double testQues4_B_1000000[1000000] = {0};
    double sum = 0;

    for(int i=0; i<1000; i++)
    {
        testQues4_B_1000[i] = negExp(11);
        sum += testQues4_B_1000[i];
        //printf("In the 1,000 tests, the %dnd number is: %.4lf\n", i, testQues4_B_1000[i]);
    }
    printf("Finally, the average of these 1000 values is %lf\n", sum / 1000);

    sum = 0;
    for(int i=0; i<1000000; i++)
    {
        testQues4_B_1000000[i] = negExp(11);
        sum += testQues4_B_1000000[i];
        //printf("In the 1,000 tests, the %dnd number is: %.4lf\n", i, testQues4_B_1000000[i]);
    }
    printf("Finally, the average of these 1,000,000 values is %lf\n", sum / 1000000);

    // Test of part C
    int Test22bins[23] = {0};
    for(int i=0; i<1000; i++)
    {
        if(testQues4_B_1000[i] < 10)
        {
            if(testQues4_B_1000[i] < 5)
            {
                if(testQues4_B_1000[i] < 1) Test22bins[1] += 1;
                else if(testQues4_B_1000[i] < 2) Test22bins[2] += 1;
                else if(testQues4_B_1000[i] < 3) Test22bins[3] += 1;
                else if(testQues4_B_1000[i] < 4) Test22bins[4] += 1;
                else Test22bins[5] += 1;
            }
            else
            {
                if(testQues4_B_1000[i] < 6) Test22bins[6] += 1;
                else if(testQues4_B_1000[i] < 7) Test22bins[7] += 1;
                else if(testQues4_B_1000[i] < 8) Test22bins[8] += 1;
                else if(testQues4_B_1000[i] < 9) Test22bins[9] += 1;
                else Test22bins[10] += 1;
            }
        }
        else if(testQues4_B_1000[i] < 20)
        {
            if(testQues4_B_1000[i] < 15)
            {
                if(testQues4_B_1000[i] < 11) Test22bins[11] += 1;
                else if(testQues4_B_1000[i] < 12) Test22bins[12] += 1;
                else if(testQues4_B_1000[i] < 13) Test22bins[13] += 1;
                else if(testQues4_B_1000[i] < 14) Test22bins[14] += 1;
                else Test22bins[15] += 1;
            }
            else
            {
                if(testQues4_B_1000[i] < 16) Test22bins[16] += 1;
                else if(testQues4_B_1000[i] < 17) Test22bins[17] += 1;
                else if(testQues4_B_1000[i] < 18) Test22bins[18] += 1;
                else if(testQues4_B_1000[i] < 19) Test22bins[19] += 1;
                else Test22bins[20] += 1;
            }
        }
        else if(testQues4_B_1000[i] < 21) Test22bins[21] += 1;
        else if(testQues4_B_1000[i] < 22) Test22bins[22] += 1;
    } 

    for(int i=1; i<23; i++)
    {
        printf("%d\n", Test22bins[i]);
        Test22bins[i] = 0;
    }

    for(int i=0; i<1000000; i++)
    {
        if(testQues4_B_1000000[i] < 10)
        {
            if(testQues4_B_1000000[i] < 5)
            {
                if(testQues4_B_1000000[i] < 1) Test22bins[1] += 1;
                else if(testQues4_B_1000000[i] < 2) Test22bins[2] += 1;
                else if(testQues4_B_1000000[i] < 3) Test22bins[3] += 1;
                else if(testQues4_B_1000000[i] < 4) Test22bins[4] += 1;
                else Test22bins[5] += 1;
            }
            else
            {
                if(testQues4_B_1000000[i] < 6) Test22bins[6] += 1;
                else if(testQues4_B_1000000[i] < 7) Test22bins[7] += 1;
                else if(testQues4_B_1000000[i] < 8) Test22bins[8] += 1;
                else if(testQues4_B_1000000[i] < 9) Test22bins[9] += 1;
                else Test22bins[10] += 1;
            }
        }
        else if(testQues4_B_1000000[i] < 20)
        {
            if(testQues4_B_1000000[i] < 15)
            {
                if(testQues4_B_1000000[i] < 11) Test22bins[11] += 1;
                else if(testQues4_B_1000000[i] < 12) Test22bins[12] += 1;
                else if(testQues4_B_1000000[i] < 13) Test22bins[13] += 1;
                else if(testQues4_B_1000000[i] < 14) Test22bins[14] += 1;
                else Test22bins[15] += 1;
            }
            else
            {
                if(testQues4_B_1000000[i] < 16) Test22bins[16] += 1;
                else if(testQues4_B_1000000[i] < 17) Test22bins[17] += 1;
                else if(testQues4_B_1000000[i] < 18) Test22bins[18] += 1;
                else if(testQues4_B_1000000[i] < 19) Test22bins[19] += 1;
                else Test22bins[20] += 1;
            }
        }
        else if(testQues4_B_1000000[i] < 21) Test22bins[21] += 1;
        else if(testQues4_B_1000000[i] < 22) Test22bins[22] += 1;
    } 

    for(int i=1; i<23; i++)
    {
        printf("%d\n", Test22bins[i]);
    }
    


    /* ------------------------------ Test of question FIVE PART ONE ------------------------------ */
    
    int count[200] = {0};
    FILE *fp;
    fp = fopen("record.txt", "w");
    for(int i=0; i<204800; i++)
    {
        printf("Now is in the %d time", i+1);
        double test = rejectionAlgo(30, 180, 1);
        printf("\t%lf\n", test);
        fprintf(fp, "%10.7lf  ", test);
        for(int i=1; i<=200; i++)
        {
            if(test > i && test < i+1) count[i] += 1;
        }
    }
    fclose(fp);

    for(int i=30; i<=180; i++)
    {
        printf("Result as point %d is %d times\n", i, count[i]);
    }
    

    /* ------------------------------ Test of question FIVE PART TWO ------------------------------ */
    double mean = 0;
    double stdc = 1;
    double data = 0;
    int count[20];

    for(int i=0; i<100; ++i)
    {
        data = BoxMuller(mean, stdc);
        printf("%10.7lf ", data);
    }


    // Test of 1000 times
    data = 0;
    for(int i=0; i<1000; ++i)
    {
        data = BoxMuller(mean, stdc) * 10 - 5;
        if(-4>data) count[0]++;
        if(-4<data && -3>data) count[1]++;
        if(-3<data && -2>data) count[2]++;
        if(-2<data && -1>data) count[3]++;
        if(-1<data && 0>data) count[4]++;
        if(0<data && 1>data) count[5]++;
        if(1<data && 2>data) count[6]++;
        if(2<data && 3>data) count[7]++;
        if(3<data && 4>data) count[8]++;
        if(4<data && 5>data) count[9]++;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d\n",count[i]);
    }

    // Test of 1,000,000 times
    data = 0;
    for(int i=0; i<1000000; ++i)
    {
        data = BoxMuller(mean, stdc) * 10 - 5;
        if(-4>data) count[0]++;
        if(-4<data && -3>data) count[1]++;
        if(-3<data && -2>data) count[2]++;
        if(-2<data && -1>data) count[3]++;
        if(-1<data && 0>data) count[4]++;
        if(0<data && 1>data) count[5]++;
        if(1<data && 2>data) count[6]++;
        if(2<data && 3>data) count[7]++;
        if(3<data && 4>data) count[8]++;
        if(4<data && 5>data) count[9]++;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d\n",count[i]);
    }



    return EXIT_SUCCESS;
}