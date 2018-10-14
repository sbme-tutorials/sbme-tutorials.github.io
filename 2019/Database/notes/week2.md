---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: home
category: "coursepage"
course: "sbe403a"
year: "2019"
---
* TOC
{:toc}

# Tutorial 2
This week we will dive a little bit deeply for the previously explained SQL statements.

## Select statement

we usually retrieve the data using select statement where we can retrieve one , or or all columns from a certain table

### LIMIT

LIMIT is used along with the selection to restrict it to a certain number of top rows from the table.

```
SELECT column_name(s)
FROM table_name
WHERE condition
LIMIT number; 
```
it could also be used without a condition.

### Min , Max , Count , Avg , Sum
MAX/MIN : returns minimum or maximum value in the selected column and it could be used on a subset satisfies a conditions.
```
SELECT MAX/MIN(column_name)
FROM table_name
WHERE condition;   /* optional */
```

Count : used to retrieve the number of rows that matches the criteria if exists.

```
SELECT COUNT(column_name)
FROM table_name
WHERE condition; /* optional */
```

Average : returns the average of a numeric column

```
SELECT AVG(column_name)
FROM table_name
WHERE condition; /* optional */
```

Summation : returns the sum of a specified column that matches the criteria if exists.

```
SELECT SUM(column_name)
FROM table_name
WHERE condition; /* optional */
```
### logical operators

Basic operator

| Operator        | Description     | 
| ------------- |:-------------:|
| AND     |  combine conditions with logical and in WHERE clause |
| OR     |  combine conditions with logical OR in WHERE clause |
| NOT     |  Negate operator |
| EXISTS     | used to search te presence of a row in table or a table it self      |
| ALL     | used to check wether all records satisfy the condition or not     |
| ANY     | used to check wether any records satisfy the condition or not     |
| Between     | used to search te for values in a certain range along with AND      |

More operators
**LIKE** used to search for a specified pattern in selected column usually used with text.
it uses two wildcards
1. percentage **%** represents a sequence form zero to multiple characters
2. underscore **_** represents a single character.

```
SELECT column1, column2, ...
FROM table_name
WHERE columnN LIKE pattern; 
```
Patterns: 
+ LIKE 'x%' finds any string starts with x
+ LIKE '%x' finds any string ends with x
+ LIKE '%x%' finds any string that contain s in any place
+ LIKE '_x%' finds any string have x in seconds position

**IN** operator used to check the values given found in the list or not moreover it acts like multiple **OR** statements.

```
SELECT column_name(s)
FROM table_name
WHERE column_name IN (value1, value2, ...); 
```
**AS** called aliases which acts as a renaming function to give the retrieved attribute a new name.

```
SELECT fname + lname AS Name 
WHERE condition
```

it also can be used to rename tables


## Alter statement

previously we practiced every SQL statement on its basic form what if we wants two alter attributes in a certain table.

to add new attribute for previously created table.

```
ALTER TABLE table_name
ADD column_name datatype; 
```

to drop a certain column

```
ALTER TABLE table_name
DROP COLUMN column_name; 
```

to modify datatype for a singe column

```
ALTER TABLE table_name
MODIFY COLUMN column_name datatype;
```

## SQL Constraints

used to specify rules for data in table

| Constraint    | Description |
| ------------- |:-------------:|
| NOT NULL      | Ensures that a column cannot have a NULL value |
| UNIQUE        | Ensures that all values in a column are different |
| DEFAULT        | set a default value for column |
| AUTO_INCREMENT        | auto increments records inserted into table |
| PRIMARY KEY   |  A combination of a NOT NULL and UNIQUE. Uniquely identifies each row in a table |
| FOREIGN KEY   | Uniquely identifies a row/record in another table |

SQL constraint could be specified during CREATE statement or using alter statement previously explained.
```
CREATE TABLE table_name (
    column1 datatype constraint,
    column2 datatype constraint,
    column3 datatype constraint,
    ....
);
```
**NOT NULL**

```
CREATE TABLE table_name (
    column datatype NOT NULL);
```

```
ALTER TABLE table-name MODIFY column datatype NOT NULL;
```
during the insertion we can`t neglect entering a not NULL column it will gives an error it could be solved by DEFAULT.

**UNIQUE** preferred numeric

```
 CREATE TABLE table_name (
    column datatype NOT NULL UNIQUE);
```

```
ALTER TABLE table_name 
    ADD UNIQUE (column_name);
```

**DEFAULT** value for a column

```
 CREATE TABLE table_name (
    column datatype  UNIQUE DEFAULT 'someting' );
```


Moreover about constraint next tutorial and relations.