/*
 * @author Ao XIE
 * @date 2023.02.08 
 */

#include <iostream>
#include <string>
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_RUNNER

class Pile {
    private:
    int taille;
    int actu = 0;
    int * info[];
    public:

    Pile(int num){
        this->taille = num;
        if(num<=0){
            std::invalid_argument;
        }
    }
    Pile(){
        this->taille = 10;
    }

    char top(){
        return * info[0];
    }
    void pop(){
        info[actu] = nullptr;
        actu --;
    }
    void push(int element){
        * info[actu] = element;
        actu ++;
    }
    void empty() {
        int * info = nullptr;
    }

    int size(){
        return actu;
    }
};