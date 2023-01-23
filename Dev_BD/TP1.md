# TP 1 Dev_BD


```sql
INSERT INTO emp VALUES (7000, 'XIE', 'SALESMAN', 7566, to_date('17-12-1980', 'dd-mm-yyyy'), 2200, NULL, 20);
Commit;
```
## Exemple of PL/Sql
```sql
DECLARE
    v_nbFilms       INTEGER;
    v_nbArtistes    INTEGER;

BEGIN
    SELECT COUNT(*) INTO v_nbFilms FROM Film;
    SELECT COUNT(*) INTO v_nbArtistes FROM Artiste;

    DBMS_OUTPUT.PUT_LINE ('Nombre de Films: ' || v_nbFilms);
    DBMS_OUTPUT.PUT_LINE ('Nombre d''artistes: ' || v_nbArtistes);

    EXCEPTION
        WHEN OTHERS THEN
            DBMS_OUTPUT.PUT_LINE('Promblème rencontré dans StatsFilms');

END;
/
```

## Question 2 TP 1

```sql
DECLARE
    i INTEGER;
BEGIN

    FOR i IN 1..30 
    LOOP
        IF MOD(i, 2)=0 THEN
            INSERT INTO Temp VALUES(i, i*100, i||'est paire');
        ELSE
            INSERT INTO Temp VALUES(i, i*100, i||'est impair');
        END IF;
    END LOOP;
END;
/

```
## Question 3 TP 1
```sql
DECLARE
        i INTEGER;
BEGIN
    SELECT FROM Emp 
    WHERE 
```


