---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 8 - Part1: Binary Search Trees and Sets (ADT)"
by: "Asem"
---

* TOC
{:toc}

## Objectives

1. Learn about **graph** structures in a glimpse
1. Specializing a **graph** into **trees**
1. Specializing **trees** into **binary trees**
1. Specializing **trees** into **binary search trees (BST)**
1. Implementing **set** (ADT) using **BST**

## Trees

In previous weeks, we have learned about:

* Arrays
* Linked Lists
* Queues
* Stacks

These structures are conceptually linear structures. However, there also exist very important kind of structures that are inherently non-linear (e.g **trees** and **graphs**). Trees are special case of graphs, where **nodes** and **edges (links)** do not form a cycle.

### Tree Glossary

* **Root:** is the top node in the tree.
* **Child:** any node that is emerged from an upper node.
* **Parent/Internal Node:** node with at least one child.
* **Siblings:** nodes sharing the same parent.
* **Leaf:** node with no children.
* **Edge:** the link between two nodes (i.e a parent and its child).
* **Path:** the sequence of links and nodes to reach from one node to a descedant.
* **Height of node:** the number of links between a node and the furthest leaf.
* **Depth of node:** the number of links between a node and the root.

<img src="/gallery/trees/tree.svg" style="width:80%;">

### Synonyms

* Node = Vertex = Point
* Edge = Link = Arc

### Violating Tree Structure

> wikipedia

The following structures **are not trees**:

| Graphs that are not trees | Why? |
|--------------|----------------|
| <img src="/gallery/trees/Directed_graph,_cyclic.svg" style="width:80%;"> |cycle B→C→E→D→B. <br> B has more than one parent (inbound edge). |
| <img src="/gallery/trees/Directed_graph_with_branching_SVG.svg" style="width:50%;"> |undirected cycle 1-2-4-3. <br> 4 has more than one parent (inbound edge). |
| <img src="/gallery/trees/Directed_graph,_disjoint.svg" style="width:50%;"> | two non-connected parts, A→B and C→D→E. There is more than one root. |

## Binary Search Trees (BST)

**Binary trees** is a special case of trees where each node can have at most 2 children. Also, these children are named: **left child** or **right child**. A very useful specialization of **binary trees** is **binary search tree (BST)** where nodes are conventionally ordered in a certain manner. By convention, the  $$ \text{left children} < \text{parent} < \text{right children} $$, and this rule propagates recursively across the tree.

|  <img src="/gallery/trees/Binary_search_tree.svg"> |
|-------------|
| *A binary search tree (BST)* |

|  <img src="/gallery/trees/graphtreevenn.svg"> |
|-------------|
| *Specialization from graph->tree->BT->BST* |


### Motivation

Efficient search & insertion/deletion in *logarithmic* time $O(\log(n))$

* Arrays:
  * **(+)** efficient search on sorted arrays $O(\log(n))$,
  * **(-)** ineffiecient insertion/deletion $O(n)$.
* Linked lists:
  * **(-)** inefficient search $O(n)$,
  * **(+)** efficient insertion/deletion $O(1)$.

### Intuition

* Tree combines the advantages of arrays and linked lists.
* The nature of **BST** (i.e being ordered) makes it potential for extensive applications. For example, implementing **set (ADT)**.

### Design and Implementation: Using Linked Structures

