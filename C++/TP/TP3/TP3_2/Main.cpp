#include "Hello.hpp"

int main(int, char **){
    Mere m;
    Mere mere("TOTO");
    mere.getName();

    m.setName(5);
    m.afficher();

    Fille fu("TUTU");
    fu.setName(6);
    fu.setName("CHLOE");
    fu.afficher();
    fu.getName();
    fu.getComputer();

    return 0;
}