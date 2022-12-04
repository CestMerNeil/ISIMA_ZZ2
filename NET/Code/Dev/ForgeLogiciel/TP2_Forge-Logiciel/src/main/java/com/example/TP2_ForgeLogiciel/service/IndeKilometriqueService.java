package com.example.TP2_ForgeLogiciel.service;

import org.springframework.stereotype.Service;

@Service
public class IndeKilometriqueService {
    private double Distance;

    public void setDistance(double dis)
    {
        Distance = dis;
    }
    public double getDistance()
    {
        return Distance;
    }

    public static double getPrice(double distance)
    {
        double price = 0;
        if(distance <= 0)
        {
            System.out.println("Error, the value is not ture!");
        }
        else if(distance <= 10 && distance > 0)
        {
            price = 1.5 * distance;
        }
        else if(distance <= 40 && distance > 10)
        {
            price = (distance - 10) * 0.4 + 10 * 1.5;
        }
        else if(distance <= 60 && distance > 40)
        {
            price = (10 * 1.5) + (30 * 0.4) + (distance - 40) * 0.55;
        }
        else
        {
            price = (10 * 1.5) + (30 * 0.4) + (20 * 0.55) + (((distance - 60) / 20) + 1) * 6.81;
        }

        return price;
    }

}
