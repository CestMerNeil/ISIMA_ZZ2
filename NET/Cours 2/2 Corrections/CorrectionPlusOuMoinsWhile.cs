static void Main(string[] args)
{
    int valeurATrouver = new Random().Next(0, 100);
    int nombreDeCoups = 0;
    bool trouve = false;
    Console.WriteLine("Veuillez saisir un nombre compris entre 0 et 100 (exclu)");
    while (!trouve)
    {
        string saisie = Console.ReadLine();
        int valeurSaisie;
        if (int.TryParse(saisie, out valeurSaisie))
        {
            if (valeurSaisie == valeurATrouver)
                trouve = true;
            else
            {
                if (valeurSaisie < valeurATrouver)
                    Console.WriteLine("Trop petit ...");
                else
                    Console.WriteLine("Trop grand ...");
            }
            nombreDeCoups++;
        }
        else
            Console.WriteLine("La valeur saisie est incorrecte, veuillez recommencer ...");
    }
    Console.WriteLine("Vous avez trouvé en " + nombreDeCoups + " coup(s)");
}