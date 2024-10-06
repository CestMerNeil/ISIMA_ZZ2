/** @file TP3_XIE.sql
 * @brief       TP3 for lesson Developement Database
 * @author      Ao XIE
 * @date        2023.02.19
 * @version     2.0
 * @copyright   Copyright (c) 2023 XIE Ao. All rights reserved.
 *****************************************************************
 * @attention
 * Development environment: macOS Ventura 13.2.1
 * @par Modification log:
 * <table>
 * <tr><th>Date        <th>Version  <th>Author    <th>Description
 * <tr><td>2023/02/19  <td>2.0      <td>Ao XIE  <td>Finished at home
 * <tr><td>2023/02/xx  <td>1.0      <td>Ao XIE  <td>Part done in the course
 * </table>
 ******************************************************************
 */

/******************************************************************
 * @todo    Part of <Package>                                     *
 * @auther  Ao XIE                                                *
 ******************************************************************/
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

/******************************************************************
 * @todo    Part of <Trigger>                                     *
 * @auther  Ao XIE                                                *
 ******************************************************************/

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