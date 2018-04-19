---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 1 - Part 1: Basics of C++"
by: "Asem"
---

* TOC
{:toc}

## Introduction

## Variables and Collections

### Variables

### Primitive Data Types (PDT) in C++

* `bool`: boolean variable holds logical value (i.e `true` or `false`), it occupies **1 byte** of memory.
* `char`: a character (e.g `'a'`,`'b'`,..) , it occupies **1 byte** of memory.
* `int`: an integer (e.g ...,-1,0,1,2,..), it occupies **4 bytes** of memory (for 64-bit machines).
* `float`: a real-number-like (e.g 0.5, 3.141, 9.81), it occupies **4 bytes** of memory.
* `double`: it is like float, but higher precision, occupies **8 bytes** of memory.
* pointers: it holds an address of a variable in memory, occupies **8 bytes** of memory (for 64-bit machines).
* references: an alias to a variable (same entity, but different name/label).

Short story: pointers and references are made to make life easier and flexible when controlling variables as we will see later in this course.

### Construction of Variables

A variable basically has:

1. **Data Type**: `int`, `char`, `bool`, ..., etc.
2. **Name**: name of the variable to be used throughout your code.
3. **Value**: the content of the variable.

Don't mix between them!

To construct a variable you need to:

1. Declare a variable (Compiler Requirement).
    * Indicate your variable **type**.
    * Indicate your variable **name** that your are going to refer later.
