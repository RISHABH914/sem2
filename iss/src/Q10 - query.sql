use lab3;
select Dno, MAX(salary) as highest_salary
from employee
group by Dno;