package com.michelin.tp1.store;

import com.michelin.tp1.model.Session;
import com.michelin.tp1.model.User;
import org.springframework.stereotype.Component;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

@Component
public class SessionStore {

    public Map<UUID, Session> store = new HashMap<>();

    public UUID createForUser(User user){
        Session session = new Session(user);
        UUID key = UUID.randomUUID();
        store.put(key, session);
        return key;
    }
    
    public Session findBySession(UUID sessionId){
        return store.get(sessionId);
    }


}
