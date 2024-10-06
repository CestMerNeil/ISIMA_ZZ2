/**
  * Pour executer une BD -> exec package.procedure(...)
  *
  * Pour la question 2, faire l'executer sur la table dept.
  */

/**------------------------------------------*
  * Pour créer le procedure 
  *------------------------------------------*/
CREATE OR REPLACE Procedure emp_par_dep_XIE
(x_numdept IN dept.deptno%type, x_nomdept IN dept.dname%type, x_locdept IN dept.loc%type)
IS
BEGIN
    INSERT INTO dept VALUES(x_numdept, x_nomdept, x_locdept);
    COMMIT;
END [emp_par_dep_XIE];
/

CREATE TABLE Sal_Intervalle_XIE (job varchar2(9), lsal number(7,2), hsal number(7,2));
insert into Sal_Intervalle_XIE values ('ANALYST', 2500, 3000) ;
insert into Sal_Intervalle_XIE values ('CLERK', 900, 1300) ;
insert into Sal_Intervalle_XIE values ('MANAGER', 2400, 3000) ;
insert into Sal_Intervalle_XIE values ('PRESIDENT', 4500, 4900) ;
insert into Sal_Intervalle_XIE values ('SALESMAN', 1200, 1700) ;

CREATE OR REPLACE function salok_XIE
(x_job IN Sal_Intervalle_XIE.job%type, x_sal IN Sal_Intervalle_XIE.lsal%type)
RETURN number
IS
e_lsal Sal_Intervalle_XIE.lsal%type;
e_hsal Sal_Intervalle_XIE.hsal%type;
res number(8, 2) :=0;
Cursor c IS SELECT lsal, hsal FROM Sal_Intervalle_XIE WHERE job=x<x_job;
BEGIN
    OPEN c;
    FETCH c INTO e_lsal, e_hsal;
    CLOSE c;
    IF x_sal >= e_lsal and x_sal <= e_hsal THEN
        res := 1;
    END IF;
    RETURN (res);
END salok_XIE;
/   

CREATE OR REPLACE procedure raise_salary_XIE
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
End raise_salary_XIE;
/

/* Le salaire d’un employé ne diminue jamais. */
CREATE OR REPLACE TRIGGER raise_XIE
AFTER UPDATE OF sal ON emp
FOR EACH ROW
BEGIN
    IF(new.sal < old.sal) THEN
        raise_application_error(-20001, 'Salary is lower.');
    END IF;
END;

/* Le numéro de département doit être entre 61 - 69. */
CREATE OR REPLACE TRIGGER numdept_XIE
AFTER UPDATE OF numdept ON emp
FOR EACH ROW
BEGIN
    IF (numdept <= 61 AND numdept >= 69) THEN
        raise_application_error(-20001, 'ERROR of department.')
    END IF;
END;

/* Si un employé est affecté à un département qui n’existe pas 
dans la base de données, ce département doit être rajouté avec 
pour valeur « A SAISIR » pour les attributs Dname et Loc. */

CREATE OR REPLACE TRIGGER dept_XIE
AFTER INSERT OF dept ON emp
FOR EACH ROW 
BEGIN
    IF ()




/*****************************/
/* package */
CREATE OR REPLACE PACKAGE emp_actions AS
    TYPE Emp_n IS RECORD (emp_num Emp.Empno%type, emp_nom Emp.ename%type);
    CURSOR emp_par_dep_XIE(dept Emp.deptno%type) RETURN Emp_n;

    PROCEDURE raise_salary_XIE (emp_id IN Emp.empno%type, amount IN Emp.sal%type);
    PROCEDURE afficher_emp_XIE (dept Emp.deptno%type);
END emp_actions;
/

CREATE OR REPLACE PACKAGE BODY emp_actions AS

    CURSOR emp_par_dep_XIE(dept Emp.deptno%type) RETURN Emp_n IS SELECT Empno, Ename FROM Emp WHERE DEPTNO = dept;
    PROCEDURE afficher_emp_XIE (dept Emp.deptno%type) IS
    BEGIN
        emp_par_dep_XIE(dept);
        
    PROCEDURE raises_alary_XIE (emp_id IN Emp.empno%type, amount IN Emp.sal%type) IS
        res NUMBER := 0;
        travail Emp.job%type;
        salaire Emp.sal%type;
    Begin
        SELECT job, sal into travail, salaire FROM Emp WHERE empno = emp_id;
        salaire := salaire + amount;
        res := salok_XIE(travail, salaire);
        If res=1 THEN
            UPDATE Emp SET sal = sal + amount WHERE empno = emp_id;
            Commit;
        Else
            RAISE_APPLICATION_ERROR(-20100, 'SALAIRE HORS INTERVALLE');
        End If;
    End raisesalary_XIE;

