using System;

namespace TP3
{

    public class Foo<T>
    {
        
        public void Method(int i)
        {
            Console.WriteLine("Un entier à été passé en paramètre, il est " + i);
        }
        public void Method<T>(T i)
        { 
            Console.WriteLine("Le type de paramètre est " + i.GetType());
        }
        public void Bar<T>(T i) // question !!!!
        {
            Method(i);
        }
    }
    public class Bar
    {
        
    }

   interface IDocument
    {
        string Name
        {
            get;
            set;
        }
        int NumDeDocument
        {
            get;
            set;
        }
        string Contienu
        {
            get;
        }
        /*
        public void ajouterDocument(string NomdeDocument, int nombre, string contenue)
        {
            Name = NomdeDocument;
            NumDeDocument += nombre;
            Contienu = contenue;
        }

        public void retraitDocument(string Name)
        {
            NumDeDocument -= 1;
        }
        */ 
    }

    class Document : IDocument
    {
        public Document(string name, int num, string contenue)
        {
            Name = name;
            NumDeDocument = num;
            Contenue = contenue;

        }
        public string Name
        {
            get;
            set;
        }
        public int NumDeDocument
        {
            get;
            set;
        }
        public string Contenue
        {
            get;
            set;
        }

        
    }
    class Program
    {
        static void printDocument(IDocument d)
        {
            Console.WriteLine("nom de ce document est {0}, nombre est {1}", d.Name, d.NumDeDocument);
        }
        static void Main(string[] args)
        {
            /*
            //Console.WriteLine("Hello World!");
            Foo<int> T1 = new Foo<int>();
            Foo<float> T2 = new Foo<float>();
            Foo<double> T3 = new Foo<double>();
            T1.Method(999);
            T2.Method((float)2.36351545);
            T3.Method((double)2.3655545);
            T1.Bar(25);
            */

            int num = 20;
            string contenue = "helloworld";
            Document Bonjour = new Document("Bonojur", num, contenue);
            // Bonjour.ajouterDocument;
            Bonjour.printDocument();
            Bonjour.printDocument();


   

        }
    }
}
