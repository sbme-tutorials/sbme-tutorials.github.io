---
layout: presentation
style: laminal
highlighter: ir-black
course: "sbe201"
category: "presentation"
year: "2019"
title: "Week1: Introduction to 'Introduction to Data Structures and Algorithms (SBE201)'"
by: "Asem"
author: "Asem Alaa"
---

<!-- https://highlightjs.org/static/demo/ -->


<script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script> 

<textarea id="source" markdown="1">


class: left, middle
## Information about TA

--
* Asem Alaa
--
* e-mail: `asem.a.abdelaziz@gmail.com`
--
* Office hours and course materials are available on the course page:

.center[.blue[[{sbme-tutorials.github.io/2020/data-structures}](https://sbme-tutorials.github.io/2020/data-structures)]]

--
* Main research interests: Bioinformatics Algorithms and Machine Learning

---
class: left, middle
## Information about our course

--
* Aims to understanding various data structures by implementation from scratch.
--
* Understanding algorithms by implementation from scratch.
--
* Modern C++ is used to build our data structures and algorithms. —*.blue["What I cannot create I don't understand. R.F]"*—
--
.center[<img src="../media/feynman.jpg" style="width:42%">]

---
class: left, middle
## Information about our course (cont'd)

--
* This course doesn't aim to teach OOP nor design patterns. (Though, I recommend learning these topics after this course).
--
* We still aim to write a very clean and simple C++ code.
--
* We will also learn and practice on version control systems like git.
--
* We will learn about different topics and tools in the development ecosystem.
--
* Implementation assignment each week. 

---
class: left, middle
### Attendance

* Attendance is a requirement to pass the courses.
--
* Not showing in more than 25% of lectures or tutorials is penalized by failing in the course.

---
class: left, middle
### .red[Cheating and Academic Dishonesty] 
--
## Be it in exams or assignments

* Violating other rights and affects honest students as well.
--
* Usually correlated with other corrupted personal values.
--
* Forbidden by the religions' laws.

---
class: left, top
## Recommended Resources 
### Data structure and Algorithms
<ul class="list-unstyled" markdown="1">
--
  <li class="media">
    <a href="https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844"><img src="../media/cormen.jpg" style="height:128px;width:128px;" class="mr-3" alt="cormen"></a>
    <div class="media-body">
      <h5 class="mt-0 mb-1">Introduction to Algorithms</h5>
      <em>by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein.</em>
    </div>
  </li>
--
  <li class="media my-4">
    <a href="https://www.amazon.com/Algorithms-Sanjoy-Dasgupta/dp/0073523402"><img src="../media/gupta.jpg" style="height:128px;width:128px;"  class="mr-3" alt="cpp book"></a>
    <div class="media-body">
      <h5 class="mt-0 mb-1">Algorithms</h5>
      <em>by Sanjoy Dasgupta, Christos H. Papadimitriou, Umesh Vazirani.</em>
    </div>
  </li>
--
  <li class="media my-4">
    <a href="https://www.coursera.org/learn/data-structures"><img src="../media/coursera.png" style="height:128px;width:128px;"  class="mr-3" alt="cpp book"></a>
    <div class="media-body">
      <h5 class="mt-0 mb-1">Online course: Data Structures</h5>
      <em>by Offered By University of California San Diego and National Research University Higher School of Economics.</em>
    </div>
  </li>
</ul>


---
class: left, top
## Recommended Resources 
### C++ Programming

<ul class="list-unstyled" markdown="1">
--
  <li class="media">
    <a href="https://www.pluralsight.com/courses/cplusplus-fundamentals-c17"><img src="../media/pluralsight.png" style="height:128px;width:128px;" class="mr-3" alt="C++"></a>
    <div class="media-body">
      <h5 class="mt-0 mb-1">Online course: C++ Fundamentals Including C++ 17</h5>
      5h 48m long course, <em>by Kate Gregory.</em>
    </div>
  </li>
--
  <li class="media my-4">
    <a href="https://en.cppreference.com/w/"><img src="../media/ISO_C++_Logo.svg" style="height:128px;width:128px;"  class="mr-3" alt="cpp book"></a>
    <div class="media-body">
      <h5 class="mt-0 mb-1">Documentation: C++ Standard Documentation</h5>
      <em>by C++ committee.</em>
    </div>
  </li>
</ul>

---
class: left, top
## Recommended Resources 
### C++ Programming (cont'd)

<ul class="list-unstyled" markdown="1">
--
  <li class="media my-4">
    <a href="http://stroustrup.com/programming.html"><img src="../media/cppbook1.jpeg" style="height:128px;width:128px;"  class="mr-3" alt="cpp book"></a>
    <div class="media-body">
      <h5 class="mt-0 mb-1">Textbook: Principles and Practice Using C++</h5>
      including more than 100 pages of exercises, <em>by Bjarne Stroustrup.</em>
    </div>
  </li>
--
  <li class="media">
    <a href="https://www.amazon.com/Primer-5th-Edition-Stanley-Lippman/dp/0321714113"><img src="../media/cppbook2.jpg" style="height:128px;width:128px;"  class="mr-3" alt="cpp book"></a>
    <div class="media-body">
      <h5 class="mt-0 mb-1">Textbook: C++ Primer</h5>
      <em>by Stanley B. Lippman, Josée Lajoie, Barbara E. Moo.</em>
    </div>
  </li>
</ul>

---
class: left, middle
## The very C++ basics

* Creating variables.
* Arithmetic Operations.
* If, else if, else.
* while-for-switch-case.
* functions
* namespace


---
class: left, top
## Introduction

--
### A Simple Calculator Program and Memory Model

* Programs are all about playing with variables and groups of variables (structures)


<img style="width:80%" src="/gallery/mem.png">

---
class: left, middle
### C++

<img style="width:80%" src="/gallery/bjarne.jpg">

--
* Bjarne Stroustrup created C++.
* C++ first appeared in 1985 (35 years ago).

---
class: left, middle
### What we can build using C++

* Self-driving cars
* Games
* PDE solvers
* Banking software
* Animation software
* Financial software
* Search engines
* Navigation software 
* Social networking

---
class: left, middle
### What we can build using C++

<blockquote class="twitter-tweet"><p lang="en" dir="ltr">Our NN is initially in Python for rapid iteration, then converted to C++/C/raw metal driver code for speed (important!). Also, tons of C++/C engineers needed for vehicle control &amp; entire rest of car. Educational background is irrelevant, but all must pass hardcore coding test.</p>&mdash; Elon Musk (@elonmusk) <a href="https://twitter.com/elonmusk/status/1224182478501482497?ref_src=twsrc%5Etfw">February 3, 2020</a></blockquote> 


---
class: left, top
## Variables in C++

#### Primitive Data Types (PDT) in C++

* `bool`: holds logical value (i.e `true` or `false`), occupies **1 byte** of memory.
--
* `char`: a character (e.g `'a'`,`'b'`,..), occupies **1 byte** of memory.
--
* `int`: an integer (e.g ...,-1,0,1,2,..), occupies **4 bytes** of memory.


---
class: left, top
## Variables in C++ (cont'd)

* `std::string`: a text (e.g `"Mostafa"`, `"ACCTTG"`, etc.), occupies variable size im memory.
--
* `float`: a real-number-like (e.g 0.5, 3.141, 9.81), occupies **4 bytes** of memory.
--
* `double`: like float, but higher precision, occupies **8 bytes** of memory.
--

### Double vs float

* $ \pi $ equals: `3.14159265358979323846264338327950288419716939937510582097494459230781640628620899`
--
* $ \pi $ in `float `  variable: `3.1415927`.
--
* $ \pi $ in `double` variable: `3.1415926535897931`. 


---
class: left, top
## Variables in C++


--
* `std::vector`: collections.
--
* `enum class`: finite sets.
--
* `pointer`: next week.
--
* `reference`: next week.


---
class: left, top
### Construction of Variables

--
A variable basically has:

--
1. **Data Type**: `int`, `char`, `bool`, ..., etc.
--
2. **Name**: name of the variable to be used throughout your code.
--
3. **Value**: the content of the variable.
--
 
.red[Don't mix between them!]

---
class: left, top
#### So, to construct a variable you need to:

--
1. Declare a variable (Compiler Requirement).
    
    * Indicate your variable **type**.
    * Indicate your variable **name** that your are going to refer later.
--
2. Initialize that variable (.red[to survive undefined behaviour]).
    * Give it an initial **value**.
---

#### Example: constructing variables
--

First of all:
* Comments in C++ code.

--
```c++
// What comes after double forward-slash (//) in a line is a comment.
// Compiler Ignores comments.
// Comments are not contributing to your application logic.
// Comments are message to the readers of your code.
```

---
class: left, top
#### Cont'd


--
```c++
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
```

---
class: left, top
#### Cont'd

--
```c++
// If no interesting value to initialize 
// your variable with, initialize with 0.
int k = 0;

// You can initialize a variable with the value of 
// another variable.
int j = k;

// Another way to initialize a variable is 
// using braces, it is up to you.
double e {2.71828};
```

--
One way to avoid bugs (undefined behaviour) is initializing your variables.

--
Any Questions?


---
class: center, middle
## Overview on data structures

---
class: left, top
### Collections of Variables (Data Structures)

A data structure is a .blue[particular way of organizing data] so they can be used efficiently by some task.

#### Example 1: Data Structures in Biomedical Informatics

.center[<img style="width:30%;" src="/gallery/ecg-paper.png">]

--
* Application: analysis of ECG of the heart.

---
class: center, middle
#### Example 1: Data Structures in Biomedical Informatics (cont'd)

.center[<img style="width:30%;" src="/gallery/ecg-sampled.png">]

--
<span>$$ \text{Sampled Signal} = \[ 12.3, 12.7 , 14.5 , 18.0 , 16.2 , 10.1 , 8.6 , ... \]  $$</span>

--
* It is pointless to construct a variable for each sample!

--
.left[
```c++
double s1 = 12.3;
double s2 = 12.7;
.
.
double s256 = -0.5;
```
]
--
Instead we need to store all values and use a single name for them.


---
class: left, top
#### Example 2: Data Structures in Biomedical Informatics

Input:

| txt     | =  "AACAAGAATAACAACA" |
|---|---|
| pattern | =  "AACA" |

--
- Output: ".blue[A]ACAAGAAT.blue[A]AC.blue[A]ACA"
- Pattern found at index .blue[0,9,12]

--
Assume that we have:
* `txt` of size <span>$n = 10,000,000$</span>
* `pattern` of size <span>$m = 12$</span>
--
* No. of comparisons/steps $\approx m \times n = 120,000,000$
--
* Can we do it in only $\approx$ .blue[12 step!!]
--
* .blue[Yes!] but using special data structure like suffix trees.

---
### Data structures and basic algorithms on them

--
Mainly these what we are going to study through this course:
--
* Different data structures (i.e collections of elements): Array, Linked List, Stack, Queue, Tree.
--
* How to **construct** collections.
--
* How to **insert** elements to our collection.
--
* How to **modify** element in our collection.
--
* How to **delete** an element.
--
* How to **traverse** our collection (i.e print all its elements).
--
* Applying **algorithms** on our collection.
--
* **Searching** for an element in our collection.

---
class: center, middle
## Back to C++

---
class: left, top
### Basic Operations on Primitive Data Types (PDT)

--
* A) Arithmetic Operations.
--

```c++
int x = 12;
int y = 5;

x + y; // 17
x - y; // 7
x * y; // 60
x / y; // 2
x % y; // 2
```

---
class: left, top
### Cont'd

--
```c++
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
```

---
class: left, top
### Cont'd 

--
* B) Logical Operations


--

```c++
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
```

---
class: left, top
### Cont'd

--
```c++
// less than or equal
x<=y; // True

// greater than or equal
x>=y; // False

// logical and
x == 3 && y > x; // True
x != 3 && y > x; // False
true && true; // True
5 < 10 && 13 >= 11; // True
5 % 2 == 1 && 3 / 2 > 1; // False
5 % 2 == 1 && 3 / 2.0 > 1; // True
```
--
* Note 1: expressions are more generic unit than variables.
--
* Note 2: (`expression % 2 == 1`) is a way to test if that expression is even or odd.


---
class: left, top
### Cont'd 


```c++
// logical or
true || true; // True
true || false; // True
false || true; // True
false || false; // False
5 % 2 == 1 || 3 / 2 > 1; // True
```

---
class: left, top
### Basic Control Statements

--
* Conditions: `if`, `else if`, `else`, `switch`-`case`

```c++
bool myCondition = 5 % 2 == 1 || 3 / 2 > 1;

if( myCondition )
{
  // Some operations here.
}
else
{
  // Other operations here.
}
```

---
class: left, top
### Cont'd

```c++
char base = 'A'; char complementary = 'T';
std::cin >> base;
if( base == 'A' )
{
  complementary = 'T';
}
else if( base == 'C' )
{ complementary = 'G'; }
else if( base == 'G' )
  complementary = 'C';
else
  complementary = 'A';

std::cout << complementary << std::endl;
```

---
class: left, top
### Cont'd

```c++
char base = 'A'; char complementary = 'T';
std::cin >> base;
switch (base)
{
  case 'A':
    complementary = 'T'; break;
  case 'C': 
    complementary = 'G'; break;
  case 'G': 
    complementary = 'C'; break;
  default:
    complementary = 'A'; break;
}
std::cout << complementary << std::endl;
```

--
* `std::cout` is used to print out object values to the terminal.
--
* What is `std::` and what is `cout`?

---
class: left, top
### Loops: `for`, `while`

```c++
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
```

--
.red[Any bug?]

---
class: left, top
### Loops: `for`, `while`

```c++
for( int i = 0; i < 10; ++i )
{
  std::cout << i << " ";
}
// prints:0 1 2 3 4 5 6 7 8 9

int i = 0;
while( i < 10 )
{
  std::cout << i << " ";
  ++i;
}
// prints:0 1 2 3 4 5 6 7 8 9
```

---
class: left, top
### Functions

--
A function is a unit that you write some logic in it. So we can use that logic many times through that function.
--
A function basically has:
--
* **Name** to be used when calling this function.
--
* **Return Type**: a function may return `int`, `double`, `char`, ... etc. Also, it may not return, so its return type is `void`.
--
* **Arguments**: the variables given to your function so it makes some operations on.

---
class: left, top
### Declaration and Definition of Functions

--
Like variables, functions must be declared before you implement your logic in this function.
--
* **Declaration** is a function header that indicates the function **name**, **return type**, and **arguments**.
--
* **Definition** is the function logic.

---
class: left, top
#### Example

```c++
double average( double a , double b ) // function header (Declaration)
{ // function definition (logic) goes here
  return ( a + b ) / 2;
}

double max( double a , double b ) // declaration
{ // definition
  if( a > b )
    return a;
  else return b;
}

int main()
{
  // Define 'x' as double. Realize the type consistency.
  double x = average( 13.5 , 21.0 );
  bool y = average( 11.5 , 15.0 ); // Compiler Error, type mismatch!
  std::cout << max( 15.0 , 9.0 ) << std::endl; // prints: 15.0
}
```

---
class: left, top
### Scopes and Lifetime

--
* Variables are bound to scopes where they are declared. Scopes types:

--
1. Local scope: any variable declared in a function is not accessible outside that function.
--
2. Block: any variable declared inside braces `{}`, like the blocks of the `for`, `while`, `if`, `else if`, `else`, and `switch`-`case`.
--
3. `Namespace` scope.

--
* Once the scope is terminated, all variables in that scope are destructed.
--
* Otherwise, if variable is declared outside all of the mentioned scopes, then it is a global variable. 
--
* Global variables are accessible anywhere in the source file.

---
class: left, top
#### Example of a local scope and a block scope

```c++
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
```

---
class: left, top
#### Example of namespace scope

--
Consider a situation when you need to implement a function that computes the area of rectangle and the area of right triangle. Using the same function name `area`!

---
class: left, top
#### Example of namespace scope

```c++
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
```

---
class: left, top
#### Example of namespace scope


```c++
int main()
{
*  double rectangleArea = rectangle::area( 12.9 , 2.5 );
*  double triangleArea = triangle::area( 4.0 , 3.0 );
  std::cout << rectangleArea << std::endl << triangleArea << std::endl;
}
```

--
- Now you have a little sense about `std::cout` and `std` Namespace.

---
class: left, top
### C++ Programs

C++ is a compiled language which means you need to install a compiler in order to generate executable files for your application.

A typical process of executable file generation is shown in this image:

.center[![Compilation](/gallery/compile.gif)]

---
class: left, top
### Writing C++ codes

* To write a C++ source code we will rely on Integrated Development Environment (IDE).



--
<ul class="list-unstyled">
  <li class="media">
    <img src="../media/Qt_logo_2016.svg" style="height:200px;width:200px;" class="mr-3" alt="qt">
    <div class="media-body">
      <h5 class="mt-0 mb-1">Qt Creator for SBE201</h5>
      <a href="{{ site.baseurl }}{% link 2020/data-structures/notes/qt.md %}">{Installing and running Qt Creator IDE}</a>
    </div>
  </li>
</ul>

You will find in the link above instructions on:
1. Downloading the Qt project packages.
2. Installation.
3. Starting and writing your first program.

---
class: left, top
### Lightweight Alternative: Microsoft VSCode

* A light IDE.
* You can use to write Markdown files and simple C++ codes.
* Download from: [{Visual Studio Code}](https://code.visualstudio.com)
--
* After downloading the `.deb` package file, open a terminal at the directory where you downloaded the package file, then:

--
```terminal
sudo dpkg -i ./<package file>
code
```

---
class: left, top
#### Writing your first C++ application

.small[Let's write our first source file. Copy the following code to your VS Code editor. Save the file as `firstApp4SBME.cpp`.]

```c++
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
  std::cout << rectangleArea << "\n" << triangleArea << std::endl;
}
```

---
class: left, top
#### Compiling your code

--
```terminal
g++ -o firstAppSBME firstAppSBME.cpp
```

--
**.green[CONGRATULATIONS!]** you have built your first application.

---
class: left, top
#### Execute the application

--
```terminal
./firstAppSBME
```

--
you should see:

```shell
32.25
6
```

---
class: left, top
## Git

![git-logo](/gallery/Git-logo.svg)

--
### Problem Definition


Imagine the case when *Emad* and *Ahmed* need to collaborate on this project. Such that:

---
class: left, top
### Problem Definition (cont'd)

1. *Emad* generates the biolerplate/skeleton (i.e the files and the main function) of the project.

```c++
#include <iostream>
namespace rectangle
{
    // No implementation yet!
}
namespace triangle
{
    // No implmenetation yet!
}
int main()
{
  double rectangleArea = rectangle::area( 12.9 , 2.5 );
  double triangleArea = triangle::area( 4.0 , 3.0 );
  std::cout << "Rectangle area: " << rectangleArea << std::endl 
            << "Triangle area: " << triangleArea << std::endl;
}
```

---
class: left, middle
### Problem Definition (cont'd)

--
2. *Ahmed* has to implement the rectangle area function $$A = w h $$

--
3. *Emad* has to implement the triangle area function $$ A = \frac{bh}{2}$$

---
class: left, middle
### Problem Definition (cont'd)
#### ~~Possible~~ Awful Solutions:

* Ahmed finishes the whole project alone.
--
* Emad finishes the whole project alone.
--
* They share intermediate codes through messenger, e-mail, or dropbox!
--
* They pass USB disk back and forth!
--
* They sit together to finish the project!

---
class:left, middle 
### Problem Definition (cont'd)

#### What if?!

--
* What if we have a team of 8 members.
--
* What if your application was as big as 20000 lines of code across tens of files.

---
class: left, middle
## Version Control Systems

--
* Keep track of all the changes that happened (No lost work).
--
* Many Developers can work on the same file at the same time.
--
* The Version Control System will handle conflicts if possible, if not, it
 will ask the developers to check it.

--
### Popular Version Control Systems

--
* Git (we will use this)
* Mercurial
* Subversion (SVN)

---
class: left, middle
### Git

.center[<img style="width:35%" src="/gallery/Linus_Torvalds.jpeg.jpg">]

--
* [{Linus Torvaldos}](https://en.wikipedia.org/wiki/Linus_Torvalds) developed Linux Kernel in 1991.
--
* Torvalds and others developed Git for management of Linux Kernel source in 2005.
--
* Git is Free and Open Source.
--
* Great community support. You can always search in [{Quora}](https://www.quora.com/) and [{Stackoverflow}](https://stackoverflow.com/) for problems you face.

---
class: left, top
#### Typical Git Cycle

For your first experience with git, refer to this workflow.

--
1. \[First Time Only\] Create/Clone Repository to your disk, so you have a local copy.
--
2. Make changes to your source (edit/add new file).
--
3. Add new files to your **repository system**. (You already created the files physically, but you need to ask the git repository to take control of your new file).
--
4. Commit your changes.
--
5. Get latest updates.
--
6. Resolve any conflict (if any).
--
7. Push to the remote repository.

---
class: left, top
##### Create/Clone Repo

--
* Case 1: New Repository.

```terminal
$ git init
$ git remote add [name] [URL]
```

--
* Case 2: Existing Repository.

```terminal
$ git clone [URL]
```

---
class: left, top
##### Track files

--
It is recommended to add file by file, so apply this command to all your application **souce** files, **exclude** any executable files or files generated by the compiler.

```terminal
$ git add [file name]
```

--
Or, alternatively, do it once for all files (not recommended, but it is up to you anyway). 
```terminal
$ git add *
```

--
`add` here means you are asking the repository to watch your files that already exists on disk.

---
class: left, top
##### Commit changes

--
* After making changes, you need to your repository to **confirm** these changes and documenting that change.
* Write a message that you can understand (e.g briefly, indicate your changes in the repository e.g "implementing square::area function").

--
```terminal
$ git commit -a -m “I implemented square::area function”
```
---
class: left, top
##### Get latest source code updates

Before you publish your changes to the remote repository, update your repository in case some member of your team has made changes before you.

--
```terminal
$ git pull [remote name] [branch name]
```

--
By default, *remote name* is `origin` and *branch name* is `master`, unless you made a new branch you are working on with your teammates.

---
class: left, top
##### Push source code changes

Publish your changes to your teammates on the remote repository:

--
```terminal
$ git push [remote name] [branch name]
```

--
Similarly, by default, *remote name* is `origin` and *branch name* is `master`, unless you made a new branch your are working on with your teammates.


--
###### But what is **Remote Repository**, What do you mean

---
class: center, top
#### Local repository and remote repository 

<img style="width:50%" src="/gallery/distributed.png">
> This photo is from [{official git website}](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control).

---
class: left, top
### Git on the cloud

Popular servers offering free remote repository hosting:

--
<img style="width:40%" src="/gallery/github.jpg"> 
**+** 
<img style="width:40%" src="/gallery/Bitbucket.svg">

--
* Github is offering you unlimited public and private repositories, your teammates per repository are limited to 5 members (Otherwise, pay). .green[Unless you are a student. Everything is free!]
--
* Bitbucket is offering you unlimited public and private repository, but your teammates for all repositories are limited to 5 members (Otherwise, pay).


---
class: center, middle
### What would you gain from keeping your projects on the cloud?

* Never lose your work

--
<img style="width:50%" src="/gallery/dog-eating-homework.jpg">


---
class: left, top
### Why Git on the cloud

--
* If you messed with your project, you can review your repository timeline and recover to a good state. 
--
* It is always safe to keep your projects on the cloud in one place. 
--
* Build a portfolio: always an elegant reference to your projects when you apply for a job. Include github profile on your CV.

---
class: left, top
## Very efficient way to demonstrate your skills
#### Example

#### [{UK VISA: Tier 1 Exceptional Talent}](https://technation.io/visa/?fbclid=IwAR1LwtzzMubZtGRHqV21nTaxeJZ6cIyUfUMJrLqxB-dYhZ9avDnzWcGVkH4)

![visa and github](../media/visa1.png)

---
class: center, middle
## A Special Gift for Bio2020 Class

<blockquote class="twitter-tweet" data-lang="en"><p lang="en" dir="ltr"><a href="https://twitter.com/hashtag/ThanksGitHub?src=hash&amp;ref_src=twsrc%5Etfw">#ThanksGitHub</a> for this gift 😄 ❤️ from all Systems and Biomedical Engineering students class 2020 at Cairo University. <a href="https://t.co/syLYrCHbJI">pic.twitter.com/syLYrCHbJI</a></p>&mdash; Amr Mahmoud (@AmrAhmed58) <a href="https://twitter.com/AmrAhmed58/status/961567568535408640?ref_src=twsrc%5Etfw">February 8, 2018</a></blockquote>

---
class: center, middle
## A Special Gift for Bio2021 Class

<blockquote class="twitter-tweet"><p lang="en" dir="ltr">Sometimes the smallest things take up the most room in your heart. <a href="https://twitter.com/hashtag/ThanksGitHub?src=hash&amp;ref_src=twsrc%5Etfw">#ThanksGitHub</a> for supporting us with your dear gift. We improved our studying process through GitHub network.<br>-From all systems and biomedical engineering students/class 2021/ at cairo university.❤❤ <a href="https://t.co/4n4uyI9wBs">pic.twitter.com/4n4uyI9wBs</a></p>&mdash; MouEhab (@_muhammedehab_) <a href="https://twitter.com/_muhammedehab_/status/1096125593006018560?ref_src=twsrc%5Etfw">February 14, 2019</a></blockquote>


---
class: center, middle
### Git cheat sheets

<img style="width:90%" src="/gallery/gh-cheatsheet.png">

[{PDF}](https://education.github.com/git-cheat-sheet-education.pdf)

---
class: center, middle
### GitHub Flow guide

<img style="width:90%" src="/gallery/gh-flow.png">

[{PDF}](https://enterprise.github.com/downloads/en/github-flow-cheatsheet.pdf)

---
class: center, middle
### GitHub-Flavored Markdown guide

<img style="width:80%" src="/gallery/gh-markdown.png">

[{PDF}](https://enterprise.github.com/downloads/en/markdown-cheatsheet.pdf)

---
class: center, middle
### GitHub for Robotics comic book 
#### explains the basics of using GitHub

<img style="width:50%" src="/gallery/gh-robot.png">

[{CBR}](https://discourse-cdn-sjc2.com/standard16/uploads/github/original/2X/1/175452fc42e0a4e34b0dd52d4c923ab47fd1619f.cbr)

---
class: center, middle
### Special Gifts for Best Students

<img style="width:70%" src="/gallery/gh-tshirts.png">

---
class: center, middle
## .green[Special Gift from GitHub to SBME 2022 Class]

--
### .green[#ThanksGitHub]

---
class: left, top
### Installing Git on your machine

Issue the following command in your terminal.
```terminal
$ sudo apt-get install git
```

---
class: left, top
### Homework

* Markdown resumes
* Basic C++
* To be announced soon

---
class: left, middle
## Linux Spaces
### System-wise space vs. User space

<img style="width:80%" src="/gallery/linux-spaces.png">

* When working on your projects, you are a **USER**.
* When installing/upgrading system-wise application/library, you are an **ADMIN**. 


---
class: left, top
## Jumping between folders (changing directories)

```terminal
$ cd (Relative Path|Absolute Path)
```

* In terminal commands, with `A|B`, I mean "Either A or B". 

---
class: left, top
## Listing files in the current directory (folder)

### List files/directories inside the current directory of the terminal
```terminal
$ ls 
```

### List files/directories on from other directory
```terminal
$ ls (Relative Path|Relative Path)
```


---
class: left, top
## Change folder name or moving folder name

```terminal
$ mv (file|directory) (new file|new directory)
```

---
class: left, top
## Copy file 


```terminal 
$ cp (file) (target path)
```

---
class: left, top
## Copy directory

```terminal
$ cp -r (directory) (target path)
```

---
class: left, top
## Create a new directory (folder)


```terminal
$ mkdir (new folder name)
```


---
class: left, top
## Removing a file

```terminal
$ rm (file)
```

---
class: left, top
## Remove a directory  

```terminal
$ rm -r (directory)
```


---
class: left, top
## WARNING: Did you say `rm`?

### HOW ABOUT `sudo rm -rf /`

DO NOT DO THIS!
```terminal
$ sudo rm -rf /
```

--
<img style="width:80%" src="/gallery/bomb.jpg">



---
class: left, top
## Updating & Upgrading your Linux

Upgrades are very important. Many hardware drivers issues are being fixed through these updates. Also, security-wise,
updates guarantees your system to be safe against hackable vulnerabilities. For example, *Spectre* and *Meltdown* vulnerabilities that exposed all
 Operating Systems (including Widnows and Linux), for more [info](https://www.pcworld.com/article/3245606/security/intel-x86-cpu-kernel-bug-faq-how-it-affects-pc-mac.html).

```terminal
$ sudo apt-get update
$ sudo apt-get upgrade
```


---
class: left, top
## Installing packages from the apt store

```terminal
$ sudo apt-get install (package name)
```

---
class: left, top
## Installing local `.deb` packages

```terminal
$ sudo dpkg -i (package path)
```

---
class: left, top
## Interesting Appliactions

| Category | package name | 
|----------|--------------|
| Music & Video | vlc, rhythm box (shipped with Ubuntu) |
| PDFs | Okular, Foxit, PdfShuffler |
| Screenshots | Shutter | 
| C++ IDEs | Qt Creator, Jet-brains CLion, VSCode |
| Python IDEs | Pycharm, Anaconda (Spyder) |
| Web IDEs | VSCode, Jet-brains WebStorm | 

---
class: left, top
# Thank you

</textarea>