Tree structure allows us to use recursive routines to implement the basic operations. Think of each node in a tree as a separate standalone tree. Trees can be embedded in arrays or implemented as a linked nodes (i.e using pointers). In this tutorial, we will implement the **BST** using linked nodes. Any node in the tree (including the root) will be represented by the type `BSTNode` that has the following C++ `struct:

```c++
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};
```

### Operations

#### Is Empty

```c++
bool isEmpty( BSTNode *tree )
{
    return tree == nullptr;
}
```

#### Is Leaf

```c++
bool isLeaf( BSTNode *tree )
{
    return tree->left == nullptr && tree->right == nullptr;
}
```

#### Size

```c++
int size( BSTNode *tree )
{
    if ( node )
        return 1 + size( tree->left ) + size( tree->right );
    else return 0;
}
```

#### Insertion

|  <img src="/gallery/trees/binary-search-tree-insertion-animation.gif"> |
|-------------|
| *Insertion in BST, realize recursion. [Author](https://commons.wikimedia.org/w/index.php?title=User:A.gholamzade&action=edit&redlink=1)* |


```c++
void insert( BSTNode *&tree, int data )
{
    if ( isEmpty( tree ))
        tree = new BSTNode{ data , nullptr , nullptr };

    else
    {
        if ( data < tree->data )
            insert( tree->left, data );

        else insert( tree->right, data );
    }
}
```

#### Search

|  <img src="/gallery/trees/binary-search-tree-sorted-array-animation.gif"> |
|-------------|
| *Search in BST, realize recursion. [Author](https://commons.wikimedia.org/w/index.php?title=User:A.gholamzade&action=edit&redlink=1)* |

```c++
bool find( BSTNode *tree, int data )
{
    if ( isEmpty( tree ))
        return false;
    else
    {
        if ( data == tree->data )
            return true;

        else if ( data < tree->data )
            return find( tree->left , data );

        else return find( tree->right , data );
    }
}
```

#### BST Traversal

| Pre- In- Post-order Traversals |
|--------------------------------|
| <script src="https://www.khanacademy.org/computer-programming/depth-first-traversals-of-binary-trees/934024358/embed.js?editor=no&buttons=yes&author=yes&embed=yes"></script> |
| *Made using: [Khan Academy Computer Science](http://www.khanacademy.org/computer-programming)* |

#### Traversal: In-order

|  <img src="/gallery/trees/InorderTrav.gif"> |
|-------------|
| *In-order Traversal in BST, realize recursion. [Source](http://ceadserv1.nku.edu/longa/classes/mat385_resources/docs/traversal.htm)* |

```c++
void inorder( BSTNode *tree )
{
    if( tree )
    {
        inorder( tree->left );
        std::cout << "[" << tree->data << "]";
        inorder( tree->right );
    }
}
```

#### Traversal: Pre-order

|  <img src="/gallery/trees/PreOrderTrav.gif"> |
|-------------|
| *Pre-order Traversal in BST, realize recursion. [Source](http://ceadserv1.nku.edu/longa/classes/mat385_resources/docs/traversal.htm)* |

```c++
void preorder( BSTNode *tree )
{
    if( tree )
    {
        std::cout << "[" << tree->data << "]";
        preorder( tree->left );
        preorder( tree->right );
    }
}
```

#### Traversal: Post-order

|  <img src="/gallery/trees/PostorderTrav.gif"> |
|-------------|
| *Post-order Traversal in BST, realize recursion. [Source](http://ceadserv1.nku.edu/longa/classes/mat385_resources/docs/traversal.htm)* |

```c++
void postorder( BSTNode *tree )
{
    if( tree )
    {
        postorder( tree->left );
        postorder( tree->right );
        std::cout << "[" << tree->data << "]";
    }
}
```

#### Traversal: Breadth-first

|  <img src="/gallery/trees/bfs.gif"> |
|-------------|
| *Breadth-first Traversal in BST. Created by Stephanie Wong* |

#### Clear the whole tree

```c++
void clear( BSTNode *&tree )
{
    if ( !isEmpty( tree ))
    {
        clear( tree->left );
        clear( tree->right );
        delete tree;
        tree = nullptr;
    }
}
```

#### Removal of element

| Case | Action |Example |
|------|--------|--------|
| **Case I:** Node to be removed **has no children** | Simplest case. Algorithm **sets corresponding link of the parent to NULL and deletes the node** |`remove( tree , -4 )`<br>![bst-del1](/gallery/trees/bst-remove-case-1.png) |
| **Case II:** Node to be removed **has one child** | It this case, node is cut from the tree and algorithm **links single child (with it's subtree) directly to the parent of the removed node** |`remove( tree , 18 )`<br>![bst-del2a](/gallery/trees/bst-remove-case-2-1.png)<br>![bst-del2b](/gallery/trees/bst-remove-case-2-2.png)<br>![bst-del2c](/gallery/trees/bst-remove-case-2-3.png) |
| **Case III:** Node to be removed **has two children** | This is the most complex case. To solve it, <br>**(1)** **find a minimum value in the right subtree;** <br>**(2)** **replace value of the node to be removed with found minimum**. Now, right subtree contains a duplicate! <br>**(3)** **apply remove to the right subtree to remove a duplicate.** | ![bst-del3a](/gallery/trees/bst-remove-case-3-3.png) <br> ![bst-del3b](/gallery/trees/bst-remove-case-3-4.png) <br> ![bst-del3c](/gallery/trees/bst-remove-case-3-5.png) <br> ![bst-del3d](/gallery/trees/bst-remove-case-3-6.png) <br> |
| *Source: [http://www.algolist.net/](http://www.algolist.net/Data_structures/Binary_search_tree/Removal)* |

```c++
void remove( BSTNode *&tree, int data )
{
    if ( isEmpty( tree )) return;

    if ( data == tree->data )
    {
        if ( !isEmpty( tree->left ) && !isEmpty( tree->right ))
        {
            BSTNode *minRight = minNode( tree->right );
            tree->data = minRight->data;
            remove( tree->right, minRight->data );
        } else
        {
            BSTNode *discard = tree;

            if ( isLeaf( tree ))
                tree = nullptr;
            else if ( !isEmpty( tree->left ))
                tree = tree->left;
            else
                tree = tree->right;

            delete discard;
        }

    } else if ( data < tree->data )
        remove( tree->left, data );
    else remove( tree->right, data );
}
```

## Asbtract Data Types Built Upon BST

### Set

We can harness the sorted property of **BST** to make efficient insertions and removals. Also, with a slight modification to the `insert` function, we can make this function only insert unique values, hence our new **set (ADT)** will always contain unique values.

http://homepage.divms.uiowa.edu/~ghosh/2116.11.pdf

#### Operations

http://www.shsu.edu/~csc_tjm/summer2000/cs165/CS165L3.html

* `isEmpty`: same as **BST**
* `size`: same as **BST**
* `contains`: same as `find` of **BST**
* `remove`: same as **BST**
* `insert`: slight modification of `bst::insert`, such that insertion is done when the element isn't a duplicate of existing element, possible implementation:
  1. use `contains` to check if element doesn't already exist,
  1. then, if the condition holds, use `bst::insert`, otherwise, do nothing.
* `union`: given two sets $S_1$ and $S_2$ make a new data structure $S_3 = S_1  \cup S_2$, possible implementation:
  1. make an empty set `S3`,
  1. iterate over elements of `S1` inserting each element to `S3`, and similarly for `S2`.
* `intersect`: given two sets $S_1$ and $S_2$ make a new data structure $S_3 = S_1  \cap S_2$, possible implementation:
  1. make an empty set `S3`,
  1. iterate over elements of `S1` inserting each element that also exists in `S2` into `S3`.
* `equals`: given two sets $S_1$ and $S_2$, check the equality of the two sets, possible implementation:
  1. first, check that $S_1$ and $S_2$ sizes are equal,
  1. then, iterating **in-order** in parallel in both $S_1$ and $S_2$ to validate the equality of traversed elements.

### Map

Synonyms: Associative containers, dictionary, symbol table.

A **map** is a collection of searchable key-value pairs, where each key has a value.

**Example 1**, we can have a **map** representing count of words in a page or textbook, so the **key** here is the *word*, while the **value** is the count of this word.

**Example 2**, for the function that counts characters in **DNA**:

```c++
int countCharacter( std::string dna, char query )
    {
        int count = 0;
        for ( int i = 0; i < dna.size(); ++i)
        {
            if ( query == dna[i] )
                ++count;
        }
        return count;
}
int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::string dna = getDNA( argv[1] );

        int countA = countCharacter( dna , 'A');
        int countC = countCharacter( dna , 'C');
        int countG = countCharacter( dna , 'G');
        int countT = countCharacter( dna , 'T');

        std::cout << "A:" << countA << std::endl
                  << "C:" << countC << std::endl
                  << "G:" << countG << std::endl
                  << "T:" << countT << std::endl;
    }

    return 0;
}
```

This function was called four times (i.e to count **A**, **C**, **G**, and **T**). However, by using **map** data structure we can run this function to count all characters in a single run!

```c++
int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::string dna = getDNA( argv[1] );

        char_map::CharMap dnaCounter = char_map::create();

        for( int i = 0 ; i < dna.size() ; ++i )
            map::value( dnaCounter , dna[i] )++;

        char_map::printAll( dnaCounter );
    }

    return 0;
}
```

Another important usage of **map (ADT)** is to implement a **graph (ADT)** by:

1. representing each node in the graph as a **key**,
1. and the associated **value** to that key is a list of the connected nodes.

#### Implementing a Dictionary (i.e Map) Using BST

Map implementation using **BST** would be as easy as implementing a **set** using the concrete routines of **BST**.

1. `create`: returns empty dictionary.
1. `isEmpty`: checks if dictionary is empty.
1. `size`: returns the size of the dictionary.
1. `insert`: inserts new key to the dictionary.
1. `remove`: remove an element by its key.
1. `at`: returns a reference to the value associated with a given dictionary. Crashes if the key is not found.
1. `value`: returns a reference to the value associated with a given key. If key not found, then insert a new key with the given key then returns a reference to the newly created value.
1. `contains`: checks if a key exists in the dictionary.

```c++
struct MapNode
{
    std::string key;
    int value;
    MapNode *left;
    MapNode *right;
};

