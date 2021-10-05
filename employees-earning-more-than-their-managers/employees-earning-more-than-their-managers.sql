# Write your MySQL query statement below
select e1.name "Employee"
from employee e1 ,employee e2
where e2.id=e1.managerid and e1.salary > e2.salary