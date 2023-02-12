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



