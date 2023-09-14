package com.modernarchi.tp2.store;

import com.modernarchi.tp2.model.Pixel;
import com.modernarchi.tp2.model.PixelBoard;
import org.springframework.stereotype.Component;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

import static com.modernarchi.tp2.model.PixelBoard.SIZE;

@Component
public class PixelStore {


    private static final int PIXEL_SIZE = 10;

    private PixelBoard pixelBoard = new PixelBoard();

    public PixelStore() {
    }

    public void addPixel(int x, int y, Pixel pixel){
        pixelBoard.store[x][y] = pixel;
    }

    public byte[] toImage() throws IOException {
        BufferedImage bi = new BufferedImage(SIZE * PIXEL_SIZE, SIZE * PIXEL_SIZE, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = bi.createGraphics();

        for (int x=0; x<SIZE; x++){
            for (int y=0; y<SIZE; y++){
                Pixel pixel = pixelBoard.store[x][y];
                if (pixel == null) continue;
                String color = pixel.color;
                g.setColor(Color.decode(color));
                g.fillRect(x * PIXEL_SIZE ,y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE);
            }
        }

        ByteArrayOutputStream out = new ByteArrayOutputStream();
        ImageIO.write(bi, "PNG", out);
        return out.toByteArray();
    }
}
