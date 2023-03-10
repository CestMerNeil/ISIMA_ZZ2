#include "catch.hpp"
/* #include "Dictionnaire.hpp" */
#include "ListeMotsTries.hpp"

TEST_CASE ( "ListeMT1" ) {
  ListeMotsTries liste;

  REQUIRE( 0 == liste.getNbMots() );
  liste.ajouterMot("inserer");
  REQUIRE( 1 == liste.getNbMots() );
  liste.ajouterMot("effacer");
  REQUIRE( 2 == liste.getNbMots() );
  liste.ajouterMot("ajout");
  REQUIRE( 3 == liste.getNbMots() );


  ListeMotsTries::const_iterator it = liste.debut();

  REQUIRE( *it == "ajout" ); 
  ++it;
  REQUIRE( *it == "effacer" );
  ++it;
  REQUIRE( *it ==  "inserer" );
  ++it;
  REQUIRE( it == liste.fin() );

  liste.enleverMot("effacer");
  REQUIRE( 2 == liste.getNbMots() );
  liste.enleverMot("inserer");
  REQUIRE( 1 == liste.getNbMots() );
  liste.enleverMot("ajout");
  REQUIRE( 0 == liste.getNbMots() );

  REQUIRE( liste.debut() == liste.fin() ); 
}

/* TEST_CASE ( "ListeMT2" ) {
  ListeMotsTries liste1, liste2;

  liste1.ajouterMot("essai 1 a");
  liste1.ajouterMot("essai 1 b");
  liste2.inserer(liste1.debut(), liste1.fin());

  ListeMotsTries liste3;
  liste3.ajouterMot("essai 1 b");
  liste3.ajouterMot("essai 2 a");
  liste3.ajouterMot("essai 2 c");
  liste2.inserer(liste3.debut(), liste3.fin());
} */