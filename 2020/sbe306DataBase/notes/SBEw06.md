---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: page
category: "notes"
course: "sbe306a"
year: "2019"
---
* TOC
{:toc}

# Tutorial 6

## Exercises
Regard the following Relational model

![](../images/pract1.png)

### **Q1** Retrieve employees names who are working in the Research department.

* cross product:
```
SELECT FNAME,LNAME
from employee,department
where DNO = DNUMBER and DNAME = 'Research'
```
* JOIN Query:
```
SELECT FNAME,LNAME FROM 
employee JOIN department ON DNO = DNUMBER 
Where DNAME = 'Research'
```

### **Q2** Retrieve project names where the last name of the department manager is Wong

* cross product:
```
SELECT PNAME
from employee,department,project
where DNUM = DNUMBER and MGRSSN = SSN and LNAME = "Wong"
```

* JOIN Query:
```
SELECT PNAME from 
employee JOIN department ON MGRSSN = SSN
JOIN project ON DNUM = DNUMBER 
WHERE LNAME = "Wong"
```

### **Q3** Retrieve managers names having projects in 'Stafford'

* cross product:
```
SELECT FNAME,LNAME
from employee,department,project
where DNUM = DNUMBER and MGRSSN = SSN and Plocation = "Stanfford"
```

* JOIN Query
```
SELECT FNAME,LNAME from 
employee JOIN department ON MGRSSN = SSN 
JOIN project ON DNUM = DNUMBER 
WHERE Plocation = "Stanfford"
```

### **Q4** Retrieve the names of all employees in ‘Research’ department who work
more than 10 hours per week on theProductX project.

```
select FName,MINIT,LNAME
from employee join works_on on ESSN = SSN join project on PNO = PNUMBER join department on DNO =
DNUMBER
where DNAME = ‘Research’ and PName = 'ProductX' and hours>10;
OR
Select FNAME,MINIT,LNAME
From employee,works_on,project,department
Where ESSN = SSN and PNUMBER = PNO and DNO = Dnumber and DName = ‘Research’ and Hours > 10 and
PNAME = 'ProductX';
```

### **Q5** List the names of all employees who have a dependent with the same first
name as themselves.

```
select FNAME, MINIT, LNAME
from employee join dependent on ESSN =ssn
where FNAME = DEPENDENT_NAME;
```

### **Q6** For each project, list the project name and the total hours per week (by all
employees) spent on that project.

```
select PNAME, sum(HOURS)
from project join works_on on PNO = PNUMBER
group by PNAME;
```

### **Q7** Retrieve the names of all employees who do not work on any project.

```
select Fname
from employee
where SSN not in (select SSN from employee, works_on
where SSN = ESSN );
```

### **Q8** Retrieve project names where the department manager last name is Wong or project names where employee smith is working in.

* Nested Query
```
SELECT PNAME
from project
where PNUMBER in
(SELECT PNUMBER from employee
JOIN department on MGRSSN = SSN
JOIN project on DNUM = DNUMBER
where LNAME = "Wong" )
or PNUMBER in (SELECT PNUMBER from employee
JOIN works_on on ESSN = SSN
JOIN project on PNO = PNUMBER
where LNAME = "Smith" )
```

* Union Clause
```
SELECT Pname from
project JOIN JOIN department on DNUM = DNUMBER
JOIN employee ON MGRSSN = SSN
WHERE Lname= "Wong"
UNION
SELECT Pname from
project JOIN works_on on Pnumber = Pno
JOIN employee on SSN = ESSN
WHERE Lname= "Smith"
```