End;
/





/* trigger */

/* Q1 */
CREATE TRIGGER raise_XIE
BEFORE UPDATE OF sal ON Emp
FOR EACH ROW
BEGIN
    If :old.sal > :new.sal THEN
        RAISE_APPLICATION_ERROR(-20101, 'SALAIRE DIMINUE');
    End If;
End;
/

/* Q2 */
CREATE OR REPLACE TRIGGER numdept_XIE
BEFORE UPDATE OR INSERT OF deptno ON Emp
FOR EACH ROW
BEGIN
    If :new.deptno > 69 or :new.deptno < 61 THEN
        RAISE_APPLICATION_ERROR(-20102, 'DEPTNO PAS ENTRE 61 ET 69');
    End If;
End;
/

/* Q3 */
CREATE OR REPLACE TRIGGER dept_XIE
BEFORE UPDATE OR INSERT OF deptno ON Emp
FOR EACH ROW
DECLARE
    c NUMBER;
BEGIN
    SELECT COUNT(deptno) INTO c FROM Dept WHERE deptno=:new.deptno;
    If c=0 THEN
        INSERT INTO Dept VALUES (:new.deptno, 'A SAISIR', 'A SAISIR');
    End If;
End;
/

/* Q4 */
CREATE OR REPLACE TRIGGER noweek_XIE
BEFORE UPDATE OR INSERT OR DELETE ON Emp
FOR EACH ROW
BEGIN
    If (TO_CHAR(SYSDATE, 'D') = '6' OR TO_CHAR(SYSDATE, 'D') = '7') THEN
        RAISE_APPLICATION_ERROR(-20103, 'PAS DE MODIF LE WE');
    End If;
End;
/

/* Q5 */
ALTER TRIGGER noweek_XIE DISABLE;

/* Q6 */
ALTER TRIGGER noweek_XIE ENABLE;

/* Q7 A */

create table STATS_XIE (TypeMaj VARCHAR2(9), NbMaj NUMBER, Date_derniere_Maj DATE);
INSERT INTO STATS_XIE VALUES ('INSERT', 0, NULL);
INSERT INTO STATS_XIE VALUES ('DELETE', 0, NULL);
INSERT INTO STATS_XIE VALUES ('UPDATE', 0, NULL);

CREATE OR REPLACE TRIGGER stat_XIE
BEFORE UPDATE OR INSERT OR DELETE ON Emp
FOR EACH ROW
DECLARE
    c NUMBER;
    v VARCHAR(9);
BEGIN
    If INSERTING THEN
        v := 'INSERT';
    End If;
    If DELETING THEN
        v := 'DELETE';
    End If;
    If UPDATING THEN
        v := 'UPDATE';
    End If;
    SELECT NbMaj INTO c FROM STATS_XIE WHERE TypeMaj=v;
    UPDATE STATS_XIE SET NbMaj= c + 1, Date_derniere_Maj =  SYSDATE WHERE TypeMaj = v;
End;
/

/* Q7 B */

UPDATE EMP SET SAL = SAL * 1.01;


CREATE OR REPLACE TRIGGER stat_XIE
BEFORE UPDATE OR INSERT OR DELETE ON Emp
DECLARE
    c NUMBER;
    v VARCHAR(9);
BEGIN
    If INSERTING THEN
        v := 'INSERT';
    End If;
    If DELETING THEN
        v := 'DELETE';
    End If;
    If UPDATING THEN
        v := 'UPDATE';
    End If;
    SELECT NbMaj INTO c FROM STATS_jl WHERE TypeMaj=v;
    UPDATE STATS_XIE SET NbMaj= c + 1, Date_derniere_Maj =  SYSDATE WHERE TypeMaj = v;
End;
/

/* Q8 */

CREATE OR REPLACE TRIGGER checksal_XIE
BEFORE UPDATE OR INSERT OR DELETE OF job ON Emp
FOR EACH ROW
DECLARE
    salmin NUMBER;
    salmax NUMBER;
    v VARCHAR(10);
BEGIN
    SELECT lsal, hsal into salmin, salmax FROM SalIntervalle_F2 WHERE job=:new.job;
    If :old.job = 'PRESIDENT' THEN
        RAISE_APPLICATION_ERROR(-20104, 'SALAIRE DEJA TRES HAUT');
    End If;
    If :old.sal+100 < salmin THEN
        :new.sal := salmin;
    End If;
    If :old.sal+100 > salmax THEN
        :new.sal := salmax;
    End If;
    If :old.sal+100 < salmax and :old.sal+100 > salmin THEN
        :new.sal := :old.sal + 100;
    End If;
End;
/
