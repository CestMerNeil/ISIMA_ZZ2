
// Methode 1

static int CalculSommeEntiers(int borneMin, int borneMax)
{
    int resulat = 0;
    for (int i = borneMin; i <= borneMax; i++)
    {
        resulat += i;
    }
    return resulat;
}


// Methode 2
static double CalculMoyenne(List<double> liste)
{
    double somme = 0;
    foreach (double valeur in liste)
    {
        somme += valeur;
    }
    return somme / liste.Count;
}


// Methode 3

static int CalculSommeIntersection()
{
    List<int> multiplesDe3 = new List<int>();
    List<int> multiplesDe5 = new List<int>();

    for (int i = 3; i <= 100; i += 3)
    {
        multiplesDe3.Add(i);
    }
    for (int i = 5; i <= 100; i += 5)
    {
        multiplesDe5.Add(i);
    }

    int somme = 0;
    foreach (int m3 in multiplesDe3)
    {
        foreach (int m5 in multiplesDe5)
        {
            if (m3 == m5)
                somme += m3;
        }
    }
    return somme;
}