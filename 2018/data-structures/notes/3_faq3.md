---
layout: page
course: "sbe201"
category: "faq"
year: "2018"
title:  "FAQ #3: Why not using `std::cin` inside functions of particular logic"
by: "Asem"
---

## FAQ #3. Why not using `std::cin` inside functions of particular logic

Most of functions implement some logic (ideas); physical, mathematical, or biological theories. Using Input/Output functions like `std::cin` or `std::cout` in such functions is limiting their usage. What if you are interested in input from:

* The command line arguments (e.g through `argv` and `argc`).
* The user input (e.g through `std::cin` and `std::cout`).
* Some file in your disk (e.g through `std::ifstream`).
* Some input from the internet (e.g using _CURL_ library).

You have to make your functions usable with any input. Simply, you just isolate your interesting functions from Input/Output operations.

### Example

In this application we have a `calculation` function that takes two operands and operation symbol, and returns the numerical results. **We intended not to include any `std::cin` or `std::cout` in that function. So we can use it with any kind of Input/Output sources.**

Use case #1: use `calculation` with input from the command line arguments.

```c++
#include <iostream>
#include <cstdlib>

// Our logic, interesting function
double calculation( double a , double b , char operation )
{
    if (operation == '+')
    {
        return a + b;
    }
    else if (operation == '-')
    {
        return a - b;
    }
    else if (operation == '*')
    {
        return a * b;
    }
    else if (operation == '/')
    {
        return a / b;
    }
    else
    {
        return 0;
    }
}

int main( int argc , char *argv[] )
{
    double a = std::atof( argv[1] );
    double b = std::atof( argv[3] );

    char *op_string = argv[2]; // op_string == "+" == {'+','\0'} (null-terminated)
    char op = op_string[0]; // op == '+'

    std::cout << calculation( a , b , op ) << std::endl;
    return 0;
}
```

Use case #2: use `calculation` and our input is now from user.

```c++
#include <iostream>

// Our logic, interesting function.
double calculation( double a , double b , char operation )
{
    if (operation == '+')
    {
        return a + b;
    }
    else if (operation == '-')
    {
        return a - b;
    }
    else if (operation == '*')
    {
        return a * b;
    }
    else if (operation == '/')
    {
        return a / b;
    }
    else
    {
        return 0;
    }
}

int main( int argc , char *argv[] )
{
    double a = 0;
    double b = 0;
    char op = 0;

    std::cin >> a >> op >> b;

    std::cout << calculation( a , b , op ) << std::endl;
    return 0;
}
```

So we used the same function without any changes, because our interesting function is isolated from any Input/Output operations. We made our Input/Output operations in both cases inside the `main` function.