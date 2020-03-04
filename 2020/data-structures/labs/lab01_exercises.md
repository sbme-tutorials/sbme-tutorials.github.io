---
layout: page
course: "sbe201"
category: "lab"
year: "2020"
title:  "Lab 1: Revision on C++"
by: "Asem"
pdf: true
---

* TOC
{:toc}

## Application 1: Simple Calculator

Starting from the following code (name the file as `calculation.cpp`):

```c++
double calculation( double a, double b, char op )
{
    // Implement the ('+','-','/','*') 
    // operations for 'a' and 'b' using if-else or switch case.

}

int main()
{
    // Create two doubles for the operands. (initialize /w 0)
    
    // Create a char for the operation. (initialize /w '+')

    // Receive the input from the user using std::cin in one line.

    // Call the function 'calculation' and print its output

}
```

Finally compile your file:

```bash
g++ calculation.cpp -o calculator.out
```

Test your program:

```bash
./calculator.out
16 * 3
```

So every time you need to run the program to make single calculation!

### Additional Improvement

Make your program able to make infinite calculations, until the user uses '!' as an operation. For example, if user inputs `5 ! 3`, the the program halts.


## Application 2: Pythagoras

Starting from the following code (name the file as `pythagoras.cpp`):

```c++
double length( double x1, double x2, double y1, double y2 )
{
    // Apply Pythagoras law to compute the distance between (x1,y1) and (x2,y2) 

}

int main()
{
    // Create four doubles for the x1, x2, y1, y2.
    
    // Receive the input from the user using std::cin in one line.

    // Call the function 'length' and print its output

}
```


### Additional Improvement

Make your program able to persist running, until the user special input. For example, if the user input four zeros, then the program halts.


Additionally use `struct` to declare a new type `Point`:

```c++
struct Point
{
    double x;
    double y;
};
```

Now, instead of using four `double`s, you can use two `Point`s.


Update your `length` function to the following signature:

```c++
double length( Point p1, Point p2 )
{
    // Apply Pythagoras law to compute the distance between p1 and p2 

}
```