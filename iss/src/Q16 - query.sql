SELECT Fname, Lname FROM EMPLOYEE 
WHERE Dno = (SELECT Dno FROM EMPLOYEE WHERE Fname = 'John' AND Lname = 'Smith');
