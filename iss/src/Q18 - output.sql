CREATE VIEW Dept_Manager_Info AS
SELECT D.Dname AS department_name, E.Fname AS Manager_Fname, E.Lname AS Manager_Lname, E.Salary AS Manager_Salary
FROM DEPARTMENT D
JOIN EMPLOYEE E ON D.Mgr_ssn = E.Ssn;