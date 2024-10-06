/**
 * @author Ao XIE
 * @version 3.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * @brief One of the first non-linear proposed by John Von Neumannn
 * @param The original random number
 * @return Result of the original random number
 */ 
void Ques1_Von_Neumann(int NumOrignal)
{
    int NumO = NumOrignal;
    for(int i=0; i<100; i++)
    {
        NumO = NumO * NumO;
        printf("%08d ", NumO);
        NumO = NumO / 100;
        printf("%06d ", NumO);
        NumO = NumO % 10000;
        printf("%04d\n", NumO);
    }
}

/**
 * @brief Test of question one, use 4100, 1324, 1234 and 3141.
 */
void Ques2_test_Q1()
{
    printf("For the number 4100:\n");
    Ques1_Von_Neumann(4100);
    printf("For the number 1324:\n");
    Ques1_Von_Neumann(1324);
    printf("For the number 1301:\n");
    Ques1_Von_Neumann(1301);
    printf("For the number 1234:\n");
    Ques1_Von_Neumann(1234);
    printf("For the number 3141:\n");
    Ques1_Von_Neumann(3141);
}

/**
 * @brief man 3 rand
 */
void Ques3_Ramdon()
{
    int val;
    for(int i=0; i<100; i++)
    {
        val = rand();
        printf("%d\n", val);
    }
}

/**
 * @brief Result of a coin tossing
 * @param Number of coin tosses
 */
void Ques4_Coin_Tossing(int times)
{
    int val;
    int count_face = 0;
    int count_back = 0;

    for(int i=0; i<times; i++)
    {
        val = rand() % 10;
        if(val < 5)
        {
            count_back += 1;
        }  
        else
        {
            count_face += 1;
        }
    }

    printf("Result of %d Times:\n ", times);
    printf("Face: %d\n", count_back);
    printf("Back: %d\n\n", count_face);
    
}

/**
 * @brief Random result of dice
 * @param Number of sides of a dice, number of throws
 */ 
void Ques5_Result_of_Dice(int numFaces, int numThrow)
{
    int res[15] = {0};                  //The dice have a maximum of 10 faces as required by the question, set 15 to ensure some redundancy.
    for(int i=0; i<numThrow; i++)
    {
        int val = rand() % numFaces;
        res[val] += 1;
    }

    printf("DICE Result of %d faces %d Times:\n", numFaces, numThrow);
    for(int j=0; j<numFaces; j++)
    {
        printf("Result of face %04d: %04d times\n", j, res[0]);
    }

}

/**
 * @brief Linear Congrential Generators with parameter 5, 1 and 16
 * @param Input of LCGs
 * @return Result of the input
 */
int Ques6_LCGs_intRand(int x0, long int a, int c, long int m)
{
    
    int x1;         //Introduce values
    x1 = a * x0 + c;
    x1 = x1 % m; 

    return x1;

}

/**
 * @brief Question 6 divide by 16
 */
float Ques7_LCGs_floatRand(float numIn, int a, int c, long int m)  // The parameters in the LCGs are all integers.
{
    int numOrignal;           //For the orignal number
    float numNext;
    numOrignal = 16 * numIn;
    numNext = Ques6_LCGs_intRand(numOrignal, a, c, m);
    numNext = numNext / 16;

    return numNext;
}

/**
 * @brief 15 test of question 6.
 */
void Ques8_Test_of_Ques6()
{
	int x = 10;
    	for(int i=0; i<15; i++)
    	{
		int a = rand() % 1000 + 1;
		int c = rand() % 1000 + 1;
		int m_pre = rand() % 50 + 5 ;	// Make sure m is the most big. 
		long int m = pow(2, m_pre);	// In gereral, the parameter m is a multipe of 2.
		printf("The %dth test.\n In this group, using those params\n a = %d\n c = %d\n m = %ld\n", i+1, a, c, m);
    		for(int j=0; j<32; j++)
		{
			printf("%d\n", x);
			x = Ques6_LCGs_intRand(x, a, c, m);
		}
    	}
}

/**
 * @brief Best tuples finded in Internet.
 */
void Ques9_Best_Tuples_for_LCGs()
{
    /**
     * From an internet search, the most common options currently available are
     * a = 134775813
     * c = 1
     * m = 2^32
     */
     long int t1 = 10;
     long int a = 134775813;
     int c = 1;
     long int m = pow(2, 32);
     for(int i=0; i<100; i++)
     {
        printf("%ld\n", t1);
        t1 = Ques6_LCGs_intRand(t1, a, c, m);
     }
}

void Ques10_Newest_Ramdon_number_generators()
{
	/**
     * A new chaos-based true random number generator and a sliding mode controller to synchronize the proposed TRNDs proposed by T.L.Liao et al. in "Design and Synchronization of Chaos-Based True Random Number Generators and Its FPGA Implementation" published on January 12, 2022.
     * DOI: 10.1109/ACCESS.2022.3142536
	 */
}
void Ques11_Quality_Test()
{
    /**
     * https://doi.org/10.1016/0010-4655(78)90080-2
     * Some simple concept tests of pseudorandom number generators are discussed in S. Garpman et al., 1978 in Computer Physics Communications.
     */
}

int main()
{
    // Result of question 1
    Ques1_Von_Neumann(1234);

    // Result of Question 2
    Ques2_test_Q1();

    // Result of question 3
    Ques3_Ramdon();

    // Result of question 4
    Ques4_Coin_Tossing(10);
    Ques4_Coin_Tossing(100);
    Ques4_Coin_Tossing(1000);

    // Result of question 5
    // Test of 6 faces
    Ques5_Result_of_Dice(6, 100);
    Ques5_Result_of_Dice(6, 1000);
	// Test of 10 faces
    Ques5_Result_of_Dice(10, 10);
    Ques5_Result_of_Dice(10, 100);
    Ques5_Result_of_Dice(10, 1000);
    Ques5_Result_of_Dice(10, 1000000);

    // Result of question 6
    int q6_test = 10;
    for(int i=0; i<32; i++)
    {
        printf("%d\n", q6_test);
        q6_test = Ques6_LCGs_intRand(q6_test, 5, 1, 16);
    }

	// Result of question 7
    float t = 0.625;
    for(int i=0; i<32; i++)
    {
        printf("%.4f\n", t);
        t = Ques7_LCGs_floatRand(t, 5, 1, 16);
    }

    // Result of question 8
    Ques8_Test_of_Ques6();

    //Result of question 9
    Ques9_Best_Tuples_for_LCGs();


    return 0;
}