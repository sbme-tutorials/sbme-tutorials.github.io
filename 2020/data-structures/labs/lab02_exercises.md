---
layout: page
course: "sbe201"
category: "lab"
year: "2020"
title:  "Lab 2: Revision on C++ (2)"
by: "Asem"
pdf: true
---


## Organizing Lab Exercises

* Let's join all our lab exercises into one repository. Register in the link [https://classroom.github.com/a/PsMRcCci](https://classroom.github.com/a/PsMRcCci) and get a generated repository that you will use to keep all your lab exercises at one place.
* Clone the generated repository.
* In the repository, make new directories (folders) for `lab01` (of last week) and `lab02` (today's).

```bash
mkdir lab01 lab02
```

* Add your files of last week lab (`calculation.cpp` & `pythagoras.cpp`) to `lab01`

```bash
mv /path/to/calculation.cpp /path/to/pythagoras.cpp lab01
```

* Add `lab01` and `lab02` to the repository database, commit changes, and push

```bash
git add lab01 lab02
git commit -a -m "add first and second labs"
git push origin master
```


## Application 1: Range Summation

As mathematical historians have told the story, the German mathematician Carl
Friedrich Gauss (1777-1855) began to show his mathematical talent at a very
early age. When he was in elementary school, Gauss was asked by his teacher
to compute the sum of the numbers between 1 and 100. Gauss is said to have
given the answer instantly: 5050. Write a program that computes the answer to
the question Gauss’s teacher posed.


Starting from the following code (name the file as `range_sum.cpp`):

```c++
int range_sum( int start, int end )
{

}

int main()
{

}
```

Finally compile your file:

```bash
g++ range_sum.cpp -o summer.out
```

Test your program:

```bash
./summer.out
1 100
5050
```


## Application 2: Find the roots

Write a program to solve quadratic equations. A quadratic equation is of the form
$$ax^2 + bx + c = 0$$

If you don’t know the quadratic formula for solving such an expression, do some research. Remember, researching how to solve a problem is often necessary before a programmer can teach the computer how to solve it. Use doubles for the user inputs for `a`, `b`, and `c`. Since there are two
solutions to a quadratic equation, output both `x1` and `x2`.

Starting from the following code (name the file as `root.cpp`):

```c++
void root( double a, double b, double c, double &x1, double &x2)
{
    

}

int main()
{
    
    
}
```