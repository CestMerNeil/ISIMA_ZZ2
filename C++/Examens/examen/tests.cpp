#include <cstring>
#include <exception>
#include <sstream>

#include "catch.hpp"
#include "ferme.hpp"

/*
TEST_CASE("Produit1") {
    const char * nom   = "lait";
    
    const Produit p(nom);

    REQUIRE( nom == p.getNom());
}

TEST_CASE("Produit2") {
    const char * n1   = "oeuf";
    const char * n2   = "oeuf";
    const char * n3   = "lait";
    
    const Produit p1(n1);
    const Produit p2(n2);
    const Produit p3(n3);

    REQUIRE(  p1.isEqual(p1));
    REQUIRE(  p1.isEqual(p2));
    REQUIRE( !p1.isEqual(p3));
}

TEST_CASE("Produit3") {
    const char * n1   = "oeuf";
    const char * n2   = "oeuf";
    const char * n3   = "lait";
    
    const Produit p1(n1);
    const Produit p2(n2);
    const Produit p3(n3);

    REQUIRE(   p1 == p1 );
    REQUIRE(   p1 == p2 );
    REQUIRE( !(p1 ==p3) );
}

TEST_CASE("Produit4") {    
    const Produit p1("oeuf");
    
    std::stringstream ss;

    std::cout << p1 << std::endl;
    ss << p1;

    REQUIRE("oeuf" == ss.str() );
}

TEST_CASE("Exception1") {
    std::exception * e = new PeutPasProduireException();
    std::string message("peut_pas_produire");

    REQUIRE(message == e->what());
    delete e;
}

TEST_CASE("Vache1") {
    const char * surnom   = "clarabelle";
    
    const Vache v(surnom);

    REQUIRE( "lait" == v.produire().getNom());
}

TEST_CASE("Vache2") {
    const char * surnom   = "clarabelle";
    std::stringstream ss;
    
    const Vache v(surnom);
    v.meugler(std::cout);
    v.meugler(ss);

    REQUIRE( "la vache clarabelle meugle" == ss.str());
}

TEST_CASE("Vache3") {
    const char * surnom   = "clarabelle";
    
    Vache v(surnom);
    v.setMalade(true);
    int result = 0;

    try{
        std::cout << "production" << v.produire().getNom() << std::endl;
    }
    catch(const PeutPasProduireException &e) {
        result = 2;
    }
    catch(const std::exception & e ) {
        result = 1;
    }
    
    REQUIRE ( result > 0);
    CHECK   ( result > 1);
} 

TEST_CASE("Poule1") {
    const char * surnom   = "dame gertrude";
    
    const Animal * p = new Poule(surnom);

    REQUIRE( "oeuf" == p->produire().getNom());
    delete p;
}

TEST_CASE("Poule2") {
    const char * surnom   = "dame gertrude";
    std::stringstream ss;
    
    const Poule * p = new Poule(surnom);
    p->glousser(std::cout);
    p->glousser(ss);

    REQUIRE( "la poule dame gertrude glousse" == ss.str());
    delete p;
}

TEST_CASE("Poule3") {
    const char * surnom   = "clarabelle";
    
    Animal * a = new Poule(surnom);
    a->setMalade(true);
    int result = 0;

    try{
        std::cout << "production" << a->produire().getNom() << std::endl;
    }
    catch(const PeutPasProduireException &e) {
        result = 2;
    }
    catch(const std::exception & e ) {
        result = 1;
    }
    
    REQUIRE ( result > 0);
    CHECK   ( result > 1);
    delete a;
} 

TEST_CASE("Animal1") {    
    int i = Animal::getCompteur();

    Vache v("vachette");

    REQUIRE( (i+1) == Animal::getCompteur() );

    Poule * p = new Poule("poulette");
    delete p;

    REQUIRE( (i+2) == Animal::getCompteur() );
}

TEST_CASE("Animal2") {    
    
    Vache v1("vachette");

    int i = Animal::getCompteur();
    Vache v2 = v1;

    REQUIRE( (i+1) == Animal::getCompteur() );
}

TEST_CASE("Communiquer1") {    

    std::stringstream ss1, ss2;

    Vache * v = new Vache("vachette");
    ((Communiquer *)v)->communiquer(ss1);
    v->meugler(ss2);

    REQUIRE( ss1.str() == ss2.str() );
    delete v;
}

TEST_CASE("Communiquer2") {    

    std::stringstream ss1, ss2;

    Poule * p = new Poule("poulette");
    ((Communiquer *)p)->communiquer(ss1);
    p->glousser(ss2);

    REQUIRE( ss1.str() == ss2.str() );
    delete p;
}

TEST_CASE("Ferme1") {    
    
    int compteur = Animal::getCompteur();

    Ferme f;

    REQUIRE( compteur == Animal::getCompteur());
}

TEST_CASE("Ferme2") {    
    
    int compteur = Animal::getCompteur();

    Ferme f;

    CHECK( 0 == f.size());

    f.acheter(new Poule("p1"));
    f.acheter(new Vache("v2"));

    CHECK( 2 == f.size());

    REQUIRE( (compteur+2) == Animal::getCompteur());
}

TEST_CASE("Ferme3") {    
    std::stringstream ss;
    Ferme f;

    f.acheter(new Poule("p1"));
    f.acheter(new Vache("v1"));

    f.nourrirAnimaux(ss);

    REQUIRE( "la poule p1 glousse\nla vache v1 meugle\n" == ss.str());
}

TEST_CASE("Ferme4") {    
    std::stringstream ss;
    Ferme f;

    f.acheter(new Poule("p1"));
    f.acheter(new Vache("v1"));
    f.acheter(new Vache("v2"));

    CHECK( 3 == f.size());

    Animal * a = f.vendre("v1");

    CHECK( 2 == f.size());

    f.nourrirAnimaux(ss);

    REQUIRE( "la poule p1 glousse\nla vache v2 meugle\n" == ss.str());
    
    delete a;
}

TEST_CASE("Ferme5") {    
    std::stringstream ss;
    Ferme f;

    f.acheter(new Poule("p1"));
    f.acheter(new Vache("v1"));
    f.acheter(new Vache("v2"));

    Animal * a = f.vendre("v5");

    CHECK( 3 == f.size());

    REQUIRE( nullptr == a);
}


TEST_CASE("Ferme6") {    
    std::stringstream ss;
    Ferme f;

    f.acheter(new Vache("clarabelle"));
    f.acheter(new Poule("dame gertrude")); // robin des bois
    f.acheter(new Vache("otis"));  // la ferme se rebelle
    f.acheter(new Vache("ferdinande")); // oups ...
    f.acheter(new Poule("audrey")); // la ferme se rebelle
    f.acheter(new Poule("henrietta")); // arlo

    CHECK( 6 == f.size());

    f.nourrirAnimaux(ss);

    REQUIRE( "la poule audrey glousse\nla poule dame gertrude glousse\n"
             "la poule henrietta glousse\nla vache clarabelle meugle\n"
             "la vache ferdinande meugle\nla vache otis meugle\n" == ss.str());
    
}

*/
