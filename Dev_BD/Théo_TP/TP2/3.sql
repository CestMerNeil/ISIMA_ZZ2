DECLARE
CURSOR c IS SELECT sal,empno,ename FROM emp ORDER BY sal DESC;
r_emp c%ROWTYPE;
i number(2);
BEGIN
	OPEN c;
	FOR i IN 1..5 LOOP
		FETCH c INTO r_emp;
		INSERT INTO tempo values (r_emp.sal,r_emp.empno,r_emp.ename);


	END LOOP;
	CLOSE c;
END;
/
