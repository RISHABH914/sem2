SELECT D.Dname as department_name, E.Fname as manager_fname, E.Lname as manager_lname
FROM DEPARTMENT D
JOIN EMPLOYEE E ON D.Mgr_ssn = E.Ssn;