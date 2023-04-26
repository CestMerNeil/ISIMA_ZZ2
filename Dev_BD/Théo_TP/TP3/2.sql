CREATE OR REPLACE PROCEDURE raisesalary_cliquot(emp_id number, amount number)
IS
BEGIN
UPDATE emp SET sal= sal+amount WHERE emp_id=empno AND 1=salok_cliquot(job,sal+amount);
END;
/