2. Initialize that variable (For god's sake).
    * Give it an initial value.

#### Example

First for all:

{% highlight c++ %}
// What comes after double forward-slash (//) in a line is a comment.
// Compiler Ignores comments.
// Comments are not contributing to your application logic.
// Comments are message to the readers of your code.
{% endhighlight %}

{% highlight c++ %}
// Declare a character variable.
// Variable names are not the actual value!
char x;
// What is the value of x?!
// When not initialized, x will hold a value from garbage.

// Please, always initialize your variables.

// Declaration of character with initializng to 's'.
char x = 's';

// Declaration of float whith initializing to 3.1415.
float pi = 3.1415;


// If no interesting value to initialize your variable with, initialize with 0.
int k = 0;

// You can initialize a variable with the value of another variable.
int j = k;

// Another way to initialize a variable is using braces, it is up to you.
double e {2.71828};
{% endhighlight %}

One way to avoid bugs (undefined behaviour) is initializing your variables.

### Collections of Variables (Data Structures)

<!-- 
Show an array of floats representing an ECG signal. 
Show a linked-list of tasks.
Show a tree of life.
-->

### Construction of Collections (What?!)

This is what we are going to study through this course:

* Different data structures (i.e collections of elements): Array, Linked List, Stack, Queue, Tree.
* How to **construct** collections.
* How to **insert** elements to our collection.
* How to **modify** element in our collection.
* How to **delete** an element.
* How to **traverse** our collection (i.e print all its elements).
* Applying **algorithms** on our collection.
* **Searching** for an element in our collection.

## Basic Operations on Primitive Data Types (PDT)

### Arithmetic Operations

{% highlight c++ %}
int x = 12;
int y = 5;

x + y; // 17
x - y; // 7
x * y; // 60
x / y; // 2
x % y; // 2

// x = x+y
x += y; // x is now 17.

// increment: x = x+1
++x; // x is now 18.

// x = x-y
x -= y; // x is now 13.

// decrement: x = x-1
--x; // x is now 12.

double u = 12.5;
double v { 3 };

u / v;  // 4.166667
{% endhighlight %}

### Logical Operations

{% highlight c++ %}
int x = 3;
int y = 4;

// equal
x==y; // False

// not equal
x!=y; // True

// less than
x<y; // True

// greater than
x>y; // False

// less than or equal
x<=y; // True

// greater than or equal
x>=y; // False

// logical and
x == 3 && y > x; // True
x != 3 && y > x; // False
true && true; // True
5 < 10 && 13 >= 11; // True
5 % 2 == 1 || 3 / 2 > 1; // False
5 % 2 == 1 || 3 / 2.0 > 1; // True

// logical or
true || true; // True
true || false; // True
false || true; // True
false || false; // False
5 % 2 == 1 || 3 / 2 > 1; // True
{% endhighlight %}

## Basic Control Statements

### Conditions: `if`, `else if`, `else`, `switch`-`case`

{% highlight c++ %}

bool myCondition = 5 % 2 == 1 || 3 / 2 > 1;

if( myCondition )
{
  // Some operations here.
}
else
{
  // Other operations here.
}

char mark = 73;
char grade = 'D';

if( mark > 85 )
{
  grade = 'A';
}
else if( mark > 75 )
{
  grade = 'B';
}
else if( mark > 65 )
{
  grade = 'C';
}
else
{
  grade = 'D';
}

int minimumGrade = 0;

switch (grade)
{
  case 'A':
  {
    minimumGrade = 85;
  } break;
  
  case 'B':
  {
    minimumGrade = 75;
  } break;
  
  case 'C':
  {
    minimumGrade = 65;
  } break;
  
  default:
  {
    minimumGrade = 85;
  } break;
}

{% endhighlight %}

### Loops: `for`, `while`

Note: `std::cout` is an object used to print primitive data type (PDT) variables into the terminal/console. Wait!! What is `std::`? Well, you can write your own functions and make them callable inside a `namespace`. Consider `namespace` feature as a way to organize functions into categories. C++ is shipped with a big library of functions, called **Standard Template Library (STL)**. If you need to use a function from the the C++ **STL** just indicate the `std` as a `namespace` when you call a function from **STL**. **Don't panic if you feel uncomfotable! everything is going to be clear incrementally.**

{% highlight c++ %}
for( int i = 0; i < 10; ++i )
{
  std::cout << i << " ";
}
// prints:0 1 2 3 4 5 6 7 8 9

int i = 0;
while( i < 10 )
{
  std::cout << i << " ";
}
// prints:0 1 2 3 4 5 6 7 8 9
{% endhighlight %}

## Functions

A function basically has:

* **Name** to be used when calling this function.
* **Return Type**: a function may return `int`, `double`, `char`, ... etc. Also, it may not return, so its return type is `void`.
* **Arguments**: the variables given to your function so it makes some operations on.
* **Definition**: the logic of your function.

### Declaration and Definition of Functions

Like variables, functions must be declared before you implement your logic in this function.

* **Declaration** a function header that indicates the function **name**, **return type**, and **arguments**.
* **Definition** is the function logic.

{% highlight c++ %}
double average( double a , double b ) // function header (Declaration)
{ // function definition (logic) goes here
  return ( a + b ) / 2;
}

double max( double a , double b ) // declaration
{ // definition
  if( a > b )
  {
    return a;
  }
  else
  {
    return b;
  }
}

int main()
{
  // Declare `x` as double and initialize it with the average of 13.5 and 21.0
  // Note the type consistency between x and the function return type.
  double x = average( 13.5 , 21.0 );

  bool y = average( 11.5 , 15.0 ); // Compiler Error, type mismatch!

  std::cout << max( 15.0 , 9.0 ) << std::endl; // prints: 15.0
}

{% endhighlight %}

Thanks to C++ Type System.

### Scopes and Lifetime

1. Variables are bound to scopes where they are declared. Scopes types:
  * Local scope: any variable declared in a function is not accessible outside that function.
  * Block: any variable declared inside braces `{` `}`, like the blocks of the `for`, `while`, `if`, `else if`, `else`, and `switch`-`case`.
  * `Namespace` scope.
2. Otherwise, if variable is declared outside the mentioned scopes, then it is a global variable. Global variables are accessible anywhere in the source file.
3. Once the scope is terminated, all variables in that scope are destructed.

#### Example of a local scope and a block scope

{% highlight c++ %}
double rectangleArea( double width , double height )
{
  // The arguments width and height are local variables to this function.
  // width, height, area are not accessible outside.

  double area = width * height;
  return area; // return by value
}

int main()
{
  // area here is completely different than area in the rectangleArea function.
  // They have the same value. But they are not same the variables.
  double area = rectangleArea( 12.9 , 2.5 );
}

{% endhighlight %}

#### Example of namespace scope

Consider a situation when you need to implement a function that computes the area of rectangle and the area of right triangle. Using the same function name `area`!

{% highlight c++ %}

// This function returns the rectangle area.
double area( double width , double height )
{
  return width * height;
}

// This function return the circle area.
// Compiler error! multiple definitions of `area` function!
double area( double base , double height )
{
  return ( base * height ) / 2;
}

int main()
{
  // which definition (logic) ?!
  double area = area( 12.9 , 2.5 );
}

{% endhighlight %}

**SOLUTION** using `namespace` feature:

{% highlight c++ %}

namespace rectangle
{
  double area( double width , double height )
  {
    return width * height;
  }
}

namespace triangle
{
  double area( double base , double height )
  {
    return ( base * height ) / 2;
  }
}

int main()
{
  double rectangleArea = rectangle::area( 12.9 , 2.5 );
  double triangleArea = triangle::area( 4.0 , 3.0 );

  std::cout << rectangleArea << std::endl << triangleArea << std::endl;
}

{% endhighlight %}

Now you have a little sense about `std::cout` and `std` Namespace.

## C++ Programs

C++ is a compiled language which means you need to install a compiler in order to generate executable files for your application.

A typical process of executable file generation is shown in this image:
![Compilation](/gallery/compile.gif)

Courtesy to this [post @Quora](https://www.quora.com/How-do-I-convert-C%2B%2B-source-code-into-software/answer/Sri-Hari-Haran-Seenivasan?share=8dc30d5b&srid=h6xMq).

### Writing C++ codes

To write a c++ source code it is recommended to use an enhanced text editors. One of the light-weight editors developed by Microsoft and released as an open-source project is [Visual Studio Code](https://code.visualstudio.com). For ubuntu 64-bit machines, download from this [link](https://code.visualstudio.com/docs/?dv=linux64_deb).

#### Installing VS Code

After downloading, open a terminal at the directory where you downloaded the package file.

{% highlight shell %}
sudo dpkg -i ./<package file>
code
{% endhighlight %}

### Boilerplate codes

Boilerplate is an interesting term used to refer to the code you write that doesn't contribute to your application logic. If you are interested in *Etymology*, you can read more on the origin of boilerplate in [wikipedia](https://en.wikipedia.org/wiki/Boilerplate_code).
In C++, you usually need to link against libraries, in particular the **STL**. In prior to use functions of other libraries or other source files in your project, you have to include the header files that contains the functions declarations to guide your compiler when you are using these functions. 

We may consider the syntax of including header files as *boilerplate* since it doesn't represent your project ideas (logic). 

### Writing your first application

Let's write our first source file to go through the process of compilation and execution. Copy the following code to your VS Code editor. Save the file as `firstApp4SBME.cpp`.

{% highlight c++ %}
#include <iostream>

namespace rectangle
{
  double area( double width , double height )
  {
    return width * height;
  }
}

namespace triangle
{
  double area( double base , double height )
  {
    return ( base * height ) / 2;
  }
}

int main()
{
  double rectangleArea = rectangle::area( 12.9 , 2.5 );
  double triangleArea = triangle::area( 4.0 , 3.0 );

  std::cout << rectangleArea << std::endl << triangleArea << std::endl;
}

{% endhighlight %}

### Compiling your code

Make sure you have the compiler installed in your machine.

{% highlight shell %}
g++ --version
{% endhighlight %}

this should print output like this:

```shell
g++ (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

Otherwise, if not installed you should see:

```shell
g++: command not found
```

To install `GCC` compiler on your machine:

{% highlight shell %}
sudo apt-get install build-essential
{% endhighlight %}

After saving your file, open a terminal in the directory you saved the source at. And write the following command:

{% highlight shell %}
g++ -o firstAppSBME firstAppSBME.cpp
{% endhighlight %}

**CONGRATULATIONS!** you have built your first application.

Execute the application:

{% highlight shell %}
./firstAppSBME
{% endhighlight %}

you should see:

```shell
32.25
6
```

