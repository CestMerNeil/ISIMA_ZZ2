#include <cstring>
#include <sstream>
#include <stdexcept>

#include "catch.hpp"
#include "deviant.hpp"

/*
TEST_CASE("Personne1") {
	  const char * nom = "Jeffrey Dean Morgan";
    Personne p1(nom);

    REQUIRE(nom == p1.getNom());
    
    p1.setNom("negan");
    
    REQUIRE("negan" == p1.getNom());
} */

/*
TEST_CASE("Personne2") {
    const char * nom = "Rick Grimes";
    const Personne p2(nom);

    REQUIRE(nom     == p2.getNom());
} */

/*
TEST_CASE("Personne3") {
    const Personne p3;

    REQUIRE("inconnu"    == p3.getNom());
}*/

/*
TEST_CASE("Individu1") {
    int dep = Individu::getCompteur();

    Individu    i1;
    CHECK (dep+1 == Individu::getCompteur());    
    Individu();
    CHECK (dep+2 == Individu::getCompteur());
    Individu  * pi = new Individu;
    delete   pi;
    CHECK (dep+3 == Individu::getCompteur());    
} */

/*
TEST_CASE("Individu2") {
  std::stringstream ss1, ss2;
  ss1 << Individu::getCompteur()+1;
  
  Individu i;
  std::cout << "[Test Individu2]" << std::endl;
  i.afficher(std::cout);
  std::cout << std::endl;


  i.afficher(ss2);
  REQUIRE(ss1.str() == ss2.str());
} */

/*
TEST_CASE("Personne4") {
  int nb = Individu::getCompteur()+1;
  
  Individu * i = new Personne("Carl Grimes");
  
  std::cout << "[Test Personne4]" << std::endl;
  i->afficher(std::cout);
  std::cout << std::endl;

  REQUIRE(nb == i->getId());
  delete i;
} */

/*
TEST_CASE("Personne5") {
  std::stringstream ss1, ss2;
  ss1 << "Robert Kirkman " << Individu::getCompteur()+1;

  Personne p("Robert Kirkman");
  std::cout << "[Test Personne5]" << std::endl;
  p.afficher(std::cout);
  std::cout << std::endl;

  p.afficher(ss2);
  REQUIRE(ss1.str() == ss2.str());
}
*/

/*
TEST_CASE("Individu3") {
  std::stringstream ss1, ss2;
  ss1 << Individu::getCompteur()+1;

  Individu i;
  ss2 << i;

  REQUIRE( ss1.str() == ss2.str());
} */

/*
TEST_CASE("Personne6") {
  std::stringstream ss1, ss2;
  ss1 << "Daryl Dixon " << Individu::getCompteur()+1;

  Personne p("Daryl Dixon");
  ss2 << p;

  REQUIRE( ss1.str() == ss2.str());
} */

/*
TEST_CASE("Type1") {
  Personne p;
  REQUIRE (TYPE::PERSONNE == p.getType());
} */

/*
TEST_CASE("Type2") {
  Individu * i = new Personne;
  REQUIRE (TYPE::PERSONNE == i->getType());
  delete i;
} */

/*
TEST_CASE("Exception") {
   IllegalException e;

   REQUIRE( strcmp("illegal exception", e.what()) == 0 );
}*/

/*
TEST_CASE("ExceptionType") {
  const Individu i;
  int r = 0;
  
  try {
    i.getType();
  } catch (IllegalException &e) {
     r = 2;
  } catch (...) {
     r = 1;
  }
  CHECK   (r>0); // Exception obligatoire pour passer le test
  CHECK   (r>1); // C'est mieux si c est celle que j'attends

}*/ 

/*
TEST_CASE("Ville1") {
  // voir la definition de CITE
  int   nb    = CITE.size();
  
  Personne p1("1");
  REQUIRE (nb+1 == CITE.size());
  Personne p2;
  REQUIRE (nb+2 == CITE.size());
  Individu p3;
  REQUIRE (nb+2 == CITE.size());
} */

/*
TEST_CASE("Ville2") {
  int   nb    = CITE.size();
  
  Personne * p1 = new Personne("7");
  REQUIRE (nb+1 == CITE.size());
  delete p1;
  REQUIRE (nb == CITE.size());
} */

/*
TEST_CASE("Deviant1") {
  int nb = CITE.size();

  Personne l("loic");
  Personne a("alexis");

  CHECK( nb+2 == CITE.size() );

  Deviant  zz1(l);
  zz1.setObs("19990930");
  REQUIRE( l.getId()  == zz1.getId()  );
  REQUIRE ("19990930" == zz1.getObs() );

  Deviant  zz2(a, "20160930");
  REQUIRE( a.getId()  == zz2.getId()  );
  REQUIRE ("20160930" == zz2.getObs() );
  
  REQUIRE (nb == CITE.size());
} */

/*
TEST_CASE("Deviant2") {
  Personne l("loic");
  Personne a("alexis");

  Deviant  zz1(a, "20160930");
  Deviant  zz2(l, "19990930");

  REQUIRE (zz2 < zz1 );
} */

/*
TEST_CASE("Type3") {
  Individu * i = new Deviant(Personne("pasdebol"));
  REQUIRE (TYPE::DEVIANT == i->getType());
  delete i;
} */

/*
TEST_CASE("COVID") {
  Deviant  zz[] = { Deviant(Personne("bruno") , "19980930"), 
                    Deviant(Personne("alexis"), "20160930"), 
                    Deviant(Personne("loic")  , "19990930"), 
                    Deviant(Personne("jeremy"), "20210930") 
                   };

  Covid c;
  for (int i=0; i< 4; ++i)
     c.push(zz[i]);

   CHECK(&c.top() == &zz[3]);
   c.pop();
   CHECK(&c.top() == &zz[1]);
   c.pop();
   CHECK(&c.top() == &zz[2]);
   c.pop();
   CHECK(&c.top() == &zz[0]);
} */



