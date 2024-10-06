CREATE table STATS_cliquot(
	TypeMaj 		  varchar(10),
	NbMaj   		  number(5),
	Date_derniere_Maj Date
);

Insert Into STATS_cliquot VALUES('INSERT', 0, NULL);
INSERT INTO STATS_cliquot VALUES('UPDATE', 0, NULL);
INSERT INTO STATS_cliquot VALUES('DELETE', 0, NULL);
