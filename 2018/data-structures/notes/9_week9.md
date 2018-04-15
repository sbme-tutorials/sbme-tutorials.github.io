---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 9: Heaps, Priority Queues (ADT), and Shortest Path Problem"
by: "Asem"
---


* TOC
{:toc}

## Objectives

1. Learn about **heap** structure
1. Implementing **heap** using arrays
1. Implementing **priority queue (ADT)** using **heap**
1. The Shortest Path Problem (TSP)

## Heaps

Heap is a very useful data structure which is potential in many applications (e.g Heapsort and Priority Queues (ADT)). Heap elements are typically allocated as a dynamic array. However, the elements are conceptually forming a *complete* tree.

| Heap as array |
|---------------|
| ![heap1](/gallery/Heap-as-array.svg) |
|  Creative Commons - [Maxinator](https://commons.wikimedia.org/w/index.php?title=User:Maxiantor&action=edit&redlink=1) |

| Conceptual Representation |
|---------------------|
| ![heaptree](/gallery/heaptree.png) |
|---------------------|
| ![heapconcrete](/gallery/heapconcrete.png) |

### Glossary

* Complete Tree: A balanced tree in which the distance from the root to any leaf is either $log(n)$ or $log(n)-1$. [source](https://www.cs.auckland.ac.nz/software/AlgAnim/heaps.html).

### Operations

#### Insert

Inserting an element at the end of the heap typically violates the heap property (i.e each parent is greater than its children for max-heaps), **so after each insertion we need to recover back the heap property**.

The algorithm of insertion (source: [wikipedia](https://en.wikipedia.org/wiki/Binary_heap)):

1. Insert the new element to the bottom level of the heap.
1. Compare the added element with its parent; if they are in the correct order, stop.
1. If not, swap the element with its parent and return to the previous step.

##### Example: Insert 15

| Steps | Layout |
|-------|--------|
| | ![heapin1](/gallery/heapindel/Heap_add_step1.svg.png) |
| We first place the 15 in the position marked by the X. However, the heap property is violated since 15 > 8, so we need to swap the 15 and the 8 | ![heapin2](/gallery/heapindel/Heap_add_step2.svg) |
| However the heap property is still violated since 15 > 11, so we need to swap again | ![heapin3](/gallery/heapindel/Heap_add_step3.svg) |
| Source: [wikipedia](https://en.wikipedia.org/wiki/Binary_heap) |

#### Extract

In a similar way to insertion, when we pop the maximum of max-heap (its root), we violate the heap property by replacing the last children in the heap to be the new root. In order to recover the heap property, we use the following procedures (source: [wikipedia](https://en.wikipedia.org/wiki/Binary_heap)):

1. Replace the root of the heap with the last element on the last level.
1. Compare the new root with its children; if they are in the correct order, stop.
1. If not, swap the element with one of its children and return to the previous step. (Swap with its smaller child in a min-heap and its larger child in a max-heap.)

| Steps | Layout |
|-------|--------|
| | ![heapdel1](/gallery/heapindel/Heap_delete_step0.svg) |
| We remove the 11 and replace it with the 4. | ![heapdel2](/gallery/heapindel/Heap_delete_step0.svg) |
| Now the heap property is violated since 8 is greater than 4. In this case, swapping the two elements, 4 and 8, is enough to restore the heap property and we need not swap elements further | ![heapdel3](/gallery/heapindel/Heap_delete_step0.svg) |
| Source: [wikipedia](https://en.wikipedia.org/wiki/Binary_heap) |

### Implementation using arrays

#### Implementation: Buffer

![treearray](/gallery/Binary_tree_in_array.svg)

```c++
struct Heap
{
    std::vector<int> buffer;
};
```

#### Implementation: Left Child Index

```c++
int getLeftIdx(int parent)
{
    return parent * 2 + 1;
}
```

#### Implementation: Right Child Index

```c++
int getRightIdx(int parent)
{
    return parent * 2 + 2;
}
```

#### Implementation: Parent Index

```c++
int getParentIdx(int child)
{
    if (child % 2 == 1)
    {
        return (child - 1) / 2;
    }
    else
    {
        return (child - 2) / 2;
    }
}
```

#### Implementation: Heap size

```c++
int size(Heap &h)
{
    return h.buffer.size();
}
```

#### Implementation: Insert

```c++
void insert(Heap &h, int data)
{
    h.buffer.push_back(data);
    int childIdx = h.buffer.size() - 1;
    bubbleUp( h , childIdx );
}
```

#### Implementation: Bubble-up / Sift-up / Cascade-up

```c++
void bubbleUp(Heap &h, int child )
{
    int parent = getParentIdx(child);
    if( child >= 0 && parent >= 0  && h.buffer[child] < h.buffer[parent])
    {
        std::swap(h.buffer[child], h.buffer[parent]);
        bubbleUp( h , parent );
    }
}
```

#### Implementation: Extract

```c++
int extract(Heap &h)
{
    int child = h.buffer.size() - 1;
    std::swap(h.buffer[child], h.buffer[0]);

    int value = h.buffer.back();
    h.buffer.pop_back();

    bubbleDown( h , 0);
    return value;
}
```

#### Implementation: Bubble-down / Sift-down / Cascade-down

```c++
void bubbleDown(Heap &h, int parent)
{
    int left = getLeftIdx(parent);
    int right = getRightIdx(parent);
    int length = size(h);
    int minimum = parent;

    if (left < length && h.buffer[left] < h.buffer[minimum])
        minimum = left;

    if (right < length && h.buffer[right] < h.buffer[minimum])
        minimum = right;

    if (minimum != parent)
    {
        std::swap(h.buffer[minimum], h.buffer[parent]);
        bubbleDown(h, minimum);
    }
    else return;
}
```

## Heapsort

| Heapsort |
|-----------|
| ![heapsort](/gallery/Sorting_heapsort_anim.gif) |
| Creative Commons - [de:User:RolandH](https://de.wikipedia.org/wiki/User:RolandH) | 

<iframe width="560" height="315" src="https://www.youtube.com/embed/H5kAcmGOn4Q" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

[Heaps and Heap Sort](http://www.zutopedia.com/hs_vs_ms.html)

## Reading Homework: Priority Queue (ADT)

* What is PQ as an ADT.
* How can be implemented using Heap.
* Applications.

### Reading Homework: Shortest Path Problem

* What is shortest path problem.
* Dijkstra's algorithm using PQ.
* Applications of Dijkstra.

#### Exercise: Dijkstra

![](/gallery/dijkstra.png)

<iframe width="560" height="315" src="https://www.youtube.com/embed/U9Raj6rAqqs" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

<img src="/gallery/trees/map.png" style="width:80%;">