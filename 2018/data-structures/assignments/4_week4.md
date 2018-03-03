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


## Assignment 4

### Concrete Implementation Linked List of Doubles (DoubleLL)

```c++
struct DoubleNode
{
    double data;
    DoubleNode *next;
};

struct DoubleLL
{
    DoubleNode *head;
};
```

**Supported Operations**:

1. Insertions

```c++
void insertFront( DoubleLL &list , double data )
{

}

void insertBack( DoubleLL &list , double data )
{

}

void insertAt( DoubleLL &list , DoubleNode *target , double data )
{

}
```

2. Removals

```c++

#### Implement Another Version But for Characters (CharLL)

### Stack Implementation of Doubles using LL (DoubleStackLL)

#### Implement Another Version But for Characters (CharStackLL)

### Queue Implementation of Doubles using LL (DoubleQueueLL)

### Bonus: Stack Implementation using Arrays (DoubleStackArray)

### Bonus: Queue Implementation using Arrays (DoubleQueueArray)