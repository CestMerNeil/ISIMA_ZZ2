package com.modernarchi.tp2.model;

import org.springframework.data.annotation.Id;

public class PixelBoard {

    public PixelBoard() {
    }
    public PixelBoard(String id) {
        this.id = id;
    }







    @Id
    public String id;

    public static final int SIZE = 16;

    public Pixel[][] store = new Pixel[SIZE][SIZE];


}
