using System;
using System.Collections.Generic;

namespace _NET_TP2
{
    class Program
    {

        /**
         * @brief La premier question
         * @param Min et Max
         * @return SommeEntier
         */
        static int CalculSommeEntier(int v1, int v2)
        {
            int sum = 0;
            for (int i = v1; i <= v2; i++)
            {
                sum += i;
            }
            return sum;
            // while
        }

        //

        /**
         * @brief 2eme question
         * @param
         * @return
         */
        static double CalculMoyenne(List<Double> liste)
        {
            int num = liste.Count;
            int sum = 0;
            double moy = 0;
            for (int i = 0; i < num; i++)
            {
                sum += liste.i;
            }
            moy = sum / sum;
            return moy;
            //foreach

        }



        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");

            // Test de Question 1
            Console.WriteLine(CalculSommeEntier(1, 100));

            // Test de Question 2
            //List<double> liste = new List<double>(2.3, 6.8, 6.8);



        }
    }
}
