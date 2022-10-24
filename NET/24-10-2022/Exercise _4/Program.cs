using System;

namespace Exercise__4
{

    public delegate int NumberFind(int n);

    public class Meteo
    {
        private static int Num;
        public static int getNum(int num)
        {
            Num = num;
            return Num;
        }
        public static int getSituation()
        {
            int statu = 0;
            if(Num < 5)
                statu = 1; // soleil
            if(Num > 5 && Num <= 50)
                statu = 2; //nuages
            if(Num > 50 && Num <= 90)
                statu = 3; // pluie
            if (Num > 90)
                statu = 4; // orage

            return statu;
        }

        public static void printStatu(Meteo m)
        {
            if (Num < 5)
                Console.WriteLine("soleil");
            if (Num > 5 && Num <= 50)
                Console.WriteLine("nuages");
            if (Num > 50 && Num <= 90)
                Console.WriteLine("pluie");
            if (Num > 90)
                Console.WriteLine("orage");
        }

        /*
        static void Main(string[] args)
        {
            NumberFind nf = new NumberFind(getNum);
            nf(25);

            Console.WriteLine("{0}", getSituation());

        }
        */
    }

    public static int Main(string[] args)
    {
        Meteo meteo = new Meteo();
    }
}