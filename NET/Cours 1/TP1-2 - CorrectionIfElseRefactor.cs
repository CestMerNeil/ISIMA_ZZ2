if (DateTime.Now.DayOfWeek == DayOfWeek.Saturday ||
    DateTime.Now.DayOfWeek == DayOfWeek.Sunday ||
    (DateTime.Now.DayOfWeek == DayOfWeek.Monday && DateTime.Now.Hour < 9) ||
    (DateTime.Now.DayOfWeek == DayOfWeek.Friday && DateTime.Now.Hour >= 18))
{
    // nous sommes le week-end
    AfficherBonWeekEnd();
}
else
{
    // nous sommes en semaine
    if (DateTime.Now.Hour >= 9 && DateTime.Now.Hour< 18)
    {
        // nous sommes dans la journée
        AfficherBonjour();
    }
    else
    {
        AfficherBonsoir();
    }
}