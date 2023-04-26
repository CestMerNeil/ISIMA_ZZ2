CREATE OR REPLACE FUNCTION salok_cliquot (job emp.job%type, salaire emp.sal%type) RETURN number
IS num emp.job%type;
BEGIN
SELECT job INTO num FROM SalIntervalle WHERE salaire > lsal AND salaire < hsal;
return (1);
EXCEPTION WHEN no_data_found THEN
  return (0);
END; 
/
