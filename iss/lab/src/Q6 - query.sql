use lab3;
select Dno from employee group by Dno having count(*)>2;