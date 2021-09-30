
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT

BEGIN
DECLARE
 M INT;
 set M=N-1;
  RETURN (
      select distinct salary from employee as e1 where 
         M=(select count(distinct salary) from employee as e2 where
          e2.salary>e1.salary)
  );
END