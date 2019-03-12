---
layout: page
course: "sbe201"
category: "notes"
year: "2019"
title:  "Introduction to OOP"
by: "Asem"
---

* TOC
{:toc}

Before starting, please clone the following starter template:

## C++ without `struct`s

After cloning, change directory `cd` to the repository, then go to `cpp-no-struct` folder:

```
cd your_repository_name
cd cpp-no-struct
```

### Example: Euclidean Distance


Consider an application that computes the euclidean distance between two points as following:

$$\begin{equation}
 \bar{ || p_1p_2 ||}  = \sqrt{ (x_1-x_2)^2 + (y_1-y_2)^2 }  
\end{equation}
$$

In a single command, let the VS Code create a new file in the current working directory and name it `euclidean.cpp`.

```
code euclidean.cpp
```

Now let's start writing the boilerplate code for a typical C++ application, if you are not so familiar, copy the following code to your editor:

```c++
#include <iostream> 

int main()
{

    return 0;
}
```

The three lines you see, if you don't know their purpose:

1. `#include <iostream>`, we need this library file that has the following objects:
    1. `std::cin` to get the two points coordinates from the user through the terminal 
    1. `std::cout` to print the results in the terminal
1. `int main()`, as all the programs in the universe starts their work from the main function.
1. `return 0`, this tells the user who run the program that the program ended successfully without a crash.


Now let's make a function that takes 4 values that correspond to (x1, y1, x2, y2) and returns the euclidean distance. To declare a function, you need to use the following syntax `return_type function_name( input1_type input1, input2_type input2, ...)` which corresponds to the following components:

1. `return_type`: the type of the results that the function returns, if it doesn't return anything, then use `void` (no type).
1. `function_name`: the function name, so we can use that name when we need to call that function.
1. The declaration of the input parameters that this function operates on.

For either a variable name, function name, namespace name, you should consider few rules to have a valid name:

1. **Alphanumeric**: the name doesn't start with a number.
1. The name **doesn't contain spaces**.
1. The name is not reserved or used before.

```c++
int x = 0; // x is valid name

int sum 3 = 0; // invalid name (spaces)

int sum3 = 0; // valid

int sum array = 0; // invalid name (spaces)

int sumArray = 0; // valid
```

For a function that computes an euclidean distance, we need to declare a function as such:

```c++
#include <iostream> 
#include <cmath> // We need this library to use the std::sqrt function

double euclideanDistance( double x1, double y1, double x2, double y2)
{
    // Self practicing: try to implement this yourself

}

int main()
{

    return 0;
}
```

Now we need to take the input from the user:

```c++
#include <iostream>
#include <cmath>

double euclideanDistance( double x1, double y1, double x2, double y2 )
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return std::sqrt( dx * dx + dy * dy );
}

int main()
{
    double px = 0;
    double py = 0;
    double qx = 0;
    double qy = 0;

    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> px >> py >> qx >> qy;
    std::cout << euclideanDistance( px , py, qx , qy) << "\n";
}
```

Now let's compile and run:

```c++
g++ euclidean.cpp -o distance
./distance
Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]
```

Now the application waits us to enter the values of the coordinates. Let's try the following:

```
1.5 1 4.5 5
5
```


### Example: 2D Shapes Distances

### Example: 

## C++ with `struct`s (data grouping)

## C++ with `struct`s (data + logic grouping)

## Encapsulation

### Access modifiers

### Const-correctness

## Inheritance

