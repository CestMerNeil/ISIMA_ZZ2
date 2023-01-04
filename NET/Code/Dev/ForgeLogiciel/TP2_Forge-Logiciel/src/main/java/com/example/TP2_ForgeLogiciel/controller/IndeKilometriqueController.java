package com.example.TP2_ForgeLogiciel.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.example.TP2_ForgeLogiciel.service.IndeKilometriqueService;
import com.example.TP2_ForgeLogiciel.*;

import javax.websocket.server.PathParam;

@RestController
@RequestMapping("/indeKilo")
public class IndeKilometriqueController {


    @GetMapping("/{kilo}")
    public double indeKilo(@PathParam("kilo") Double kilo) {
        return IndeKilometriqueService.getPrice(kilo);
    }
}
