package com.modernarchi.tp2.controller;


import com.modernarchi.tp2.model.Pixel;
import com.modernarchi.tp2.store.PixelStore;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.awt.*;
import java.io.IOException;


@RestController
public class PixelArtController {

    @Autowired
    private PixelStore pixelStoreStore;


    @PostMapping(value = "/pixels")
    public void addPixel(@RequestBody AddPixelBody payload) {

        Pixel pixel = new Pixel(payload.color);

        pixelStoreStore.addPixel(payload.x, payload.y, pixel);
    }

    @GetMapping(value = "/pixels", produces = "image/png")
    public ResponseEntity<byte[]> getImage() throws IOException {
        byte[] bytes = pixelStoreStore.toImage();
        return ResponseEntity
                .ok()
                .contentType(MediaType.IMAGE_PNG)
                .body(bytes);
    }


}