using WordMap = MapNode *;
```

##### Syntactical Sugar

One usage of C++ aliases, is abstraction of types. In the line `using WordMap = MapNode *;`, we are making an alias for a pointer type naming it `WordMap`. Now, we wish, in the main function, to pay no attention to the implementation details of our map. So, we wish not to see any asterisks (pointer) in the main function.


Since we decided to hide the implementation details in the main function, we hope not to initialize an empty **map** using the following syntax:

```c++
int main()
{
    map::WordMap wmap = nullptr; // Correct. But, something vague here!
}
```

// In the above snippet, we should have a prior knowledge about the alias `WordMap` that represents a pointer, so we initialize it with `nullptr`.


**A much better and clean solution** is to write a function that returns an empty map. Hence, we hid our assumptions and conventions from the **map** user in the main function.

```c++
WordMap create()
{
    return nullptr;
}
```


Now, in the main function it becomes cleaner to have an empty **map** using the following syntax:

```c++
int main()
{
    map::WordMap wmap = map::create(); // Much cleaner!
}
```

```c++
bool isEmpty( WordMap wmap )
{

}

bool isLeaf( WordMap wmap )
{

}

int size( WordMap wmap )
{

}

bool find( WordMap wmap, std::string key )
{

}


int &at( WordMap wmap, std::string key )
{

}

