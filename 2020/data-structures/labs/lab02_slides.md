---
layout: presentation
style: laminal
highlighter: ir-black
course: "sbe201"
category: "presentation"
year: "2020"
title: "Lab 2: Revision on C++ (2)"
by: "Asem"
author: "Asem Alaa"
---
    
<textarea id="source">

---
class: left, top
## Command Line Arguments

--
### Examples: Why Command Line Arguments


--
* `apt-get install vlc`
* `git commit -a -m "correction of problem 3!"`
* `cp [file] [target path]`

---
class: left, top
### Command Line Arguments in C and C++

--
```c++
#include <iostream>
// argc is counter for the arguments, including the application-name.
// argv is array of strings representing the arguments.
int main( int argc, char *argv[] )
{
    std::cout << "Arguments count:" << argc << std::endl;

    for( int i = 0 ; i < argc ; ++i )
    {
        std::cout << "Argument:" << argv[ i ] << std::endl;
    }
}
```

---
class: left, top
#### Example: Simple calculater from command line arguments

--
What if we have a simple calculator like this.

--
```terminal
$ ./myCalculator 12.4 + 3.2
20
```

--
![](/gallery/argv2.svg)


---
class: left, top

#### Convert from string form to integer form?

--
```c++
int x = "40"; // Compiler Error (Type Mismatch)

int y = std::atoi("40"); // Now this works, and y = 40.

double z = std::atof("13.9"); // z = 13.9
```

--
* `std::atoi` converts string representation => integer representation.
--
* `std::atof` converts a string representation => double representation.
--
* `#include <cstdlib>`.

---
class: left, top

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

    std::cout << calculcation( a , b , op ) << std::endl;
    return 0;
}
```

---
class: left, top

```c++
double calculation( double a , double b , char operation )
{
  switch( operation )
  {
    case '+': return a + b;
    case '-': return a - b;
    case 'x': return a * b;
    case '/': return a / b;
    default:  return 0;
  }
}
```

---
class: left, top
![](/gallery/argv2.svg)


---
class: left, top
## Making Your Own Header Libraries

### [{DRY}](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself)
#### i.e Don't repeat your self

* Don't copy codes.
* If you need to fix a mistake, fix it from one place.

---
class: left, top

<img style="width:95%" src="/gallery/multiplefiles.svg">

</textarea>