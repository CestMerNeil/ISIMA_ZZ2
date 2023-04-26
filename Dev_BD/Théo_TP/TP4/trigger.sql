create or replace trigger raise_cliquot
before update of sal on emp
for each row
begin
	if :old.sal > :new.sal then
		raise_application_error(-20012, 'On ne baisse pas le salaire');
	end if;
end;
/

create or replace trigger numdept_cliquot
before insert on dept
for each row
begin
	if :new.deptno < 61 or :new.deptno > 69 then
		raise_application_error(-20046, 'Impossible');
	end if;
end;
/

create or replace trigger dept_cliquot
before insert on emp
for each row
DECLARE
	c number(2);
begin
	SELECT count(deptno) into c from dept where dept.deptno = :new.deptno;
	if c = 0 then
		INSERT INTO dept values(:new.deptno, 'A SAISIR', 'A SAISIR');
	end if;
end;
/

create or replace trigger noweek_cliquot
before insert or delete or update on emp
for each row
DECLARE
	c number;
begin
	Select to_char(sysdate, 'D') into c from DUAL;
	if c = 7 or c = 6 or c=3 then
		raise_application_error(-20666, 'Noooon');
	end if;
end;
/

--Alter trigger noweek_votrenom DISABLE;
--Alter trigger noweek_votrenom ENABLE;


create or replace trigger stat_cliquot
before insert or delete or update on emp
begin
	IF INSERTING THEN
		update stats_cliquot set NbMaj = nbMaj+1, date_derniere_maj=sysdate WHERE TypeMaj='INSERT';
	END IF;
	IF DELETING THEN
		update stats_cliquot set NbMaj = nbMaj+1, date_derniere_maj=sysdate WHERE TypeMaj='DELETE';
	END IF;
	IF UPDATING THEN
		update stats_cliquot set NbMaj = nbMaj+1, date_derniere_maj=sysdate WHERE TypeMaj='UPDATE';
	END IF;

end;
/


create or replace trigger checksal_cliquot
before update of job on emp
for each row when (old.job != 'PRESIDENT')
DECLARE
	hsal1 number;
	lsal1 number;
begin
	SELECT hsal, lsal INTO hsal1, lsal1 FROM SalIntervalle WHERE job = :new.job;
	if salok_cliquot(:new.job, :old.sal+100) = 1 then
		:new.sal := :old.sal + 100;
	else
		if :old.sal + 100 >= hsal1 then
			:new.sal := hsal1;
		else
			:new.sal := lsal1;
		end if;
	end if;

end;
/
