DECLARE
compteur number(2);
BEGIN
FOR compteur in 1..10 LOOP
	IF mod(compteur,2)=0 THEN
		INSERT INTO tempo values (compteur,compteur*100,compteur || ' est pair');
	ELSE
		INSERT INTO tempo values (compteur,compteur*100,compteur || ' est impair');
	END IF;
	
END LOOP
COMMIT;
END;
/
