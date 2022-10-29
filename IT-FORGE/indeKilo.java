public class indeKilo 
{
    public double trajet; // distance
    public double getRembourse()
    {
        double rembourse = 0;
        if(trajet < 0){
            System.out.println("Trajet error!");
        }
        else if(trajet < 10) rembourse = trajet * 1.5;
        else if(10 <= trajet && trajet < 39) rembourse = trajet * 0.4;
        else if(40 <= trajet && trajet < 60) rembourse = trajet * 0.55;
        else
        {
            rembourse = (int)trajet / 20;
            rembourse = (int)rembourse * 6.81;
        }

        return rembourse;
    }
}
