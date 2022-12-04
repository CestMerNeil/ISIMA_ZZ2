package com.example.TP2_ForgeLogiciel.service;

import com.example.TP2_ForgeLogiciel.service.IndeKilometriqueService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class indeKilometriqueTests {

    @Autowired
    IndeKilometriqueService indeKilometriqueService;

    /*
    @Test
    public void test()
    {
        indeKilometriqueService.setDistance(-10);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");

        indeKilometriqueService.setDistance(0);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");

        indeKilometriqueService.setDistance(0.1);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");

        indeKilometriqueService.setDistance(17.123);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");

        indeKilometriqueService.setDistance(39.5);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");

        indeKilometriqueService.setDistance(61);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");

        indeKilometriqueService.setDistance(81);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");

        indeKilometriqueService.setDistance(99);
        System.out.println("Price for "+indeKilometriqueService.getDistance() + "km is " + indeKilometriqueService.getPrice() + " euros");
    }
    */

    /*
    @Test
    public double TestWeb(double dis){
        indeKilometriqueService.setDistance(dis);
        return indeKilometriqueService.getPrice(100.0);
    }
    */

}
