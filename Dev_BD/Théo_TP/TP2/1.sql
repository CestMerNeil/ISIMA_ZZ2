set serveroutput on
DECLARE
n emp.empno%type;
BEGIN
SELECT empno INTO n FROM emp WHERE ename = 'MILLER';
dbms_output.put_line('num' || n);
COMMIT;
END;
/
