 
CREATE OR REPLACE procedure createdept_cliquot 
(numero_dept dept.deptno%type,dept_name dept.dname%type,localisation dept.loc%type)
IS 
num number(10);
BEGIN
SELECT COUNT(deptno) INTO num FROM dept WHERE deptno=numero_dept;
IF (num=0) THEN
	INSERT INTO dept VALUES(numero_dept,dept_name,localisation);
ELSE
	RAISE_APPLICATION_ERROR(-20025,'departement existant déjà');
END IF;
END;
/
