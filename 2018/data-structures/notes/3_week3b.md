---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 3 - Part2: Command Line Arguments and Compilation of Multiple Files"
by: "Asem"
---

## Command Line Arguments

### Examples: Why Command Line Arguments

* `apt-get install vlc`
* `git commit -a -m "kill me please!"`
* `cp [file] [target path]`

| Application | Argument 1 | Argument 2 | Argument 3 | Argument 4 |
|-------------|------------|------------|------------|------------|
| `apt-get` | `install` | `vlc` | `null` | `null` |
| `git`  | `commit` | `-a` | `-m` | `"kill me please!"` |
| `cp` | `[file]` | `[target path]` | `null` | `null` |

### Command Line Arguments in C and C++

```c++
#include <iostream>
// argc is counter for the arguments, including the application-name.
// argv is array of strings representing the arguments.
int main( int argc, char **argv )
{
    std::cout << "Arguments count:" << argc << std::endl;

    for( int i = 0 ; i < argc ; ++i )
    {
        std::cout << "Argument:" << argv[ i ] << std::endl;
    }
}
```

> Compile the above example and run the application with any arguments.

#### Example: Simple calculater from command line arguments

What if we have a simple calculator that we pass our operarands directly from the terminal.

```terminal
$ ./myCalculator 13 + 7
20
```

```terminal
$ ./myCalculator 50 - 39
11
```

| argv[0] | argv[1] | argv[2] | argv[3] |
|---------|---------|---------|---------|
| "./myCalculator" | "13" | "+" | "7" |
| "./myCalculator" | "50" | "-" | "39" |

**Note that "13", "7", "50", and "39" are strings! Not integers**
How to convert from string representation to integer representation?

```c++
int x = "40"; // Compiler Error (Type Mismatch)

int y = std::atoi("40"); // Now this works, and y = 40.

double z = std::atof("13.9"); // z = 13.9
```

* `std::atoi` converts a string representation of numbers into the equivalent integer.
* `std::atof` converts a string representation of numbers into the equivalent double.
* You need to `#include <cstdlib>` to use this function.

In our application we can use the function implemented by *Emmanuel and Mostafa* [from here](/2018/data-structures/presentations/1_week1_recap/index.html#27).

![](/gallery/argv.svg)

```c++
#include <iostream>
#include <cstdlib>

// Our logic
double calculation( double a , double b , char operation );

int main( int argc , char *argv[] )
{
    double a = std::atof( argv[1] );
    double b = std::atof( argv[3] );

    char *op_string = argv[2];
    char op = op_string[0];

    std::cout << calculation( a , b , op ) << std::endl;
    return 0;
}

double calculation( double a , double b , char operation )
{
    // Copy-paste the implementation of Emmanuel here.
}
```

> After implementing (or copying) the `calculation` function, compile this example.

## FAQ #3. Why not using `std::cin` inside functions of particular logic

After working with different kind of input (i.e input from the command line arguments instead of `std::cin`), you can now realize why it is pointless to use `std::cin` and `std::cout` in our interesting and usefull functions. See [FAQ #3: Why not using `std::cin` inside functions of particular logic]({{ site.baseurl }}{% link 2018/data-structures/notes/3_faq3.md %}){:target="_blank"}

## Making Your Own Header Libraries

You may realized that we used `calculation` multiple times in different program. And you also may realized that I used the word "*Copy The Implementation*"! Which is very frustrating; copying a particular implementation in multiple programs! 

What about making a library containing your very useful function:

* So you use that library whenever you need, **without copying sources**. This will make you adopt [DRY principle (i.e Don't repeat your self)](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself).
* So if you have figured out a mistake in your function, you just fix it from one place; No need to jump across sources to fix the buggy function.

![multiple](/gallery/multiplefiles.svg)