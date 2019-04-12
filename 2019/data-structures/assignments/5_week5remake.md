---
layout: page
course: "sbe201"
category: "assignment"
year: "2019"
title:  "Assignment 5 (individual remake and practicing): Stacks and Queues"
by: "Asem"
pdf: true
---

## Prerequisites

* Read the \[[Part1: Struct, Stacks, Linked Lists, and Queues]({{ site.baseurl }}{% link 2019/data-structures/notes/4_week4a.md %}){:target="_blank"}\] 
* Read \[[Week 5: More on Structs, Linked Lists, Const-correctness]({{ site.baseurl }}{% link 2019/data-structures/notes/5_week5.md %}){:target="_blank"}\]
* Read \[[Introduction to OOP: classes, encapsulation, methods]({{ site.baseurl }}{% link 2019/stl-intro/presentations/1_oop1/index.md %}){:target="_blank"}\]
* Read \[[Introduction to OOP 2: constructors, default arguments, const-correctness in OOP, template classes and template functions, access modifiers, enum types.]({{ site.baseurl }}{% link 2019/stl-intro/presentations/2_oop2/index.md %}){:target="_blank"}\]
* Good understanding of the relation between the DNA, RNA, and proteins. If you don't have sufficient background:
  *  [Overview of translation \| Khan Academy](https://www.khanacademy.org/science/biology/gene-expression-central-dogma/translation-polypeptides/a/translation-overview)
  *  [Starting off in Bioinformatics — Turning DNA sequences into Protein sequences \| Towards Data Science](https://towardsdatascience.com/starting-off-in-bioinformatics-turning-dna-sequences-into-protein-sequences-c771dc20b89f)

## Abstract Data Type Overview

Abstract Data Types (ADT), as explained earlier are abstract specifications of a structure; **ADT** do not specify a particular implementation. **ADTs** we have been through so far:

* Stack
* Queue

While concrete data types that we can use to implement the above **ADTs** are:

* Arrays
* Linked Lists

## Objectives

1. Implement a concrete **template** linked list.
1. Provide a **template** stack implementation using linked list.
1. For each type listed in (2), provide **queue** implementation using **linked lists**.
1. Adopt OOP.
1. Respect const-correctness.
1. Respect encapsulation (using appropriate access modifiers)
1. Use Enum class when appropriate.
1. Make useful constructors.

## Clone Your Asssignment

Join your individual assignment from this [link](https://classroom.github.com/a/yTT0kHeR)

## Deadline

**Thursday of 18 April 2019, 11:59 PM (PST time)**

## Assignment 5 Requirements

### Concrete Implementation of Linked List

Supported Operations:

1. insertion at front `insertFront`.
2. insertion at back `insertBack`.
3. remove front `removeFront`.
4. remove back `removeBack`.
5. remove the kth-element `removeNth`.
6. remove a node given its preceding node `removeNext`.
7. return front `front`.
8. return back `back`.
9. get arbitrary nth-element `getNth`.
10. is empty `isEmpty`?
11. size of the linked list `size`.
12. printAll `printAll`.
13. delete the whole list from the heap `clear`.

You need to make your implemented data structure generic for any type by using **templates**. Also, adopt **OOP** for that data structure.

Implementation hints:

1. you can start by implementing the data structure as usual for a particular type (e.g `int`).
1. move the free functions inside the `struct`/`class` and omit the input parameter of the data structure from those functions.
1. templetize by substituting all `int` with a generic `T`, then declare `T` as template parameter.


### Stack (ADT)

Based on the **linked list** above, implement a **stack** that supports the following operations:

1. `push`.
2. `pop`.
3. `size`.
4. is empty? `isEmpty`.
5. return front `front` (LIFO).
6. delete the whole stack `clear`.

Implementation hints:

1. you can start by implementing the data structure as usual for a particular type (e.g `int`).
1. move the free functions inside the `struct`/`class` and omit the input parameter of the data structure from those functions.
1. templetize by substituting all `int` with a generic `T`, then declare `T` as template parameter.

### Queue (ADT)

Based on the **linked list** above, implement a **quee** that supports the following operations:

1. `enqueue`.
2. `dequeue`.
3. `size`.
4. `isEmpty`.
5. return `front` (FIFO).
6. delete the whole queue `clear`.

Implementation hints:

1. you can start by implementing the data structure as usual for a particular type (e.g `int`).
1. move the free functions inside the `struct`/`class` and omit the input parameter of the data structure from those functions.
1. templetize by substituting all `int` with a generic `T`, then declare `T` as template parameter.

### Use Enum class for `Patient` sex identifier

Make the necessary changes to use `enum class` for representing the patient's sex.

### Implement constructors

Make useful constructor for every `struct`/`class` in your code, including the `Point` and `Patient` in `custom_types.hpp`.

### Applications

#### A) Complementary DNA using Stack

It turns out that we can implement the complementary sequence of DNA using different methods. In the `dna.hpp`, you will find two versions for the complementary sequence function:

##### **A.1** `complementarySequence1` (implemented)

Which is the direct one that most of you managed to implement in the previous task.
Here I provide an implementation using the handy `std::string` of the STL instead of using bare arrays.

```c++
std::string complementarySequence1( const std::string &dna )
{
    // Allocate string with the same size of `dna`, and init with zeros.
    std::string complementary = std::string( dna.size(), 0 );
    for ( int i = 0; i < dna.size(); ++i )
    {
        complementary[i] = complementaryBase( dna[dna.size() - 1 - i] );
    }
    return complementary;
}
```

##### **A.2** `complementarySequence2` (implemented)

In this version, which is also implemented for you, we will consider complementing the sequence without bothering with the indices trick part in version 1:

```c++
complementary[i] = complementaryBase( dna[dna.size() - 1 - i] );
```

Instead, we will push, in order, each complemented base in a stack. After we have a stack storing all the complementary bases, we will populate the new sequence by popped characters in the stack. That way we can obtain 1) a **complemented** bases and 2) in a **reversed** sequence.

In this function we are going to use the stack of the **STL**. To use an `std::stack` data structure, you need:

1. `#include <stack>` library file.
2. create the stack using the following syntax according to the type of interest:

```c++
std::stack< char > stack1; // now we have a stack of chars named `stack1`.
std::stack< int > stack2; // now we have a stack of integers named `stack2`.
```

We learn soon how to make template `struct`/`class` to make our data structures generic for any type.

Here is our `complementarySequence2` function:

```c++
std::string complementarySequence2( const std::string &dna )
{
    // Empty string.
    std::string complementary;
    std::stack<char> dnaStack;

    for ( int i = 0; i < dna.size(); ++i )
    {
        char c = complementaryBase( dna[i] );
        dnaStack.push( c );
    }

    // Now populate the `complementary` from the stack.
    while ( !dnaStack.empty())
    {
        char c = dnaStack.top();
        complementary.push_back( c );
        dnaStack.pop();
    }

    return complementary;
}
```

##### **A.3** `complementarySequence3` (required)

In this function, you are going to use the same instructions in `complementarySequence2`, but this time using your own `StackLL< char >`.

##### **A.4** Compiling `complementaryDNA.cpp` 

Open the file `complementaryDNA.cpp`, then try to understand what it does. After that compile it and test:

```
g++ -std=c++11 complementaryDNA.cpp -o complementaryDNA
./complementaryDNA data/hiv1_envelope_gene.fasta
```

If your stack if working correctly, then you should see `VERIFIED!` in the last line.

#### B) DNA Transcription and Translation using Queue

In this part, you are going to work on `rna.hpp` file, where you are required to implement two functions:

##### **B.1** `transcribeDNA` (required)

Given a DNA sequence, return its transcribed RNA. It is a very simple!

1. Make a copy of the DNA.
2. Convert each T (thymine) to U (Uracel).

##### **B.2** `translateRNA` (required)

You are given an RNA, generate the sequence of amino acids (peptide). The idea is simple:

* Convert each 3 neighboring bases (codon) to an amino acid, then take the next triplet and convert it to an amino acid, and so on.
* Use `codon2Aminoacid` function that takes three bases, and returns their corresponding amino acid.
* Use a queue to store the sequence of the generated amino acids.
* After reaching the end of the sequence, populate an `std::string` object with the queue elements (that are inherently ordered).



##### **B.3** Compiling and running `translateDNA.cpp` 

Let's test the DNA translation on a potential gene in the HIV1 virus. This gene is called **Env** (envelope gene) which attaches to the CD4 receptors present on lymphocytes, which makes the HIV1 as a trojan virus that enables them to destroy our immunity system.

```
g++ -std=c++11 translateDNA.cpp -o translateDNA
./translateDNA data/hiv1_envelope_gene.fasta
```

This should give you the protein sequence in this [query page of the Env gene \| NCBI](https://www.ncbi.nlm.nih.gov/protein/AAC82596.1?report=fasta&from=1&to=856).
