 using System;
using System.Security.Principal;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime testDate = new DateTime(2022, 9, 26, 13, 5, 0);
            DayOfWeek dt = DateTime.Now.DayOfWeek;
            int hour = testDate.Hour;
            string currentUser = WindowsIdentity.GetCurrent().Name;
            string message = "Bonjour " + currentUser;

            switch(testDate.DayOfWeek)
            {
                case DayOfWeek.Monday:
                    {
                        if( hour >= 18 )
                        {
                            message = "Bonsoir " + currentUser;
                        }
                        else if( hour < 9 )
                        {
                            message = "Bon week-end " + currentUser;
                        }
                        break;
                    }
                case DayOfWeek.Tuesday:
                case DayOfWeek.Wednesday:
                case DayOfWeek.Thursday:
                    {
                        if( hour > 18 )
                        {
                            message = "Bonsoir " + currentUser;
                        }
                        break;
                    }
                case DayOfWeek.Friday:
                    {
                        if( hour <= 9 )
                        {
                            message = "Bonsoir " + currentUser;
                        }
                        else if( hour > 18 )
                        {
                            message = "Bon week-end " + currentUser;
                        }
                        break;
                    }
                default:
                    {
                        message = "Bon week-end " + currentUser;
                        break;
                    }
            }

            Console.WriteLine(message);
            
        }
    }
}
