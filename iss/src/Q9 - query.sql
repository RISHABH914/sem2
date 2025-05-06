use lab3;
Select Essn from works_on group by Essn having count(Pno)>1;
