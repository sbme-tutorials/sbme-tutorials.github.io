---
layout: page
course: "sbe201"
category: "assignment"
year: "2020"
title:  "Assignment 2: C++ Basic Operations on Memory"
by: "Asem"
pdf: true
---


## Objectives

* Creating variables on stack and heap.
* Using arithmetic operations on variables using their addresses in memory.
* Memory management.
* Pass-by-value (copy) vs. pass-by-reference vs. pass-by-pointer (address)
* Make simple functions and using it multiple times.

## Prerequisites (Before you start)

#### **Required**: Read the notes of the second section: \[[Memory, pointers, and references]({{ site.baseurl }}{% link 2020/data-structures/notes/week02.md %}){:target="_blank"}\]
#### **You need to learn**: Functions Can Be Declared Multiple Times and Defined Only Once

Example,

```c++
double sum( double a , double b ) // Declaration (Header)
{ // Definition
    return a + b;
}

int main()
{
    double results = sum( 12 , 17 );
    return 0;
}
```

Can also be written as,

```c++
// Function declaration (header) without definition
// We call function declaration without a header as function prototype.
double sum( double a , double b );
// Function prototypes allow us to define the function somewhere else.

int main()
{
    double results = sum( 12 , 17 );
}

// Another declaration, but now with a definition this time.
double sum( double a , double b ) 
{
    return a + b;
}
```

#### 3. **Recommended for watching** animated explanation between pass-by-value (copy) and pass-by-reference

<iframe width="640" height="360" src="https://www.youtube.com/embed/ErMKBh1pobg" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

Another video in *Arabic*,

<iframe width="640" height="360" src="https://www.youtube.com/embed/dqlCK_-ArO0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

## Deadline

**Monday 17/3/2020 11:59 PM**.

## Assignment Registration

* First, register your team for the assignment from this [link](https://classroom.github.com/g/UBg4HwXh).
* As you did in the first part, clone the remote repository to your local machine.
* Jump to the assignment folder and open the folder in VSCode or open the `CMakeLists.txt` in Qt Creator.
* You will find the questions as in-line comments in `myheader.hpp`. If you understand the memory model explained in the notes, you should solve the questions seamlessly.
* If you feel uncomfortable with any question, feel free to post at our Campuswire channel.