package com.michelin.tp1.model;

import java.time.LocalDateTime;

public class Session {

    private final User user;

    private final LocalDateTime createdAt;

    public Session(User user) {
        this.user = user;
        this.createdAt = LocalDateTime.now();
    }

    public User getUser() {
        return user;
    }
    
}