void insert( WordMap &wmap, std::string key )
{

}

WordMap minNode( WordMap wmap )
{

}

void remove( WordMap &wmap, std::string key )
{

}

int &value( WordMap &wmap , std::string key )
{

}

void clear( WordMap &wmap )
{

}

void printAll( WordMap wmap )
{

}
```

### Exercise and Assignment: Text Processing

Clone your group lab work and assignment from this [link](https://classroom.github.com/g/JPz8R-yi).

<iframe width="560" height="315" src="https://www.youtube.com/embed/wupToqz1e2g?rel=0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

Consider the following text for [Carl Sagan](https://en.wikipedia.org/wiki/Carl_Sagan)

> Look again at that dot. That's here. That's home. That's us. On it everyone you love, everyone you know, everyone you ever heard of, every human being who ever was, lived out their lives. The aggregate of our joy and suffering, thousands of confident religions, ideologies, and economic doctrines, every hunter and forager, every hero and coward, every creator and destroyer of civilization, every king and peasant, every young couple in love, every mother and father, hopeful child, inventor and explorer, every teacher of morals, every corrupt politician, every "superstar," every "supreme leader," every saint and sinner in the history of our species lived there on a mote of dust suspended in a sunbeam. The Earth is a very small stage in a vast cosmic arena. Think of the rivers of blood spilled by all those generals and emperors so that, in glory and triumph, they could become the momentary masters of a fraction of a dot. Think of the endless cruelties visited by the inhabitants of one corner of this pixel on the scarcely distinguishable inhabitants of some other corner, how frequent their misunderstandings, how eager they are to kill one another, how fervent their hatreds. Our posturings, our imagined self-importance, the delusion that we have some privileged position in the Universe, are challenged by this point of pale light. Our planet is a lonely speck in the great enveloping cosmic dark. In our obscurity, in all this vastness, there is no hint that help will come from elsewhere to save us from ourselves. The Earth is the only world known so far to harbor life. There is nowhere else, at least in the near future, to which our species could migrate. Visit, yes. Settle, not yet. Like it or not, for the moment the Earth is where we make our stand. It has been said that astronomy is a humbling and character-building experience. There is perhaps no better demonstration of the folly of human conceits than this distant image of our tiny world. To me, it underscores our responsibility to deal more kindly with one another, and to preserve and cherish the pale blue dot, the only home we've ever known.

#### Prelimenary Statistics

| Total count of words | count of words after removing duplicates (i.e word set) |
|----------------------|-----------------------|
| 362 | 205 |


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

#### Lab work: Extract Set of Words in a Text using Set (ADT)

1. Complete the source code in `set.hpp` to produce a **set** of `std::string`s.
1. Complete the source code in `unique_words.cpp` to print the set of words of the given file.

#### Group Assignment 1-A: Implement a Dictionary That Maps Characters to Integers

You are required here to develop a dictionary that has `char` as a key and `int` as a value. We will use this dictionary to keep track of each character count.

1. Complete the implementation in `cmap.hpp`, to produce a a dictionary that maps `char` to `int`.
1. Complete the source code in `countDNA.cpp`, to count each base in the given dna file using the developed **dictionary**.

#### Group Assignment 2-B: Evaluate the count of each word in a text using Map (ADT)

1. Complete the implementation in the `map.hpp` file to produce a **dictionary** that maps `std::string` to `int`.
1. Complete the source code in `count_words.cpp` to count each word in the given text file.