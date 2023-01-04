static void Main(string[] args)
{
    if (DateTime.Now.DayOfWeek == DayOfWeek.Saturday || DateTime.Now.DayOfWeek == DayOfWeek.Sunday)
    {
        // nous sommes le week-end
        AfficherBonWeekEnd();
    }
    else
    {
        // nous sommes en semaine

        if (DateTime.Now.DayOfWeek == DayOfWeek.Monday && DateTime.Now.Hour < 9)
        {
            // nous sommes le lundi matin
            AfficherBonWeekEnd();
        }
        else
        {
            if (DateTime.Now.Hour >= 9 && DateTime.Now.Hour < 18)
            {
                // nous sommes dans la journée
                AfficherBonjour();
            }
            else
            {
                // nous sommes en soirée

                if (DateTime.Now.DayOfWeek == DayOfWeek.Friday && DateTime.Now.Hour >= 18)
                {
                    // nous sommes le vendredi soir
                    AfficherBonWeekEnd();
                }
                else
                {
                    AfficherBonsoir();
                }
            }
        }
    }
}

static void AfficherBonWeekEnd()
{
    Console.WriteLine("Bon week-end " + Environment.UserName);
}

static void AfficherBonjour()
{
    Console.WriteLine("Bonjour " + Environment.UserName);
}

static void AfficherBonsoir()
{
    Console.WriteLine("Bonsoir " + Environment.UserName);
}