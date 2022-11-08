#include "Simulation_TP4_Ao-XIE.h"
#include "Random.c"

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

    RealRabbit();

    return EXIT_SUCCESS;
}
