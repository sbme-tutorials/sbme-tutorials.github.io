---
layout: page
title:  "Basics of C++ and Git"
by: "Asem"
---

* TOC
{:toc}

## Introduction

## Variables and Collections

### Variables

### Plain Data Types (PDT) in C++

* `bool`: boolean variable holds logical value (i.e `true` or `false`), it occupies **1 byte** of memory.
* `char`: a character (e.g `'a'`,`'b'`,..) , it occupies **1 byte** of memory.
* `int`: an integer (e.g ...,-1,0,1,2,..), it occupies **4 bytes** of memory (for 64-bit machines).
* `float`: a real-number-like (e.g 0.5, 3.141, 9.81), it occupies **4 bytes** of memory.
* `double`: it is like float, but higher precision, occupies **8 bytes** of memory.
* pointers: it holds an address of a variable in memory, occupies **8 bytes** of memory (for 64-bit machines).
* references: an alias to a variable (same entity, but different name/label).

Short story: pointers and references are made to make life easier and flexible when controlling variables as we will see later in this course.

### Collections of Variables (Data Structures)

<!-- 
Show an array of floats representing an ECG signal. 
Show a linked-list of tasks.
Show a tree of life.
-->

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

## Basic Operations on Plain Data Types (PDT)

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

Note: `std::cout` is a function used to print PDT variables into the terminal/console. Wait!! What is `std::`? Well, you can write your own functions and make them callable inside a `namespace`. Consider `namespace` feature as a way to organize functions into categories. C++ is shipped with a big library of functions, called **Standard Template Library (STL)**. If you need to use a function from the the C++ **STL** just indicate the `std` as a `namespace` when you call a function from **STL**. **Don't panic if you feel uncomfotable! everything is going to be clear incrementally.**

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

### Scopes and Lifetime {% cite stroustrup2013tour %}

Variables bound to scopes where they are declared. Scopes types:

* Local scope: any variable declared in a function is not accessible outside the function.
* Block: any variable declared inside braces `{` `}`, like the blocks of the `for`, `while`, `if`, `else if`, `else`, and `switch`-`case`.
* `Namespace` scope.

Otherwise, if variable is declared outside the mentioned scopes, then it is a global variable. Global variables are accessible anywhere in the source file.

#### Example of a local scope and a block scope

{% highlight c++ %}
double squareArea( double width , double height )
{
  double area = width * double;
  return area;
}

int main() 
{

}

{% endhighlight %}

#### Example of namespace scope

## C++ Programs



### Boiler-plate codes

### Writing your first application

### Hello, world

### Task 1: Basic C++ operations

## References

{% bibliography --cited %}
