set serveroutput on;
create or replace Package p
AS
	Type temp is record(nope emp.empno%type, yes emp.ename%type);
	Cursor emp_par_dep_votrenom(deptnoo number) return temp;
	Procedure raise_salary_cliquot(emp_id number, amount number);
	Procedure afficher_emp_cliquot(deptno number);
End p;
/
