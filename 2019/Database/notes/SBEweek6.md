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
This week we will learn how we create a dynamic Web-App and Templates inheritance

## The previous clinic application

Your Directory should have the following files.
* Project folder.
   * server.py
   * templates
      * index.html
      * add.html
      * view.html

**add.html file**

```html
<!DOCTYPE html>
<html>
   <head>
      <title>Page Title</title>
   </head>

   <body>
      <a href="http://127.0.0.1:5000/adddoctor">Add doctor</a>
      <br>
      <a href="http://127.0.0.1:5000/viewdoctor">View Doctor</a>
      <br>

      <h1>Add new doctor</h1>

      <form action="http://localhost:5000/adddoctor" method="POST">
        name:<br>
        <input type="text" name="name" value="example">
        <br>
        department:<br>
        <input type="text" name="department" value="radiology">
        id<br>
        <input type="number" name="id" value="10">
        <br><br>
        <input type="submit" value="Submit">
      </form> 

      
   </body>
</html> 

```

**view.html file**

```html
<html>
   <head>
      <title>View</title>
   </head>

   <body>
      <a href="http://127.0.0.1:5000/adddoctor">Add doctor</a>
      <br>
      <a href="http://127.0.0.1:5000/viewdoctor">View Doctor</a>
      <br>

    <h1>View All Doctor</h1>

    <table>
       <tr>
          { % for r in data.header % }
          <td>{ { r } }</td>
          { % endfor % }
       </tr>
       { % for r in data.rec % }
       <tr>
          { % for l in r% }
            <td> { { l } }</td>
          { % endfor % }
       </tr>
       { % endfor % }
    </table>
   </body>
</html> 
```

**index.html**

```html
<html>
   <head>
      <title>Page Title</title>
   </head>

   <body>

      <a href="http://127.0.0.1:5000/adddoctor">Add doctor</a>
      <br>
      <a href="http://127.0.0.1:5000/viewdoctor">View Doctor</a>
      <br>

      <h1>Home Page</h1>
   </body>
</html> 
```

**server.py**

```python

import mysql.connector
from flask import Flask, redirect, url_for, request,render_template

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="mysql",
  database="MyPythonDatabase"
)
mycursor = mydb.cursor()
app = Flask(__name__)

@app.route('/')
def hello_name():
   return render_template('index.html')

@app.route('/adddoctor',methods = ['POST', 'GET'])
def adddoctor():
   if request.method == 'POST': 
      name = request.form['name']
      department = request.form['department']
      id = request.form['id']
      print(name,department,id)
      sql = "INSERT INTO Doctors (name,department, id) VALUES (%s, %s, %s)"
      val = (name,department,id)
      mycursor.execute(sql, val)
      mydb.commit()   
      return render_template('index.html')
   else:
      return render_template('add.html')

@app.route('/viewdoctor',methods = ['POST', 'GET'])
def viewdoctor():
   if request.method == 'POST':
      return render_template('index.html')
   else:
      mycursor.execute("SELECT * FROM Doctors")
      row_headers=[x[0] for x in mycursor.description] 
      myresult = mycursor.fetchall()
      data={
         'message':"data retrieved",
         'rec':myresult,
         'header':row_headers
      }
      return render_template('view.html',data=data)

if __name__ == '__main__':
   app.run()
```

## Bootstrap

Bootstrap is an open source toolkit for developing with HTML, CSS, and JS. Quickly prototype your ideas or build your entire app with our Sass variables and mixins, responsive grid system, extensive prebuilt components, and powerful plugins built on jQuery. 

