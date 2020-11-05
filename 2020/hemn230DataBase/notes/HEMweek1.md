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
# Tutorial one
This week we will talk about DMS and a quick intro for the Basic SQL statement.

## start ampps
type the following in your browser [http://localhost/ampps/](http://localhost/ampps/)
you should see
![](../images/amppshome.png)

## ampps tour

click on phpmyadmin or just type [http://localhost/phpmyadmin/](http://localhost/phpmyadmin/) in your browser.
you should see
![](../images/phpmyadmin.png)

* on your left **new** we help you building new database
* select your database
* you can view your database structure or adding new table using **structure** tap
* SQL or Query tap to start writing  queries on your database

## Queries time

we created the table from **phpmyadmin** lets write an equivalent query.

### CREATE statement
```
CREATE TABLE table_name (
    coulumn1 datatype constraint,
    coulumn2 datatype constraint,
    coulumn3 datatype constraint,
);
```

For example

```
CREATE TABLE students(
    Fname VARCHAR(250),
    Lname VARCHAR(250),
    st_id INT NOT NULL,
    class_id INT NOT NULL,
    email VARCHAR(250)
);
```

so what are available data-types for SQL ? For MoreInfo you can visit [W3schools datatypes](https://www.w3schools.com/sql/sql_datatypes.asp)
and for constraint visit [W3schools constraint](https://www.w3schools.com/sql/sql_constraints.asp) and for sure it will be explained later on during the course.

### INSERT statement
```
INSERT INTO table_name (column1 ,
                        column2, 
                        column3 , ...) 
                        VALUES 
                        (value1 , 
                        value2, 
                        value3, ...);
```

for example (if you created the previous table):

```
INSERT INTO students (Fname, 
                    Lname,
                    st_id)
                    VALUES
                    ('Ayman',
                    'Anwar',
                    1);

```

**HINT : you don`t have to insert in all columns of the table because later we will learn how to update a certain record**

now once we inserted a record in our database how do we retrieve what is in our database

### SELECT statement

```
SELECT column1 , column2 , .... 
                FROM table_name;
```

To select all the records from the database

``` 
SELECT * from students;
```

**Question?** Take a moment and think is it practical to retrieve  all the data from the data base ?
#### where clause
used to select data that serves a particular condition.

```
SELECT column1, column2, ...
FROM table_name
WHERE condition; 
```

for examples

```
SELECT * from students
    WHERE st_id = 1;
```

logical expressions (AND , OR and NOT) could be used to join multiple conditions

```
SELECT column1, column2, ...
FROM table_name
WHERE condition1 AND condition2 OR condition3 ...; 
```

#### ORDER clause

we can order the retrieved data by any mean of a certain column values.

for example
```
SELECT Fname , Lname 
    FROM students
    ORDER BY st_id;
```


the update clause used to update the value of one , more or all database entries in a table.

### UPDATE statement

```
UPDATE table_name
    SET  column1 = value1, column2 = value2, ...
    WHERE condition;
```

for example
```
UPDATE students
    SET Fname = " plapla " , email = "plapla@sucks.com"
    WHERE st_id = 1;
```



we can delete one or more data base entry from our table controlled by a condition.

### DELETE statement

```
DELETE FROM table_name
    WHERE condition; 
```

for example
```
DELETE FROM students
    WHERE st_id IS NULL
```
