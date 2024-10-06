DECLARE
/*CURSOR c IS SELECT sal,empno,ename FROM emp WHERE empno IN (SELECT empno FROM emp START WITH empno = 7902 CONNECT BY empno = prior mgr) AND sal > 4000;
r_emp c%ROWTYPE;*/

enum emp.empno%type := 7902;
s emp.sal%type;
empname emp.ename%type;

BEGIN
/*FOR r_emp IN c LOOP
		INSERT INTO tempo values (r_emp.sal,0,r_emp.ename);
	END LOOP;*/

	LOOP
		SELECT empno,sal,ename INTO enum,s,empname FROM emp WHERE empno = (SELECT mgr FROM emp WHERE empno=enum);

	if s > 4000 then
		INSERT INTO tempo values (s,0,empname);
		EXIT;
	end if; 
	END LOOP;

END;
/DECLARE
CURSOR c IS SELECT sal,empno,ename FROM emp WHERE empno IN (SELECT empno FROM emp START WITH empno = 7902 CONNECT BY empno = prior mgr) AND sal > 4000;
r_emp c%ROWTYPE;
BEGIN
	FOR r_emp IN c LOOP
		INSERT INTO tempo values (r_emp.sal,0,r_emp.ename);
	END LOOP;
END;
/
