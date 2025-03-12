SELECT DISTINCT E.Fname, E.Lname 
FROM EMPLOYEE E
JOIN WORKS_ON W ON E.Ssn = W.Essn
WHERE W.Pno IN (SELECT Pno FROM WORKS_ON 
                WHERE Essn = (SELECT Ssn FROM EMPLOYEE 
                             WHERE Fname = 'Franklin' AND Lname = 'Wong'))