Lets use Bootstrap and enhance our home page.
**[Bootstrap Starter Template](https://getbootstrap.com/docs/4.3/getting-started/introduction/)**
```html
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>Hello, world!</title>
  </head>
  <body>

    <h1>Hello, world!</h1>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>
```

Lets modify out home page. Open index.html and replace it with the following code.
adding a boot strap [menu](https://getbootstrap.com/docs/4.3/components/navbar/) for home page.
```html
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>Clinic Application!</title>
  </head>
  <body>

   <nav class="navbar navbar-expand-lg navbar-light bg-light">
   <a class="navbar-brand" href="#">Navbar</a>
   <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
   </button>

   <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav mr-auto">
         <li class="nav-item active">
         <a class="nav-link" href="http://127.0.0.1:5000/">Home <span class="sr-only">(current)</span></a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/adddoctor">Add New Doctor</a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/viewdoctor">View Doctors</a>
         </li>
         <li class="nav-item dropdown">
         <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            Dropdown
         </a>
         <div class="dropdown-menu" aria-labelledby="navbarDropdown">
            <a class="dropdown-item" href="#">Action</a>
            <a class="dropdown-item" href="#">Another action</a>
            <div class="dropdown-divider"></div>
            <a class="dropdown-item" href="#">Something else here</a>
         </div>
         </li>
         <li class="nav-item">
         <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
         </li>
      </ul>
      <form class="form-inline my-2 my-lg-0">
         <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
         <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
      </form>
   </div>
   </nav>
   <div class="container">
    <h1>Home Page!</h1>
   </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>

```

Lets modify our add.html and view.html files to the same appearance
**add.html**: add a better looking [form](https://getbootstrap.com/docs/4.3/components/forms/) from boot strap.

```html
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>Clinic Application!</title>
  </head>
  <body>

   <nav class="navbar navbar-expand-lg navbar-light bg-light">
   <a class="navbar-brand" href="#">Navbar</a>
   <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
   </button>

   <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav mr-auto">
         <li class="nav-item active">
         <a class="nav-link" href="http://127.0.0.1:5000/">Home <span class="sr-only">(current)</span></a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/adddoctor">Add New Doctor</a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/viewdoctor">View Doctors</a>
         </li>
         <li class="nav-item dropdown">
         <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            Dropdown
         </a>
         <div class="dropdown-menu" aria-labelledby="navbarDropdown">
            <a class="dropdown-item" href="#">Action</a>
            <a class="dropdown-item" href="#">Another action</a>
            <div class="dropdown-divider"></div>
            <a class="dropdown-item" href="#">Something else here</a>
         </div>
         </li>
         <li class="nav-item">
         <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
         </li>
      </ul>
      <form class="form-inline my-2 my-lg-0">
         <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
         <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
      </form>
   </div>
   </nav>
   <div class="container">
    <h1>Add a Doctor!</h1>

    <form action="http://localhost:5000/adddoctor" method="POST">
      <div class="form-group">
        <label for="exampleInputEmail1">Name</label>
        <input name="name" type="text" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your name">
        <small id="emailHelp" class="form-text text-muted">We'll never share your data with anyone else.</small>
      </div>
      <div class="form-group">
        <label for="deptinput">Department</label>
        <input name= "department" type="text" class="form-control" id="deptinput" aria-describedby="emailHelp" placeholder="Enter your department">
      </div>
      <div class="form-group">
        <label for="idinput">ID</label>
        <input name="id" type="number" class="form-control" id="idinput" placeholder="Your ID">
      </div>

      <button type="submit" class="btn btn-primary">Submit</button>
    </form>
   </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>

```

**view.html**: add a better looking [table](https://getbootstrap.com/docs/4.3/content/tables/) from Bootstrap.
```html
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>Clinic Application!</title>
  </head>
  <body>

   <nav class="navbar navbar-expand-lg navbar-light bg-light">
   <a class="navbar-brand" href="#">Navbar</a>
   <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
   </button>

   <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav mr-auto">
         <li class="nav-item active">
         <a class="nav-link" href="http://127.0.0.1:5000/">Home <span class="sr-only">(current)</span></a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/adddoctor">Add New Doctor</a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/viewdoctor">View Doctors</a>
         </li>
         <li class="nav-item dropdown">
         <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            Dropdown
         </a>
         <div class="dropdown-menu" aria-labelledby="navbarDropdown">
            <a class="dropdown-item" href="#">Action</a>
            <a class="dropdown-item" href="#">Another action</a>
            <div class="dropdown-divider"></div>
            <a class="dropdown-item" href="#">Something else here</a>
         </div>
         </li>
         <li class="nav-item">
         <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
         </li>
      </ul>
      <form class="form-inline my-2 my-lg-0">
         <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
         <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
      </form>
   </div>
   </nav>
   <div class="container">
    <h1>View Doctors!</h1>

    <table class="table">
      <thead>
        <tr>
          <th scope="col">#</th>
          "{ % for r in data.header % }"
          <th>{ { r } }</th>
          { % endfor % } 
        </tr>
      </thead>
      <tbody>
         { % for r in data.rec % }
         <tr>
            <th>{ { loop.counter } } </th>
            { % for l in r% }
              <td> { { l } }</td>
            { % endfor % }
         </tr>
         { % endfor % }
        </tbody>
    </table>

   </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>

```

Now Run the server.py file and feel free to navigate your application.

## DRY (Don't Repeat Yourself)

The DRY or “Don’t Repeat Yourself” principle is a software development practice aimed at reducing repetition of information.
So we don't need to repeat the home page code in the add.html or view.html instead we are going to inherit from the home page and change the part to display only.

1. To inherent a base html file use the following line in top of add.htl file and view.html file 
```python
{ % extends "index.html" % }
```

2. Lets create a block in the index.html file to change the data in

**index.html**
```html
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>Clinic Application!</title>
  </head>
  <body>

   <nav class="navbar navbar-expand-lg navbar-light bg-light">
   <a class="navbar-brand" href="#">Navbar</a>
   <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
   </button>

   <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav mr-auto">
         <li class="nav-item active">
         <a class="nav-link" href="http://127.0.0.1:5000/">Home <span class="sr-only">(current)</span></a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/adddoctor">Add New Doctor</a>
         </li>
         <li class="nav-item">
         <a class="nav-link" href="http://127.0.0.1:5000/viewdoctor">View Doctors</a>
         </li>
         <li class="nav-item dropdown">
         <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            Dropdown
         </a>
         <div class="dropdown-menu" aria-labelledby="navbarDropdown">
            <a class="dropdown-item" href="#">Action</a>
            <a class="dropdown-item" href="#">Another action</a>
            <div class="dropdown-divider"></div>
            <a class="dropdown-item" href="#">Something else here</a>
         </div>
         </li>
         <li class="nav-item">
         <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
         </li>
      </ul>
      <form class="form-inline my-2 my-lg-0">
         <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
         <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
      </form>
   </div>
   </nav>
   <div class="container">
         { % block head % }
            <h1>Home Page!</h1>
         { % endblock % }
   </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>
```

3. Modify add.html 

```html
{ % extends "index.html" % }
{ % block head % }
    <h1>Add a Doctor!</h1>

    <form action="http://localhost:5000/adddoctor" method="POST">
      <div class="form-group">
        <label for="exampleInputEmail1">Name</label>
        <input name="name" type="text" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your name">
        <small id="emailHelp" class="form-text text-muted">We'll never share your data with anyone else.</small>
      </div>
      <div class="form-group">
        <label for="deptinput">Department</label>
        <input name= "department" type="text" class="form-control" id="deptinput" aria-describedby="emailHelp" placeholder="Enter your department">
      </div>
      <div class="form-group">
        <label for="idinput">ID</label>
        <input name="id" type="number" class="form-control" id="idinput" placeholder="Your ID">
      </div>

      <button type="submit" class="btn btn-primary">Submit</button>
    </form>

{ % endblock % }
```

4. Modify view.html file

```html
{ % extends "index.html" % }
{ % block head % }
    <h1>View Doctors!</h1>

    <table class="table">
      <thead>
        <tr>
          <th scope="col">#</th>
          { % for r in data.header % }
          <th>{ { r } }</th>
          { % endfor % } 
        </tr>
      </thead>
      <tbody>
         { % for r in data.rec % }
         <tr>
            <th>{ { loop.index } } </th>
            { % for l in r% }
              <td> { { l } }</td>
            { % endfor % }
         </tr>
         { % endfor % }
        </tbody>
    </table>

{ % endblock % }

```

## Input validation

Lets validate input from add doctor tap and print success message or error

1. modify server.py to validate query
```python
import mysql.connector
from flask import Flask, redirect, url_for, request,render_template

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="mysql",
  database="MyPythonDatabase"
)
mycursor = mydb.cursor()
app = Flask(__name__)

@app.route('/')
def hello_name():
   return render_template('index.html')

@app.route('/adddoctor',methods = ['POST', 'GET'])
def adddoctor():
   if request.method == 'POST': ##check if there is post data
      name = request.form['name']
      department = request.form['department']
      id = request.form['id']
      try:
         print(name,department,id)
         sql = "INSERT INTO Doctors (name,department, id) VALUES (%s, %s, %s)"
         val = (name,department,id)
         mycursor.execute(sql, val)
         mydb.commit()   
         return render_template('add.html',message="Welcome Doctor "+name)
      except:
         return render_template('add.html',error="CouSomething Went wrong ")
   else:
      return render_template('add.html')

@app.route('/viewdoctor',methods = ['POST', 'GET'])
def viewdoctor():
   if request.method == 'POST':
      return render_template('index.html')
   else:
      mycursor.execute("SELECT * FROM Doctors")
      row_headers=[x[0] for x in mycursor.description] #this will extract row headers
      myresult = mycursor.fetchall()
      data={
         'message':"data retrieved",
         'rec':myresult,
         'header':row_headers
      }
      return render_template('view.html',data=data)

if __name__ == '__main__':
   app.run()

```
2. First add empty message and empty error to add.html fro [bootstrap](2)

```html
{ % extends "index.html" % }
{ % block head % }
    <h1>Add a Doctor!</h1>

    <form action="http://localhost:5000/adddoctor" method="POST">
      <div class="form-group">
        <label for="exampleInputEmail1">Name</label>
        <input name="name" type="text" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your name">
        <small id="emailHelp" class="form-text text-muted">We'll never share your data with anyone else.</small>
      </div>
      <div class="form-group">
        <label for="deptinput">Department</label>
        <input name= "department" type="text" class="form-control" id="deptinput" aria-describedby="emailHelp" placeholder="Enter your department">
      </div>
      <div class="form-group">
        <label for="idinput">ID</label>
        <input name="id" type="number" class="form-control" id="idinput" placeholder="Your ID">
      </div>

      <button type="submit" class="btn btn-primary">Submit</button>
    </form>
    { % if message% }
      <div class="alert alert-success" role="alert">
        { { message } }
      </div>
    { % endif % }

    { % if error% }
      <div class="alert alert-danger" role="alert">
        { { error } }
        </div>
    { % endif % }
{ % endblock % }
```

**HINT**: When using flask tags { {  , { %, % }, or } } Remove the spaces.