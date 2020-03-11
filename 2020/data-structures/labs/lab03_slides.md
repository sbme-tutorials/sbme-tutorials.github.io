---
layout: presentation
style: laminal
highlighter: github
course: "sbe201"
category: "presentation"
year: "2020"
title: "Lab 2: Arrays, Function Overloading, & Recursion"
by: "Asem"
author: "Asem Alaa"
---
    
<textarea id="source">


---
## Functions overloading

--
C++ allows *functions with same name*, **but different parameter types**.

--
For example, this is **not allowed** in C++:

```c++
double area( double w , double h )
{
    return w * h;
}

double area( double base , double height ) 
{ // Compiler Error, redefinition of area(double,double)
    return base * height / 2;
}
```

**AMBIGUOUS** when calling `area(1.4,5)`

---
## Functions overloading

.green[This works]

--
```c++
double area( double d )
{
    return d * d; // square area
}

double area( double w, double h)
{
    return w * h;
}
```

---
## Functions overloading

```c++
struct Rectangle
{
  double w;
  double h;
};
struct RTriangle
{
  double b;
  double h;
};
double area( Rectangle rect ) // Works!
{
    return rect.w * rect.h;
}
double area( RTriangle tr ) // Works!
{
    return tr.b * tr.h / 2;
}
```

---
## Functions overloading

```c++
double area( double d ); // square
double area( Rectangle rect );
double area( RTriangle tr );

int main()
{
  double s;
  std::cin >> s;
  std::cout << "square area="<< area(s) <<"\n";
  Rectangle r;
  std::cin >> r.w >> r.h;
  std::cout << "rectangle area=" << area(r) << "\n";
  RTriangle tr;
  std::cin >> tr.b >> tr.h;
  std::cout << "triangle area=" << area(tr) << "\n";
}
```


---
## Recursion

### Factorial example

<img src="/gallery/recursion1.gif" style="width:100%">


---
```c++
#include <iostream>
int factorial( int n )
{
    if( n <= 1 )
        return 1;
    else
        return n * factorial( n - 1 );
}

int main()
{
    std::cout << "5!=" << factorial( 5 );
    return 0;
}
```

---
<img src="/gallery/fact5rec/8.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/7.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/6.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/6.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/5.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/4.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/3.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/2.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/1.svg" style="width:100%;">



---
### How recursion work in stack memory

[{Demo: How Recursive Factorial Work in Memory}](https://www.cs.usfca.edu/~galles/visualization/RecFact.html)

---
### Recursion is not Function Overloading

--
The following is not recursion

```c++
struct Rectangle
{
    double a = 0;
    double b = 0;
};

double area( double a , double b )
{
    return a * b;
}

double area( Rectangle rect )
{
    return area( rect.a , rect.b ); // This is not recursion.
}
```

---
However, the following calling `area` is recursive, it calls itself

```c++
struct Rectangle
{
    double a = 0;
    double b = 0;
};

double area( Rectangle rect )
{
    return area( rect ); // This is a recursion. But a buggy function!
}
```

* infinite recurions, 
* until .red[stack memory overflow] happens, 
* and finally the program crashes.

---
### **Exercise**: Power Function

--
Implement a function `power` that uses recursion to compute the power of the input number.

</textarea>