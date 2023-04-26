Create or replace package body p
AS
	Cursor emp_par_dep_votrenom(deptnoo number) return temp is
		Select empno, ename FROM emp where deptnoo = deptno;
	Procedure raise_salary_cliquot(emp_id number, amount number) is
		Begin
			raisesalary_cliquot(emp_id, amount);
		End raise_salary_cliquot;
	Procedure afficher_emp_cliquot(deptno number) is
		Begin
			For ligne in emp_par_dep_votrenom(deptno) LOOP
				dbms_output.put_line(ligne.yes || '===' || ligne.nope);
			END LOOP;
		END;
END;
/
