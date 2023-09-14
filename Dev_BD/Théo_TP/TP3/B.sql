set serveroutput on;
DECLARE
CURSOR c IS SELECT table_name FROM user_tables WHERE table_name NOT LIKE('%_OLD');
c_tab c%ROWTYPE;
req varchar2(200);
num number(10);
BEGIN 
	FOR c_tab in c loop
		SELECT COUNT(table_name) INTO num FROM user_tables WHERE table_name=c_tab.table_name || '_OLD';
		IF (num > 0) THEN
			req:= 'DROP TABLE ' || c_tab.table_name || '_OLD';
			dbms_output.put_line(req);
			execute immediate req;
			commit;
		END IF;
		req:='CREATE TABLE ' || c_tab.table_name ||  '_OLD as SELECT * FROM ' || c_tab.table_name;
		dbms_output.put_line(req);
		execute immediate req;
		commit;
	END LOOP;
END;
/
