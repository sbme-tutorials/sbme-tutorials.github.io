---
layout: page
course: "sbe201"
category: "assignment"
year: "2019"
title:  "Assignment 5: Stacks and Queues"
by: "Asem"
pdf: true
---

## Prerequisites

* Read the \[[Part1: Struct, Stacks, Linked Lists, and Queues]({{ site.baseurl }}{% link 2019/data-structures/notes/4_week4a.md %}){:target="_blank"}\] 
* Read \[[Week 5: More on Structs, Linked Lists, Const-correctness]({{ site.baseurl }}{% link 2019/data-structures/notes/5_week5.md %}){:target="_blank"}\]
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

## Task distribution on the team

**Each member** in the team is **responsible to**:

1. work on a single particular type.
2. implement a linked list for that type.
3. based on the implemented linked list, implement a stack and a queue.
4. based on raw static arrays, implement a stack. 

## Objectives

1. Collaboration in groups, using **git**.  
2. Implement concrete linked list of the following data types:
    1. member 1: `char`, 
    2. member 2: `std::string`,
    3. member 3: `Patient` (defined in `custom_types.hpp`), and
    4. member 4 (if any): `Point` (defined in `custom_types.hpp`).
    5. member 5 (if any): `double`, 
    6. member 6 (if any): `int`, 
3. For each type listed in (2), provide **stack** implementation using:
    * Arrays.
    * Linked Lists.
4. For each type listed in (2), provide **queue** implementation using **linked lists**.
5. Use your new data structures in interesting applications.

## Clone Your Asssignment

Join your group assignment from this [link](https://classroom.github.com/g/dBAuaLsv)

## Deadline

**Tuesday of 26 March 2019, 11:59 PM (PST time)**

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

For example, **member 1** can use the following function prototypes (declarations) that works for linked list of `char`s. Other members can adapt for the other required types:

```c++
void insertFront( CharsLL &list , char data );
void insertBack( CharsLL &list, char data );
void removeFront( CharsLL &list );
void removeBack( CharsLL &list );
void removeNth( CharsLL &list , int index );
void removeNext( CharsLL &list, CharNode *node );
char front( CharsLL &list );
char back( CharsLL &list );
char getNth( CharsLL &list, int index );
bool isEmpty( CharsLL &list );
int size( CharsLL &list );
void printAll( CharsLL &list );
void clear( CharsLL &list );
```

*Realize that we can do better by using `const` qualifier (i.e. `const CharsLL &list`), for the functions that are not supposed to modify the linked list.*

### Stack (ADT)

Each member is required to provide two implementations (using arrays and linked lists) of the stack for the assigned type. For example, **member 1** needs to implement:

1. `CharsStackArray`: using static array of size = 2048 elements (i.e. `char buffer[2048];` as a member in `CharsStackArray`).
2. `CharsStackLL`: using the `CharsLL`.

Supported Operations:

1. `push`.
2. `pop`.
3. `size`.
4. is empty? `isEmpty`.
5. return front `front` (LIFO).
6. delete the whole stack `clear`.

For example,**member 1** can use the following function prototypes (declarations) that works for stack of `char`s (array version). Other members can adapt for the other required types:

```c++
void push( CharsStackArray &stack , char data );
void pop( CharsStackArray &stack );
char front( CharsStackArray &stack );
bool isEmpty( CharsStackArray &stack );
int size( CharsStackArray &stack );
void clear( CharsStackArray &stack );
```

*Realize that we can do better by using `const` qualifier when appropriate*

### Queue (ADT)

Each member is required to provide only one implementation by linked lists for the assigned type. For example, **member 1** needs to implement `CharsQueueLL`.

Supported Operations:

1. `enqueue`.
2. `dequeue`.
3. `size`.
4. `isEmpty`.
5. return `front` (FIFO).
6. delete the whole queue `clear`.

As a guideline, **member 1** can use the following function prototypes (declarations) that works for queue of `char`s (built on Linked Lists). Other members can adapt for the other required types:

```c++
void enqueue( CharsQueueLL &queue , char data );
void dequeue( CharsQueueLL &queue );
char front( CharsQueueLL &queue );
bool isEmpty( CharsQueueLL &queue );
int size( CharsQueueLL &queue );
void clear( CharsQueueLL &queue );
```

*Realize that we can do better by using `const` qualifier when appropriate*

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

In this function, you are going to use the same instructions in `complementarySequence2`, but this time using your own `CharsStackLL`.

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


## Guidelines

These are suggested guidelines to follow, i.e not mandatory.

### Collaboration

1. To avoid conflicts, each member would create a unique header file (e.g `member3.hpp`), to implement his/her share in the task.
2. After creating (or renaming) a file (e.g `member3.hpp`):
    * `git add member3.hpp`
    * `git commit -a -m "add/rename file for member3"`
    * `git pull origin master`
    * `git push origin master`
3. It is recommended that each member wrap his/her own work in a `namespace` representing the data structure he/she works on. For example, `lists`, `stacks`, and `queues`.
4. At the begining, you need for a meeting to settle on a plan for collaboration on the remote repository.
5. It is recommended that each team has a leader, who distributes the load, writes any necessary skeleton codes.