---
layout: page
course: "sbe201"
category: "notes"
year: "2020"
title:  "Week 6 - Part A: Revision on C++ classes and templates"
by: "Asem"
---

* TOC
{:toc}

In [Lab 5]({{ site.baseurl }}{% link 2020/data-structures/labs/lab05_exercises.md %}){:target="_blank"} you were introduced how to write your first C++ class (concrete) and your first C++ template class. See also live recording at the corresponding _Campusewire_ post [Lab 5 Thursday 16-04-2020](https://campuswire.com/c/GE0CC861D/feed/54). Then, you applied the newly learned features to make a doubly-linked list.

This note will walk you through the same concepts by additional examples that will also introduce new interesting concepts and features in C++. To download and prepare the example files, at any location in your disk create new directory to contain the examples files:


```
mkdir -p section06/part-a
cd section06/part-a
wget -i https://raw.githubusercontent.com/sbme-tutorials/sbme-tutorials.github.io/master/2020/data-structures/snippets/section06/part-a/download.txt
```

You can also build all the examples in an isolated folder as following:

```
mkdir build
cd build
cmake ..
make
```

Before the examples, let's take the following note on the difference between `struct` and `class` keywords.

<div class="alert alert-primary" markdown="1" role="alert">


### <i class="fas fa-info-circle"></i> Notes: `struct` vs. `class` 

* In C++, the `struct` and `class` generally do the same thing: they declare new types. You can have a `Rectangle` type with two members `width` and `height` by either:

```c++
struct Rectangle
{
    double width;
    double height;
};
```

or:

```c++
class Rectangle
{
public:
    double width;
    double height;
};
```

* By default, the members declared in `class` are accessible only within that class (for example, you cannot access these members directly in the `main` function), so if you need to access them from outside you just add `public:` line just before the members. In contrast, `struct` members by default can directly be accessed outside the class. You will learn more interesting examples where `public` and `private` scope qualifiers play an essential role in design.
</div>

## Example: Euclidean Distance

1. **Input**: 4 doubles (x1, y1, x2, y2)
2. **Output**: Euclidead distance between point (x1,y1) and point (x2,y2).

### Procedural solution

**File Name**: `euclidean_v1.cpp`

<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fpart-a%2Feuclidean_v1.cpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>


**Testing:**

```c++
./distance1
Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]
```

Now the application waits us to enter the values of the coordinates. Let's try the following:

```
1.5 1 4.5 5
5
```

### OOP solution


**File Name**: `euclidean_v2.cpp`

<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fpart-a%2Feuclidean_v2.cpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>


**Testing:**

```c++
./distance2
Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]
```

Now the application waits us to enter the values of the coordinates. Let's try the following:

```
1.5 1 4.5 5
5
```


### OOP+Template solution

**File Name**: `euclidean_v3.cpp`

<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fpart-a%2Feuclidean_v3.cpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>


This solution is useful in case we need to use `Point` to wrap to numbers of other types like `int`. In such case, we construct the template object `Point` as `Point<int>`.


**Testing:**

```c++
./distance3
Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]
```


## Example: DNA Analysis

Consider an application that counts the different bases in the DNA. Before diving into the DNA analysis example, let's explore different ways again to iterate on C++ data structures.

### Counting routines

We can count how many times a value occurs in a container using several ways.

#### A) For-loop with integer iterator

```c++
int count1( const std::string &sequence , char q )
{
    int counter = 0;
    for( int i = 0; i < sequence.size(); ++i )
        if( sequence[i] == q )
            ++counter;
    return counter;
}
```

* This approach works on any container that we can access its elements using the `operator[]` (aka Random Access Containers), such as `std::vector`, `std::string`, `std::array`, and raw arrays.
* We passed the `sequence` by reference to avoid making copies (time and space $O(n)$).
* We passed also `sequence` as a **constant reference to avoid unintentional modification on the elements**. In that case, if your function mistakenly modifies the array, the compiler will raise an error.

{% highlight c++ linenos %}
int count1_buggy( const std::string &sequence , char q )
{
    int counter = 0;
    for( int i = 0; i < sequence.size(); ++i )
        if( sequence[i] = q )
            ++counter;
    return counter;
}
{% endhighlight %}

* Realize the common mistake in line #5. Instead of comparing using `==` operator, the function instead modifies all elements to equal `q`. Luckily, since you informed the compiler that `sequence` is a constant, then it will raise an error to draw your attention to that mistake.


#### B) For-loop with STL iterator

```c++
int count2( const std::string &sequence , char q )
{
    int counter = 0;
    for( auto it = sequence.cbegin(); it != sequence.cend(); ++it )
        if( *it == q )
            ++counter;
    return counter;
}
```

* This approach works on any STL container, such as `std::vector`, `std::string`, `std::array`, `std::list`, `std::set`, and **not raw arrays**.

#### C) Range-based for loop


```c++
int count3( const std::string &sequence , char q )
{
    int counter = 0;
    for( auto c : sequence )
        if( c == q )
            ++counter;
    return counter;
}
```

* This approach works on any STL container, such as `std::vector`, `std::string`, `std::array`, `std::list`, `std::set`, and **not raw arrays**.
* `count3` is more elegant that `count2`, preferred when possible.


#### D) Range-based for loop


If your purpose is to count a particular value in a container. You can just simply use the function `std::count` (by `#include <algorithm>`).

```c++
int count4( const std::string &sequence , char q )
{
    return std::count( sequence.begin(), sequence.end(), q );
}
```

* This approach works on any STL container, such as `std::vector`, `std::string`, `std::array`, `std::list`, `std::set`, and **not raw arrays**.
* `count4` is more elegant that `count3`, preferred if your purpose is counting.

### DNA Analysis: Procedural solution


<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fpart-a%2Fdna_basics_v1.cpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>

**Testing:**

```
cat ../covid19.fasta | ./dna1
```

<div class="alert alert-primary" markdown="1" role="alert">

### <i class="fas fa-info-circle"></i> Notes: Linux `|` to redirect the output 

The command `cat ../covid19.fasta | ./dna1` executes two programs. First one is `cat` which prints the file contents to the terminal, while the second one executes our compiled program. The linux has a utilities that redirects the programs output/input. Using the pipe `|` means to use the output of the first program as input to the second program.
</div>


### DNA Analysis: OOP solution


<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fpart-a%2Fdna_basics_v2.cpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>

* In line #9, we declared and defined a constructor that constructs `DNA` object given an input string. Constructors are special functions in the class that enable us to make necessary initializations.
* In line #14, we declared the `count` method as constant method by adding `const` at the end of the line. This avoids modifying the contents of `sequence` by mistake.
* In line #20, we declared the `fromStream` method as static method. Which means it is not dependent on the data members. The reason we moved the `fromStream` from a free function into the class as static method is to add more organization. Now the `DNA` acts as a namespace for the `fromStream` function, hence we can only call this function from outside as `DNA::fromStream`. 
* In line #31-#32, we declared the `std::string sequence` under the `private` scope. This means that `sequence` cannot be seen or accessed directly outside the `DNA`; only the `DNA` methods can access it.
  
**Testing:**

```
cat ../covid19.fasta | ./dna2
```

## Summary

What you have learned from previous examples:

1. Use of `struct` and `class`.
2. Use of templates.
3. STL iterators.
4. Range-based for loops.
5. `std::count`.
6. Const-correctness, as applied to:
   * references (e.g `const std::string &`)
   * methods (e.g `int count( char q ) const`)
7. Static methods. Which are functions we decided to put inside the class because they are related. Static methods are not bound to objects, which means:
   * No `this` pointer is accessible inside a static method.
   * The class name acts as a `namespace` for static methods. For example, calling a static method `fromStream` inside `DNA` class can be done via `DNA::fromStream`.
8. `private` and `public` scope qualifiers. This is very important feature to employ as it helps to avoid abusing the objects from outside the class functions.