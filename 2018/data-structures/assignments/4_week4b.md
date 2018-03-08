---
layout: page
course: "sbe201"
category: "assignment"
year: "2018"
title:  "Assignment 4: Stacks and Queues"
by: "Asem"
pdf: true
---

## Prerequisites

* **Required**: Read the \[[Part1: Struct, Stacks, Linked Lists, and Queues]({{ site.baseurl }}{% link 2018/data-structures/notes/4_week4a.md %}){:target="_blank"}\] 
* **Required**: Read \[[More on Structs, Linked Lists, Naming Conventions, Const-correctness, Build Systems, and Git for Teams]({{ site.baseurl }}{% link 2018/data-structures/notes/4_week4b.md %}){:target="_blank"}\], the following sections:
    * [Assignment of Week 4](/2018/data-structures/notes/4_week4b.html#assignment-of-week-4)
    * [LL-Based Queues](/2018/data-structures/notes/4_week4b.html#ll-based-queues)
* **Optional**: The rest of the notes \[[More on Structs, Linked Lists, Naming Conventions, Const-correctness, Build Systems, and Git for Teams]({{ site.baseurl }}{% link 2018/data-structures/notes/4_week4b.md %}){:target="_blank"}\]


## Abstract Data Type Overview

Abstract Data Types (ADT), as explained earlier are abstract specifications of a structure; **ADT** do not specify a particular implementation. **ADTs** we have been through so far:

* List
* Stack
* Queue

While concrete data types that we use to implement the above **ADTs** are:

* Arrays
* Linked Lists

## Objectives

1. Collaboration in groups, using **git**.
2. Implement concrete linked list of few premitive data types (`int`, `double`, and `char`).
3. Implement **stacks** of few primitive data types, using:
    * Arrays.
    * Linked Lists.
4. Implement **queues** of few primitive data types, using:
    * Linked Lists.
    * Arrays (Bonus).
5. Use your new data structures in interesting applications.

## Clone Your Asssignment

Join your group assignment from this [link](https://classroom.github.com/g/GJ_0Dc9T)

## Deadlines

**Soft deadline** Tuesday of 13/3, at 11:59 PM.

Before *soft deadline* you are ecncouraged to ask your TA for  guidance concerning any difficulties working on the assignment.

**Hard deadline** Thursday of 15/3, at 11:59 PM.

Guidance are not offered after the *soft deadline*. Just make sure to submit before the **hard deadline** to avoid late penalties.

## Grading Policy

Grades will be determined by:

* **50%** *Group score*: each group will receive a score to be assigned to each member in that group.
    1. Reasonable Load distribution.
    2. Seamless collaboration on the same repository.
    3. Overall consistency (see naming conventions of the notes of Thursday of 1st of March).

* **50%** *Individual score*: depends on the contribution of each member in the group.

### Bonus Grades

Bonus grades will be assigned to the whole group by considering the following points:

* **Adoption** of **KISS** and **DRY** solutions.
* **Representative** and **optimum** use of:
    * `struct`
    * `namespace`
    * **const-correctness**
    * **Basic OOP** (see **Thursday of 1st of March notes on methods vs. functions**).
* **overusing certain feature has negative impact**, so be careful and rational.

## Assignment 4 Requirements

A submission won't be accepted (zero score) if any requirement is not satisfied.

### Concrete Implementation Linked List

Supported Operations:

1. insertion at front `insertFront`.
2. insertion at back `insertBack`.
3. remove front `removeFront`.
4. remove back `removeBack`.
5. return front `front`.
6. return back `back`.
7. remove a node **next to** a given node `removeAfter`.
8. remove nodes with given data `filter`.
9. is empty `isEmpty`?
10. size of the linked list `size`.
11. printAll `printAll`.
12. delete the whole list from the heap `clear`.

Implement the **linked list** for `int`, `double`, and `char`.

### Stack

Supported Operations:

1. `push`.
2. `pop`.
3. `size`.
4. is empty? `isEmpty`.
5. return front `front` (LIFO).
6. delete the whole stack `clear`.

* Implement stacks of `char` and `int` using **arrays**.

### Queue

Supported Operations:

1. `enqueue`.
2. `dequeue`.
3. `size`.
4. `isEmpty`.
5. return `front` (FIFO).
6. delete the whole queue `clear`.

* Implement queues of `char` and `double` using **linked lists**.
* Bonus: implement queues of `char` and `double` using **arrays**.

### Applications

1. Using stack of `int`, make an application (i.e a source file with `main` funciton) that solves [The Stock Span Problem](https://en.wikibooks.org/wiki/Data_Structures/Stacks_and_Queues#The_Stock_Span_Problem).
2. Using stack of `char`, make an application (i.e source file with `main` function) that validates the balancing of prenthesis in a string.

**Examples**:

* Input: `"()"`
    * Output: `"balanced"`
* Input: `"())"`
    * Output: `"not balanced"`
* Input: `"(()"`
    * Output: `"not balanced"`
* Input: `"()((()(((())))))"`
    * Output: `"balanced"`

3. **Your are required** to develop some interesting and useful application that depends on the **queues** you implemented earlier. It is preferably to apply some useful logic on biological data. Remember to **keep it simple and stupid**.

## Guidelines

These are suggested guidelines to follow, i.e not mandatory.

### Collaboration

1. To avoid conflicts, each member would create a unique header file (e.g `member3.hpp`), to implement his share in the task.
2. After creating (or renaming) a file (e.g `member3.hpp`):
    * `git add member3.hpp`
    * `git commit -a -m "add/rename file for member3"`
    * `git pull origin master`
    * `git push origin master`
3. It is recommended that each member wrap his/her own work in a `namespace` representing the data structure he/she works on. For example, `lists`, `stacks`, and `queues`.
4. At the begining, you need for a meeting to settle on a plan for collaboration on the remote repository.
5. It is recommended that each team has a leader, who distributes the load, writes any necessary skeleton codes.

### Declaring namespace across mutiple files

Assume that both **member1** and **member2** implement functions related to **queue** in `member1.hpp` and `member2.hpp` files, respectively. It is **perfectly Okay** that they declare the same `namespace` of `queue`.

```c++
// member1.hpp
// ..
// ..
// ..
namespace queue
{

void enqueue( IntegerLL &l , int element )
{
    // Some logic
}

}
```

```c++
// member2.hpp
// ..
// ..
// ..
namespace queue
{

void enqueue( CharLL &l , char element )
{
    // Some logic
}

}
```