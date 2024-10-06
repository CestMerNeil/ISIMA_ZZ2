CREATE OR REPLACE Package Body package_tp4_ly AS
    Cursor emp_par_dep_ly (x_deptno emp.deptno%type) return EmpType IS
        SELECT empno, ename FROM emp WHERE deptno = x_deptno; 
    Procedure raisesalary_ly (x_emp_id emp.empno%type, x_amount emp.sal%type) IS
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
            else
                raise_application_error(-20001,'salary is too high');
            end if;
        End raisesalary_ly;
    Procedure afficher_emp_ly (x_deptno emp.deptno%type) IS
        Cursor c IS SELECT empno, ename FROM emp WHERE deptno = x_deptno;
        Begin
            FOR row_c in c
            LOOP
                dbms_output.put_line('numero employe : '|| row_c.empno || '     nom employe : ' || row_c.ename);
            END LOOP;
        end afficher_emp_ly;

END package_tp4_ly;
/