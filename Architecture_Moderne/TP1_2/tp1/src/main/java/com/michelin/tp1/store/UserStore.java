package com.michelin.tp1.store;

import com.michelin.tp1.model.User;
import org.springframework.stereotype.Component;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

@Component
public class UserStore {

    public Map<Long, User> users = new HashMap<>();

    public UserStore(){
        users.put(1L, new User("joe.dalton@example.com", "Joe", "Dalton", "joe123"));
        users.put(2L, new User("william.dalton@example.com", "William", "Dalton", "joe123"));
        users.put(3L, new User("jack.dalton@example.com", "Jack", "Dalton", "joe123"));
        users.put(4L, new User("averell.dalton@example.com", "Averell", "Dalton", "joe123"));
        users.put(5L, new User("neil.xie.ao@gmail.com", "Ao", "XIE", "Neil7312"));
    }
    
    public User findById(Long id){
        return users.get(id);
    }

    public Optional<User> findByEmail(String email){
        return users.values().stream().filter(u -> u.getEmail().equals(email)).findFirst();
    }
    
}
