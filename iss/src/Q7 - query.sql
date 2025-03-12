use lab3;
select Dno, SUM(salary) AS total
from employee
group by Dno;