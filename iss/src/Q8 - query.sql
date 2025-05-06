USE lab3;

SELECT d.Dname, COUNT(*)
FROM employee e
JOIN department d ON e.Dno = d.Dnumber
GROUP BY d.Dname;
