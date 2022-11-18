using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

delegate int GetMeteoDelegate(int n);
namespace ConsoleApp2
{
    public class meteo
    {
        public int randomNum;
        int getMeteo()
        {
            int x = 0;
            int rand;
            Random random = new Random();
            randomNum = random.Next(100);
            if (randomNum < 5) x = 1; // Au soleil.
            else if (5 <= randomNum && randomNum < 50) x = 2; // nuages
            else if (50 <= randomNum && randomNum < 90) x = 3; // La pluie
            else x = 4; // Lorage.
            return x;
        }

        internal class Program
        {
            static void Main(string[] args)
            {
                //Console.WriteLine("Hello, World!");
                GetMeteoDelegate GMD1 = new GetMeteoDelegate(meteo.randomNum);
            }
        }


    }
}
