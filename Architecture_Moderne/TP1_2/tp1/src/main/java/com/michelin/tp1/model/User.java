package com.michelin.tp1.model;

public class User {

    private final String email;
    private final String firstname;
    private final String lastname;
    private final String password;

    public User(String email, String firstname, String lastname, String password) {
        this.email = email;
        this.firstname = firstname;
        this.lastname = lastname;
        this.password = password;
    }

    public String getFirstname() {
        return firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public String getEmail() {
        return email;
    }

    public boolean passwordMatch(String password){
        return this.password.equals(password);
    }
}
