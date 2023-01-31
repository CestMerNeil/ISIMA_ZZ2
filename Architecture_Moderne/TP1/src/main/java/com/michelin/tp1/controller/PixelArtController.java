package com.michelin.tp1.controller;


import com.michelin.tp1.model.Pixel;
import com.michelin.tp1.store.PixelStore;
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

        Color color = Color.decode(payload.color);
        Pixel pixel = new Pixel(color);

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
