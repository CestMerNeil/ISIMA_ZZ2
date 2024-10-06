```
create table SalIntervalle_F2 (job varchar2(9), lsal number(7,2), hsal number(7,2)); 
insert into SalIntervalle_F2  values (‘ANALYST’, 2500, 3000) ; insert into SalIntervalle_F2  values (‘CLERK’, 900, 1300) ; 
insert into SalIntervalle_F2  values (‘MANAGER’, 2400, 3000) ; insert into SalIntervalle_F2  values (‘PRESIDENT’, 4500, 4900) ; insert into SalIntervalle_F2  values (‘SALESMAN’, 1200, 1700) ; 
```

# Function in Oracle

## Add function
### Template of addition
```sql
CREATE [OR REPLACEC] FUNCTION function_name
    [ (parameter [, parameter])]

    return return_datatype

IS | AS
    [declaration_section]

BEGIN
    executable_section

[EXCEPTION
    exception_section]

END [function_name];
```

### Example
```sql
CREATE OR REPLACE Function FindCourse
    ( name_in IN carchar2 )
    RETURN number
IS
    cnumber number;
    
    cursor c1 is
    SELECT course_number
        FROM courses_tb1
        WHERE course_name = name_in;
BEGIN

    open c1;
    fetch c1 into cnumber;

    if c1%notdound then
        cnumber := 9999;
    end if;

    close c1;
RETURN cnumber;

EXCEPTION
WHEN OTHERS THEN
    raise_application_error(-20001, 'An error was encountered - '||SQLCODE||' -ERROR- ' ||SQLERRM);
END;
/
```

## Delete a function 
### Template of delete

```sql
DROP FUNCTION function_name;
```
### Example
```sql
DROP FUNCTION FindCourse;
```

# For the question A
```sql
BEGIN
    CREATE OR REPLACE FUNCTION salok_XIE
        (searcjJob salaire)
        return number
    IS
        back NUMBER :=1;
    BEGIN
        SELECT Isal from SalIntervalle
        WHERE job = searchJob;
        IF Isal > salaire THEN
            back := 0;
        SELECT hsal from SalIntervalle
        WHERE job = serachJob;
        if hsal < salaire THEN
            back := 0; 
    RETURN back;
END;
/

```

```sql
DECLARE


BEGIN

```