DECLARE
CURSOR c IS SELECT sal,empno,ename FROM emp WHERE (nvl(sal,0) + nvl(comm,0) > 2000);
r_emp c%ROWTYPE;
BEGIN
	FOR r_emp IN c LOOP
		INSERT INTO tempo values (r_emp.sal,r_emp.empno,r_emp.ename);
	END LOOP;
END;
/
