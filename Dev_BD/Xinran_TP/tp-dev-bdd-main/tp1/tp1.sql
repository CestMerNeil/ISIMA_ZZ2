CREATE TABLE Auteurs (
    Num INT,
    Nom VARCHAR(100),
    Prenom VARCHAR(100),
    Pays VARCHAR(2),
    Tel VARCHAR(10)
); 
--- réponse : table creee

CREATE TABLE Ouvrage (
    Code INT,
    Titre VARCHAR(100),
    Prix FLOAT
); 
--- réponse : table creee

--- pour charger le fichier, écrire dans le shell : $ORACLE_HOME/bin/sqlldr sily/tiger tp1.ctl
--- réponse :   2 Rows successfully loaded. Check the log file: tp1.log for more information about the load.

INSERT INTO Ouvrage VALUES (001, 'Intro aux BD', 260);
INSERT INTO Ouvrage VALUES (002, 'Journal de Bolivie', NULL);
INSERT INTO Ouvrage VALUES (003, 'L''homme aux sendales', NULL);
--- réponse : 1 ligne creee.

CREATE TABLE Auteur_exceptions (
    Num INT,
    Nom VARCHAR(100),
    Prenom VARCHAR(100),
    Pays VARCHAR(2),
    Tel VARCHAR(10)
); 

@$ORACLE_HOME/rdbms/admin/utlexcpt.sql ---créer la table exceptions
RENAME exceptions TO aut_violation;
ALTER TABLE Auteurs ADD CONSTRAINT Auteurs_primary_key PRIMARY KEY(num) EXCEPTIONS INTO exceptions;

ERREUR a la ligne 1 :
ORA-02437: impossible de valider (SILY.AUTEURS_PRIMARY_KEY) - violation de la
cle primaire

ROW_ID
------------------
OWNER
--------------------------------------------------------------------------------
TABLE_NAME
--------------------------------------------------------------------------------
CONSTRAINT
--------------------------------------------------------------------------------
AABg/NAANAAAUlmAAA
SILY
AUTEURS
AUTEURS_PRIMARY_KEY

ALTER TABLE Auteurs ADD CONSTRAINT AUTEURS_UPPER_NAME CHECK(UPPER(Nom)=Nom ) EXCEPTIONS INTO aut_violation;

ERREUR a la ligne 1 :
ORA-02293: impossible de valider (SILY.AUTEURS_UPPER_NAME) - violation d'une
contrainte de controle

ALTER TABLE Auteurs DROP CONSTRAINT Auteurs_Upper_Name;