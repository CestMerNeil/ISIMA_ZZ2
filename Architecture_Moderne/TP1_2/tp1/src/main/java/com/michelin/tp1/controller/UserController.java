package com.michelin.tp1.controller;

import com.michelin.tp1.model.Session;
import com.michelin.tp1.model.User;
import com.michelin.tp1.store.SessionStore;
import com.michelin.tp1.store.UserStore;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
import java.util.UUID;

@RestController
public class UserController {

    @Autowired
    private UserStore userStore;

    @Autowired
    private SessionStore sessionStore;

    @GetMapping("/users/id/{id}")
    public User user(@PathVariable("id") String userId) {
        Long id = Long.parseLong(userId);
        return userStore.findById(id);
    }

    @GetMapping("/users/session/{id}")
    public User userBySession(@PathVariable("id") String sessionId) {
        UUID uuid = UUID.fromString(sessionId);
        Session session = sessionStore.findBySession(uuid);
        return session.getUser();
    }

    @PostMapping(value = "/sessions")
    public Map<String, String> signin(@RequestBody Map<String, Object> payload) {
        String email = (String)payload.get("email");
        String password = (String)payload.get("password");
        Optional<User> optionalUser = userStore.findByEmail(email);

        Map<String, String> result = new HashMap<>();
        if (optionalUser.get().passwordMatch(password)){
            UUID uuid = sessionStore.createForUser(optionalUser.get());
            result.put("session", uuid.toString());
        }
        return result;
    }

}
