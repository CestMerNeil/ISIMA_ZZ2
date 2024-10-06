# Compte rendu TP de développement de bases de données

## TP 2

### Question 1

```sql
set serveroutput on;
DECLARE
e_nom emp.ename%type;
e_sal emp.sal%type;
e_comm emp.comm%type;
Cursor c IS SELECT ename, sal, comm FROM emp WHERE ename = 'MILLER';
BEGIN

    OPEN c;
    FETCH c INTO e_nom, e_sal, e_comm;
    dbms_output.put_line('nom : ' || e_nom || ' salaire : ' || e_sal || ' commission : ' || e_comm);
    CLOSE c;
END;
/
```

Résultat :

```
nom : MILLER salaire : 1300 commission :

Procedure PL/SQL terminee avec succes.
```

### Question 2

```sql
DECLARE
i number(3);
BEGIN
    For i in 1..100 loop
        if (mod(i,2)=0) then
            INSERT INTO temp values(i, i*100, to_char(i) || ' est pair');
        else
            INSERT INTO temp values(i, i*100, to_char(i) || ' est impair');
        end if;
    end loop;
END;
/
```

Résultat :

```
Procedure PL/SQL terminee avec succes.
```

### Question 3

```sql
DECLARE
e_sal emp.sal%type;
e_empno emp.empno%type;
e_nom emp.ename%type;
Cursor c IS SELECT * FROM (SELECT sal, empno, ename FROM emp ORDER BY sal DESC) WHERE rownum <=5;
BEGIN
    FOR rec_c in c
    LOOP
        e_sal:=rec_c.sal;
        e_empno:=rec_c.empno;
        e_nom:=rec_c.ename;
        INSERT INTO temp values(e_sal, e_empno, e_nom);
    END LOOP;
END;
/
```

Résultat :

```
Procedure PL/SQL terminee avec succes.


SQL> SELECT * FROM TEMP;

  NUM_COL1   NUM_COL2 CHAR_COL
---------- ---------- ----------
      5000	 7839 KING
      3000	 7902 FORD
      3000	 7788 SCOTT
      2975	 7566 JONES
      2850	 7698 BLAKE

```

### Question 4 

```sql
DECLARE
e_sal emp.sal%type;
e_empno emp.empno%type;
e_nom emp.ename%type;
Cursor c IS SELECT sal, empno, ename FROM emp WHERE ((nvl(sal, 0) + nvl(comm, 0)) >= 2000);
BEGIN
    FOR rec_c in c
    LOOP
        e_sal:=rec_c.sal;
        e_empno:=rec_c.empno;
        e_nom:=rec_c.ename;
        INSERT INTO temp values(e_sal, e_empno, e_nom);
    END LOOP;
END;
/
```

Résultat :

```
Procedure PL/SQL terminee avec succes.


SQL> SELECT * FROM TEMP;

  NUM_COL1   NUM_COL2 CHAR_COL
---------- ---------- ---------
      2975	 7566 JONES
      1250   7654 MARTIN
      2850	 7698 BLAKE
      2450	 7782 CLARK
      3000	 7902 FORD
      3000	 7788 SCOTT
      3500	 7000 LY

8 lignes selectionnees.

```

### Question 5

```sql
set serveroutput on;
DECLARE
    Cursor c IS SELECT * FROM emp start with empno=7902 CONNECT BY PRIOR mgr=empno;
BEGIN
   FOR row_c in c
   LOOP
        if row_c.sal > 4000 or row_c.mgr is null then
            INSERT INTO temp VALUES(row_c.sal, row_c.empno, row_c.ename);
            exit;
        end if;
   END LOOP;
END;    
/
```

Résultat :
```
Procedure PL/SQL terminee avec succes.
```