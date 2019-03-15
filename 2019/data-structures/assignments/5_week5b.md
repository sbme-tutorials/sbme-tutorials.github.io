---
layout: page
course: "sbe201"
category: "assignment"
year: "2018"
title:  "Assignment 5 (part 1): Stacks and Queues"
by: "Asem"
pdf: true
---

## Prerequisites

* Read the \[[Part1: Struct, Stacks, Linked Lists, and Queues]({{ site.baseurl }}{% link 2019/data-structures/notes/4_week4a.md %}){:target="_blank"}\] 
* Read \[[Week 5: More on Structs, Linked Lists, Const-correctness]({{ site.baseurl }}{% link 2019/data-structures/notes/5_week5.md %}){:target="_blank"}\]

## Abstract Data Type Overview

Abstract Data Types (ADT), as explained earlier are abstract specifications of a structure; **ADT** do not specify a particular implementation. **ADTs** we have been through so far:

* Stack
* Queue

While concrete data types that we use to implement the above **ADTs** are:

* Arrays
* Linked Lists

## Task distribution on the team

**Each member** in the team is **responsible to**:

1. work on a single particular type.
2. implement a linked list for that type.
3. based on the implemented linked list, implement a stack and a queue.
4. based on raw arrays, implement a stack. 

## Objectives

1. Collaboration in groups, using **git**.  
2. Implement concrete linked list of the following data types:
    1. member 1: `double`, 
    2. member 2: `std::string`,
    3. member 3: `Patient` (defined by us), and
    4. member 4 (if any): `Point` (defined by us).
    5. member 5 (if any): `char`, 
    6. member 6 (if any): `int`, 
3. For each type listed in (2), provide **stack** implementation using:
    * Arrays.
    * Linked Lists.
4. For each type listed in (2), provide **queue** implementation using **linked lists**.
5. Use your new data structures in interesting applications.

## Clone Your Asssignment

Join your group assignment from this [link](https://classroom.github.com/g/GJ_0Dc9T)

## Deadline

**Sunday of 24 March 2019, 11:59 PM (PST time)**

## Assignment 4 Requirements

### Concrete Implementation Linked List

Supported Operations:

1. insertion at front `insertFront`.
2. insertion at back `insertBack`.
3. remove front `removeFront`.
4. remove back `removeBack`.
5. remove the kth-element `removeAt`.
6. return front `front`.
7. return back `back`.
8. get arbitrary kth-element `getAt`.
9. remove nodes with given data `filter`.
10. is empty `isEmpty`?
11. size of the linked list `size`.
12. printAll `printAll`.
13. delete the whole list from the heap `clear`.

You can use the following function prototypes (declarations), for integers linked list.

```c++
void insertFront( IntegersLL &list , int data );
void insertBack( IntegersLL &list, int data );
void removeFront( IntegersLL &list );
void removeBack( IntegersLL &list );
void removeAt( IntegersLL &list , int index );
int front( IntegersLL &list );
int back( IntegersLL &list );
int getAt( IntegersLL &list, int index );
void filter( IntegersLL &list, int data );
bool isEmpty( IntegersLL &list );
int size( IntegersLL &list );
void printAll( IntegersLL &list );
void clear( IntegersLL &list );
```

Implement the **linked list** for `int`, `double`, and `char`.

### Stack

Supported Operations:

1. `push`.
2. `pop`.
3. `size`.
4. is empty? `isEmpty`.
5. return front `front` (LIFO).
6. delete the whole stack `clear`.

You can use the following function prototypes (declarations), for stack of integers.

```c++
void push( IntegersStack &stack , int data );
int pop( IntegersStack &stack );
int front( IntegersStack &stack );
bool isEmpty( IntegersStack &stack );
int size( IntegersStack &stack );
void clear( IntegersStack &stack );
```

* Implement stacks of `char` and `int` using **linked lists**.
* Implement stacks of `char` and `int` using **arrays**.

### Queue

Supported Operations:

1. `enqueue`.
2. `dequeue`.
3. `size`.
4. `isEmpty`.
5. return `front` (FIFO), **without dequeue**.
6. delete the whole queue `clear`.

You can use the following function prototypes (declarations), for queue of integers.

```c++
void enqueue( DoublesQueue &queue , int data );
int dequeue( DoublesQueue &queue );
int front( DoublesQueue &queue );
bool isEmpty( DoublesQueue &queue );
int size( DoublesQueue &queue );
void clear( DoublesQueue &queue );
```

* Implement queues of `char` and `double` using **linked lists**.
* Bonus: implement queues of `char` and `double` using **arrays**.

### Applications

* **A1**: Using stack of `int`, make an application (i.e a source file with `main` funciton) that solves [The Stock Span Problem](https://en.wikibooks.org/wiki/Data_Structures/Stacks_and_Queues#The_Stock_Span_Problem).
* **A2**: Using stack of `char`, make an application (i.e source file with `main` function) that validates the balancing of prenthesis in a string.

**Examples**:

* Input: `"()"`
    * Output: `"balanced"`
* Input: `"())"`
    * Output: `"not balanced"`
* Input: `"(()"`
    * Output: `"not balanced"`
* Input: `"()((()(((())))))"`
    * Output: `"balanced"`

* **A3**: **Your are required** to develop some interesting and useful application that depends on the **queues** you implemented earlier. It is preferably to apply some useful logic on biological data. Remember to **keep it simple and stupid**.

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