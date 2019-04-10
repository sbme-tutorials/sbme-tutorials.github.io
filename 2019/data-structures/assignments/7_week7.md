---
layout: page
course: "sbe201"
category: "assignment"
year: "2019"
title:  "Assignment 6: BST, Set, and Map"
by: "Asem"
pdf: true
---

## Prerequisites

* Read Week 7 [Slides]({{ site.baseurl }}{% link 2019/data-structures/presentations/7_week7/index.md %}){:target="_blank"}

## Objectives

1. Implement a concrete binary search tree.
1. Implement a Set (ADT) and a Map (ADT) based on BST.
1. Encouraged: adopt OOP.
1. Encouraged: templates.
1. Encouraged: const-correctness.
1. Encouraged: encapsulation (appropriate access modifiers)
1. Encouraged: useful constructors.

## Clone Your Asssignment

Join your individual assignment from this [link](https://classroom.github.com/a/6VXxXxrz)

## Deadline

**Thursday of 18 April 2019, 11:59 PM (PST time)**

## Requirements

### R1: implement a binary search tree

1. Complete the source code in `bst.hpp` (templates + OOP are highly encouraged).
1. Use the `test_tree.cpp` source file to test your **BST** implementation.

```
g++ test_tree.cpp -o testBST
./testBST
```

### R2: implement a Set (ADT) then extract set of unique words in a text using that Set

1. Complete the source code in `set.hpp` then make a **set** of `std::string`s.
1. Complete the source code in `unique_words.cpp` to print the set of words of the given file.

```
g++ unique_words.cpp -o uniqueWords
./uniqueWords data/carl_sagan.txt
```

### R3: Implement a dictionary that maps characters to integers

You are required here to develop a dictionary that has `char` as a key and `int` as a value. We will use this dictionary as a counter for each character.

1. A template and OOP are highly preferred to avoid redundancy.
1. Complete the implementation in `map.hpp`, to produce a a dictionary that maps `char` to `int`.
1. Complete the source code in `countDNA.cpp`, to count each base in the given dna file using the developed **dictionary**.

```
g++ countDNA.cpp -o countDNA
./countDNA data/genetic_data.txt
```

### R4: Text Processing

You are required here to develop a dictionary that has `std::string` as a key and `int` as a value. We will use this dictionary as a counter for words. Implement the `Map` data structure based on **BST**.

1. If you didn't use templates in `R1`, then extend the implementation in the `map.hpp` file to produce a **dictionary** that maps `std::string` to `int`.
1. Complete the source code in `count_words.cpp` to count each word in the given text file.


#### Comparing `std::string`s

Insertion and removal in **BST** depends in comparison in each step between the tree nodes. When we compare integers, we simply use the `<`, `<=`, `>`, `>=`, `==` operators. What if we need to compare strings lexicographically (i.e in order to be alphabetically ordered)?

Fortunately, [`std::string`](http://en.cppreference.com/w/cpp/string/basic_string) comes with a lot of embedded functions. We are going to use the embedded [`compare`](http://en.cppreference.com/w/cpp/string/basic_string/compare) function.


```c++
#include <string>
int main()
{
    std::string s1 = "batman";
    std::string s2 = "superman";

    int comparison = s1.compare( s2 );
}
```

| comparison value | explanation |
|------------------|-------------|
| positive | it means that `s1` comes after `s2` alphabetically, which is not the case |
| negative | it means that `s1` precedes `s2` alphabetically, which is the case |
| 0 | it means that `s1` equals `s2`, which is not the case |


#### Comparing operators `std::string`s

```c++
#include <string>
#include <iostream>
int main()
{
    std::string s1 = "batman";
    std::string s2 = "superman";

    if( s1 < s2 )
        std::cout << s1 << " precedes " << s2;
    else 
        std::cout << s2 << " precedes " << s1;
}
```

After you finish:

```
g++ count_words.cpp -o countWords
./countWords data/carl_sagan.txt
```