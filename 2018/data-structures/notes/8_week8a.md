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
* **Path:** the sequence of links and nodes to reach from one node to a descedent.
* **Height of node:** the number of links between a node and the furthest leaf.
* **Depth of node:** the number of linkes between a node and the root.

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

#### Removal

#### Clear the tree