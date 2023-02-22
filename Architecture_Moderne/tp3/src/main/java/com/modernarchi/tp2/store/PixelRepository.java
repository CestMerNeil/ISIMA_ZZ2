package com.modernarchi.tp2.store;


import com.modernarchi.tp2.model.PixelBoard;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Component;

@Component
public interface PixelRepository extends MongoRepository<PixelBoard, String> {

}
