insert into emp values (7000,'LY','SALESMAN',7566,to_date('17-
12-1980','dd-mm-yyyy'),3500,NULL,20);
Commit;

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

set serveroutput on;
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

(nvl(sal, 0) + nvl(comm, 0))

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

SELECT (nvl(sal, 0) + nvl(comm, 0)) FROM emp WHERE ename = 'MARTIN'; 
SELECT COMM FROM emp WHERE ename = 'MARTIN'; 
update emp SET COMM=1400 WHERE ename = 'MARTIN'; 