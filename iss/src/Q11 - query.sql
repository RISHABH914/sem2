SELECT E.Fname, E.Minit, E.Lname, E.Ssn, E.Bdate, E.Address, E.Sex, E.Salary, E.Super_ssn, E.Dno, D.Dname, P.Pname 
FROM EMPLOYEE E
JOIN DEPARTMENT D ON E.Dno = D.Dnumber
JOIN WORKS_ON W ON E.Ssn = W.Essn
JOIN PROJECT P ON W.Pno = P.Pnumber;
