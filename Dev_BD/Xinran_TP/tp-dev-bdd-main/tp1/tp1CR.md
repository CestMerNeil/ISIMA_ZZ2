# TP 1 de base de données

## Auteur
Sinaro LY (F2)

## Question 1
```sql
CREATE TABLE Auteurs (
    Num INT,
    Nom VARCHAR(100),
    Prenom VARCHAR(100),
    Pays VARCHAR(2),
    Tel VARCHAR(10)
); 
```

```log
table creee
```

```sql
CREATE TABLE Ouvrage (
    Code INT,
    Titre VARCHAR(100),
    Prix FLOAT
); 
```

```log
table creee
```

Pour charger le fichier, écrire dans le shell : 
`$ORACLE_HOME/bin/sqlldr sily/tiger tp1.ctl`

contenu de tp1.ctl :

```sql
LOAD DATA INFILE *
INTO TABLE Auteurs
fields terminated by ","
(Num, Nom, Prenom, Pays, Tel)
BEGINDATA
1,Dupont,Jacques,FR,0473151585
2,Durand,Marie,GB,NULL
3,Dupont,Pierre,NULL,NULL
3,Dupont,NULL,NULL,NULL
```

```
2 Rows successfully loaded. Check the log file: tp1.log for more information about the load.
```

```sql
INSERT INTO Ouvrage VALUES (001, 'Intro aux BD', 260);
INSERT INTO Ouvrage VALUES (002, 'Journal de Bolivie', NULL);
INSERT INTO Ouvrage VALUES (003, 'L''homme aux sendales', NULL);
```

```log
1 ligne creee
```

## Question 2
Pour créer la table des exceptions, on utilise la commande : `@$ORACLE_HOME/rdbms/admin/utlexcpt.sql`
La table créée se nomme `exceptions`, il faut de donc la renommer :

```sql
RENAME exceptions TO aut_violation;
```

```sql
ALTER TABLE Auteurs ADD CONSTRAINT Auteurs_primary_key PRIMARY KEY(num) EXCEPTIONS INTO exceptions;
```

```log
ERREUR a la ligne 1 :
ORA-02437: impossible de valider (SILY.AUTEURS_PRIMARY_KEY) - violation de la
cle primaire
```

```sql
SELECT * FROM aut_violation
```

```log
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
```

## Question 3

```sql
ALTER TABLE Auteurs ADD CONSTRAINT AUTEURS_UPPER_NAME CHECK(UPPER(Nom)=Nom ) EXCEPTIONS INTO aut_violation;
```

```log
ERREUR a la ligne 1 :
ORA-02293: impossible de valider (SILY.AUTEURS_UPPER_NAME) - violation d'une
contrainte de controle
```

## Question 4

```sql
ALTER TABLE Auteurs DROP CONSTRAINT Auteurs_Upper_Name;
```