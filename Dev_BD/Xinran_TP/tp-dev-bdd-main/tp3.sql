CREATE OR REPLACE procedure createdept_ly
(x_numdept IN dept.deptno%type, x_nomdept IN dept.dname%type, x_locdept IN dept.loc%type)
IS
Begin
    INSERT INTO  dept VALUES(x_numdept, x_nomdept, x_locdept);
    COMMIT;
End createdept_ly;
/

create table SalIntervalle_ly (job varchar2(9), lsal number(7,2), hsal number(7,2));
insert into SalIntervalle_ly values ('ANALYST', 2500, 3000) ;
insert into SalIntervalle_ly values ('CLERK', 900, 1300) ;
insert into SalIntervalle_ly values ('MANAGER', 2400, 3000) ;
insert into SalIntervalle_ly values ('PRESIDENT', 4500, 4900) ;
insert into SalIntervalle_ly values ('SALESMAN', 1200, 1700) ;

CREATE OR REPLACE function salok_ly
(x_job IN SalIntervalle_ly.job%type, x_sal IN SalIntervalle_ly.lsal%type)
RETURN number
IS
e_lsal SalIntervalle_ly.lsal%type;
e_hsal SalIntervalle_ly.hsal%type;
res number(8,2) :=0;
Cursor c IS SELECT lsal, hsal FROM SalIntervalle_ly WHERE job=x_job; 
Begin
    OPEN c;
    FETCH c INTO e_lsal, e_hsal;
    CLOSE c;
    if x_sal >= e_lsal and x_sal<=e_hsal then
        res :=1;
    end if;
    return (res);
End salok_ly;
/

Fonction creee.

ou bien on peut faire : 

variable t number
exec : t:=salok_ly('ANALYST', 2600)
print t;




CREATE OR REPLACE procedure raisesalary_ly
(x_emp_id IN emp.empno%type, x_amount IN emp.sal%type)
IS
new_sal emp.sal%type;
empjob emp.job%type;
Cursor c IS SELECT job, sal FROM emp WHERE empno=x_emp_id;
Begin
    OPEN c;
    FETCH c INTO empjob, new_sal;
    CLOSE c;
    new_sal := new_sal + x_amount;
    if (salok_ly(empjob, new_sal) = 1) then
        UPDATE emp
        SET sal = new_sal
        WHERE empno = x_emp_id;
        COMMIT;
    else
        raise_application_error(-20001,'salary is too high');
    end if;
End raisesalary_ly;
/

Procedure creee.

SQL> select * from emp where empno = 7900;

     EMPNO ENAME      JOB	       MGR HIREDATE	   SAL	     COMM     DEPTNO
---------- ---------- --------- ---------- -------- ---------- ---------- ----------
      7900 JAMES      CLERK	      7698 03/12/82	  900		          30

SQL> execute raisesalary_ly(7900, 50);

Procedure PL/SQL terminee avec succes.

SQL> select * from emp where empno = 7900;

     EMPNO ENAME      JOB	       MGR HIREDATE	   SAL	     COMM     DEPTNO
---------- ---------- --------- ---------- -------- ---------- ---------- ----------
      7900 JAMES      CLERK	      7698 03/12/82	  950		          30

SQL> execute raisesalary_ly(7900, 9999);
BEGIN raisesalary_ly(7900, 9999); END;

*
ERREUR a la ligne 1 :
ORA-20001: salary is too high
ORA-06512: a "SILY.RAISESALARY_LY", ligne 18
ORA-06512: a ligne 1

 
DECLARE
    Cursor c IS SELECT table_name FROM user_tables WHERE table_name NOT LIKE '%_OLD';
    Cursor c_old IS SELECT table_name FROM user_tables WHERE table_name LIKE '%_OLD';
BEGIN
    FOR rec_c_old in c_old
    LOOP
        EXECUTE IMMEDIATE ('DROP TABLE ' || rec_c_old.table_name); 
    END LOOP;
    COMMIT;
    FOR rec_c in c
    LOOP
        EXECUTE IMMEDIATE ('CREATE TABLE '|| rec_c.table_name || '_OLD AS SELECT * FROM ' || rec_c.table_name);
    END LOOP;
    COMMIT;
END;
/

Create table ly (id number(5)) ;
insert into ly Values (1) ;
insert into ly Values (2) ;
insert into ly Values (3) ;