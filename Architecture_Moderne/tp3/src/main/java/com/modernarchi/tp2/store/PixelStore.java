package com.modernarchi.tp2.store;

import com.modernarchi.tp2.model.Pixel;
import com.modernarchi.tp2.model.PixelBoard;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Optional;

@Component
public class PixelStore {

    private static final int SIZE = 16;
    private static final int PIXEL_SIZE = 10;


    @Autowired
    private PixelRepository repository;
    public PixelStore() {
    }

    public void addPixel(int x, int y, Pixel pixel){
        Optional<PixelBoard> optionalBoar = repository.findById("board");
        PixelBoard board;
        if (optionalBoar.isEmpty()){
            board = new PixelBoard("board");
        } else {
            board = optionalBoar.get();
        }
        board.store[x][y] = pixel;
        repository.save(board);
    }

    public byte[] toImage() throws IOException {
        BufferedImage bi = new BufferedImage(SIZE * PIXEL_SIZE, SIZE * PIXEL_SIZE, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = bi.createGraphics();

        Optional<PixelBoard> board = repository.findById("board");
        for (int x=0; x<SIZE; x++){
            for (int y=0; y<SIZE; y++){
                Pixel pixel = board.get().store[x][y];
                if (pixel == null) continue;
                Color color = Color.decode(pixel.color);
                g.setColor(color);
                g.fillRect(x * PIXEL_SIZE ,y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE);
            }
        }

        ByteArrayOutputStream out = new ByteArrayOutputStream();
        ImageIO.write(bi, "PNG", out);
        return out.toByteArray();
    }
}
