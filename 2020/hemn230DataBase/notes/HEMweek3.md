---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: page
category: "notes"
course: "hemn224"
year: "2020"
---
* TOC
{:toc}

# Tutorial 3
This week we will learn more about constraints along with table joins.

## PRIMARY KEY (constraints contd)
A table can have only one NOT NULL primary key which uniquely identifies records in our database bt one primary key could be made of more fields.

using CREATE statement

```
CREATE TABLE table_name (
    ID int NOT NULL,
    column_name varchar(255) NOT NULL,
    column_name int,
    PRIMARY KEY (ID)
); 
```

using ALTER

```
ALTER TABLE table_name
ADD PRIMARY KEY (column_name); 
```

## FOREIGN KEY (constraints contd)
A table can have only one NOT NULL primary key which uniquely identifies records in our database bt one primary key could be made of more fields.

using CREATE statement : here ID is a foreign key that points to a primary key in another table.

```
CREATE TABLE table_name (
    ID int NOT NULL,
    FID int NOT NULL,
    column_name varchar(255) NOT NULL,
    column_name int,
    PRIMARY KEY (ID)
    FOREIGN KEY (FID) REFERENCES other_table(column_name)
); 
```

using ALTER

```
ALTER TABLE table_name
ADD FOREIGN KEY (FKID) REFERENCES other_table(column_name); 
```

##  Adding Foreign Key Relationships

Generic syntax for FOREIGN KEYs
```
[CONSTRAINT [symbol]] FOREIGN KEY
    [index_name] (col_name, ...)
    REFERENCES tbl_name (col_name,...)
    [ON DELETE reference_option]
    [ON UPDATE reference_option]

reference_option:
    RESTRICT | CASCADE | SET NULL | NO ACTION | SET DEFAULT
```
if symbol is not existed index_name could be used.

### one to one/many relationships

Example: lets create these two tables without stating any foreign ids
```
CREATE TABLE parent (
    name VARCHAR(50),
    id INT NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE child (
    name VARCHAR(50),
    id INT,
    parentID INT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (parentID) REFERENCES parent(id)
);
```

then lets insert few records
```
INSERT INTO parent (name,id) VALUES ('ayman',1);
INSERT INTO parent (name,id) VALUES ('ahmed',2);
INSERT INTO parent (name,id) VALUES ('mohamed',3);
INSERT INTO parent (name,id) VALUES ('ali',4);
INSERT INTO parent (name,id) VALUES ('sameh',5);

INSERT INTO child (name,id,parentId) VALUES ('adam',1,1);
INSERT INTO child (name,id,parentId) VALUES ('ibra',2,2);
INSERT INTO child (name,id,parentId) VALUES ('wael',3,3);
INSERT INTO child (name,id,parentId) VALUES ('perry',4,4);
INSERT INTO child (name,id,parentId) VALUES ('nema',5,5);
```

now we built a relational model lets join both tables and look at it. BUT first what are joins.

### many to many relationships

if we redesigned the parent table to have both father and mothers where they share the same children's now its considered a many to many relationship.

so we need to build a junction table.

```
CREATE TABLE parent (
    name VARCHAR(50),
    id INT NOT NULL,
    relation varchar(50),
    PRIMARY KEY (id)
);

CREATE TABLE child (
    name VARCHAR(50),
    id INT NOT NULL,
    PRIMARY KEY (id)
);
CREATE TABLE parent_child
(
    parentID INT NOT NULL,
    child_ID INT NOT NULL,
    FOREIGN KEY (parentID) REFERENCES parent (id),
    FOREIGN KEY (child_ID) REFERENCES child (id)
);
```

lets insert few records

```
INSERT INTO parent (name,id,relation) VALUES ('Ayman',1,'is father of');
INSERT INTO parent (name,id,relation) VALUES ('ali',2,'is father of');
INSERT INTO parent (name,id,relation) VALUES ('aya',3,'is mother of');
INSERT INTO parent (name,id,relation) VALUES ('moa',4,'is mother of');

INSERT INTO child (name,id) VALUES ('perry',1);
INSERT INTO child (name,id) VALUES ('maya',2);
INSERT INTO child (name,id) VALUES ('ahmed',3);
INSERT INTO child (name,id) VALUES ('sameh',4);
INSERT INTO child (name,id) VALUES ('sally',5);

INSERT INTO parent_child (parentID,child_ID) VALUES (1,1);
INSERT INTO parent_child (parentID,child_ID) VALUES (1,4);
INSERT INTO parent_child (parentID,child_ID) VALUES (3,1);
INSERT INTO parent_child (parentID,child_ID) VALUES (3,4);
INSERT INTO parent_child (parentID,child_ID) VALUES (2,2);
INSERT INTO parent_child (parentID,child_ID) VALUES (3,3);
INSERT INTO parent_child (parentID,child_ID) VALUES (4,2);
INSERT INTO parent_child (parentID,child_ID) VALUES (4,3);

```

now lets join and view data

```
SELECT parent.name , parent.relation , child.name
FROM parent_child 
JOIN parent on parent_child.parentID = parent.id
JOIN child on parent_child.child_ID = child.id;
```
### Referential Actions:

For storage engines supporting foreign keys, MySQL rejects any INSERT or UPDATE operation that attempts to create a foreign key value in a child table if there is no a matching candidate key value in the parent table.

When an UPDATE or DELETE operation affects a key value in the parent table that has matching rows in the child table, the result depends on the referential action specified using ON UPDATE and ON DELETE subclauses of the FOREIGN KEY clause. MySQL supports five options regarding the action to be taken, listed here: 

+ CASCADE: Delete or update the row from the parent table, and automatically delete or update the matching rows in the child table. Both ON DELETE CASCADE and ON UPDATE CASCADE.

+ SET NULL: Delete or update the row from the parent table, and set the foreign key column or columns in the child table to NULL. Both ON DELETE SET NULL and ON UPDATE SET NULL **make sure that you have not declared the columns in the child table as NOT NULL**.

+ RESTRICT or NO ACTION: both of them are the same they Rejects the delete or update operation for the parent.

**RESTRICT** is the default action.


## JOIN clause

JOIN clause is used to combine rows from two or more tables, based on a related column between them.
there is must be a relation between the two tables via certain column

```
SELECT table1_name.column1, table2_name.column1, Orders.OrderDate
FROM table1_name
(JOIN TYPE) JOIN table2_name ON table1_name.someID=table2_name.someID; 
```

Different type of JOINS

| JOIN | Description |
| ------------- |:-------------:|
| INNER JOIN | Returns records that have matching values in both tables|
| LEFT (OUTER) JOIN | Return all records from the left table, and the matched records from the right table |
| RIGHT (OUTER) JOIN | Return all records from the right table, and the matched records from the left table |
| FULL (OUTER) JOIN | Return all records when there is a match in either left or right table |

Example

```
SELECT child.name ,parent.name 
FROM child 
JOIN parent ON child.parentID = parent.id 
```

## UNION clause

UNION is used to combine results form more than one select statement if there is no relation between them but it must have
same number of columns with similar datatype and consider the ordering.

```
SELECT column_name(s) FROM table1
UNION
SELECT column_name(s) FROM table2; 
```


it is funny right and not that hard **it`s safe you can do it at home**.

moreover next class ISA.