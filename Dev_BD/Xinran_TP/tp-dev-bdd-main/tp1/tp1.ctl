LOAD DATA INFILE *
INTO TABLE Auteurs
fields terminated by ","
(Num, Nom, Prenom, Pays, Tel)
BEGINDATA
1,Dupont,Jacques,FR,0473151585
2,Durand,Marie,GB,NULL
3,Dupont,Pierre,NULL,NULL
3,Dupont,NULL,NULL,NULL