SELECT E1.Fname AS Employee_Fname, E1.Lname AS Employee_Lname, 
       E2.Fname AS Supervisor_Fname, E2.Lname AS Supervisor_Lname
FROM EMPLOYEE E1
LEFT JOIN EMPLOYEE E2 ON E1.Super_ssn = E2.Ssn;
