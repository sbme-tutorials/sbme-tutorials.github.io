---
layout: presentation
style: laminal4
highlighter: github
course: "sbe201"
category: "presentation"
year: "2019"
title: "Week 7: Binary Search Trees, Sets (ADT) and Maps (ADT)"
by: "Asem"
author: "Asem Alaa"
---

<!-- ir-black -->
<!-- solarized-light -->
<!-- tomorrow-night-blue -->
<!-- tomorrow-night-bright -->
<!-- tomorrow-night-eighties -->
<textarea id="source">


---
## Stack (ADT) .red[not] LinkedList .red[not] Array

--
```c++
struct IntLinkedList
{
    IntNode *front;
};

void removeFront( IntLinkedList &l )
{
    // Logic
}
```

---
## Stack (ADT) .red[not] LinkedList .red[not] Array
### .red[Never do that]

```c++
using IntStackLL = IntLinkedList;
```

--
.center[<img style="width:90%" src="maxresdefault.jpg">]


---
## Stack (ADT) .red[not] LinkedList .red[not] Array
### .red[Never do that]


--
```c++
using IntStackLL = IntLinkedList;

void pop( IntStackLL &l )
{
    removeFront( l );
}
```

--
```c++
int main()
{
    IntStackLL stack;
    pop( stack ); // No stack violation.
    removeNth( stack , 2 ); // Stack violation!
}
```

---
## Stack (ADT) .red[not] LinkedList .red[not] Array
### .green[Solution]


```c++
struct IntLinkedList
{
    IntNode *front;
};

struct IntStackLL
{
    IntNode *front;
};

void removeFront( IntLinkedList &l )
{
    // Logic
}

void pop( IntStackLL &s )
{
    IntLinkedList delegate { s.front };
    removeFront( delegate );
    s.front = delegate.front;
}
```

---
## Stack (ADT) .red[not] LinkedList .red[not] Array
### .green[Solution]


--
.center[<img style="width:85%" src="bean.jpg">]


---
## Trees

--
.center[![](trees1.jpg)]

---
## Trees


.center[![](trees2.jpg)]

---
## Trees


--
### Objectives

1. Learn about **graph** structures in a glimpse
2. Specializing a **graph** into **trees**
3. Specializing **trees** into **binary trees**
4. Specializing **trees** into **binary search trees (BST)**
5. Implementing **set** (ADT) using **BST**


---
## Trees

In previous weeks, we have learned about:

1. Arrays
2. Linked Lists
3. Queues
4. Stacks


* These structures are conceptually linear structures. 
* However, there also exist non-linear (e.g **trees** and **graphs**). 
* **Trees** are special case of **graphs**, where **nodes** and **edges (links)** do not form a cycle.


---
### Tree Glossary

* **Root:** is the top node.
* **Child:** any node that is emerged from an upper node.
* **Parent/Internal Node:** node with at least one child.
* **Siblings:** nodes sharing the same parent.
* **Leaf:** node with no children.
* **Edge:** the link between two nodes.
* **Path:** the sequence of links and nodes to reach from one node to a descedant.
* **Height of node:** the number of links between a node and the furthest leaf.
* **Depth of node:** the number of links between a node and the root.


---
<img src="/gallery/trees/tree.svg" style="width:80%;">


---
### Synonyms

* Node = Vertex = Point
* Edge = Link = Arc


---
### Violating Tree Structure

---
#### The following structures **are not tree**
<img src="/gallery/trees/Directed_graph,_cyclic.svg" style="width:80%;"> 

---
#### The following structures **are not tree**
<img src="/gallery/trees/Directed_graph_with_branching_SVG.svg" style="height:80%;">

---
#### The following structures **are not tree**
<img src="/gallery/trees/Directed_graph,_disjoint.svg" style="height:80%;">


---
## Binary Search Trees (BST)

* **Binary trees** is a special case of trees where each node can have at most 2 children. 
* Also, these children are named: **left child** or **right child**. 
* A very useful specialization of **binary trees** is **binary search tree (BST)**
* $$ \text{left children} < \text{parent} < \text{right children} $$, 
* and this rule propagates recursively across the tree.

---
<img src="/gallery/trees/Binary_search_tree.svg" style="width:80%;">

---
<img src="/gallery/trees/graphtreevenn.svg" style="width:80%;">


---
### Motivation

Efficient search & insertion/deletion in *logarithmic* time $O(\log(n))$

* Arrays:
  * **(+)** efficient search on sorted arrays $O(\log(n))$,
  * **(-)** ineffiecient insertion/deletion $O(n)$.
* Linked lists:
  * **(-)** inefficient search $O(n)$,
  * **(+)** efficient insertion/deletion $O(1)$.



---
### Intuition

* Tree combines the advantages of arrays and linked lists.
* The nature of **BST** (i.e being ordered) makes it potential for extensive applications.

---
### Design and Implementation: Using Linked Structures

* Recursion: Think of each node in a tree as a separate standalone tree. 
* ADT: Trees can be embedded in arrays or implemented as a linked nodes (i.e using pointers). 
* In this tutorial, we will implement the **BST** using linked nodes. 
* Any node in the tree (including the root) will be represented by the type `BSTNode`


---
#### Node structure

--
```c++
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};
```


---
### Operations


---
#### Is Empty


--
```c++
bool isEmpty( BSTNode *tree )
{
    return tree == nullptr;
}
```

---
#### Is Leaf


--
```c++
bool isLeaf( BSTNode *tree )
{
    return tree->left == nullptr && tree->right == nullptr;
}
```


---
#### Size


--
```c++
int size( BSTNode *tree )
{
    if ( !isEmpty( tree ) )
        return 1 + size( tree->left ) + size( tree->right );
    else return 0;
}
```

---
#### Insertion

--
<img src="/gallery/trees/binary-search-tree-insertion-animation.gif" style="width:80%;">


---


--
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


---
#### Search

<img src="/gallery/trees/binary-search-tree-sorted-array-animation.gif">

---

--
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


---
#### BST Traversal

<script src="https://www.khanacademy.org/computer-programming/depth-first-traversals-of-binary-trees/934024358/embed.js?editor=no&buttons=yes&author=yes&embed=yes"></script>

---
#### Traversal: In-order

<img src="/gallery/trees/InorderTrav.gif" style="width:80%;">


---

--
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

---
#### Traversal: Pre-order

<img src="/gallery/trees/PreOrderTrav.gif" style="width:80%;">

---

--
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

---
#### Traversal: Post-order

<img src="/gallery/trees/PostorderTrav.gif" style="width:80%;"> 

---

--
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

---
#### Traversal: Breadth-first

<img src="/gallery/trees/bfs.gif" style="width:80%;">

---
#### Clear the whole tree


--
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

---
#### Removal of element


---
##### **Case I:** Node to be removed **has no children** 

###### Example: `remove( tree , -4 )`

![bst-del1](/gallery/trees/bst-remove-case-1.png)


---
##### **Case II:** Node to be removed **has one child**

###### Example: `remove( tree , 18 )`

---
##### **Case II:** Node to be removed **has one child**
![bst-del2a](/gallery/trees/bst-remove-case-2-1.png)


---
##### **Case II:** Node to be removed **has one child**
![bst-del2b](/gallery/trees/bst-remove-case-2-2.png)


---
##### **Case II:** Node to be removed **has one child**
![bst-del2c](/gallery/trees/bst-remove-case-2-3.png)


---
##### **Case III:** Node to be removed **has two children**

###### Example: `remove( tree , 18 )`

---
##### **Case II:** Node to be removed **has one child**
![bst-del3a](/gallery/trees/bst-remove-case-3-3.png)

---
##### **Case II:** Node to be removed **has one child**
![bst-del3b](/gallery/trees/bst-remove-case-3-4.png) 

---
##### **Case II:** Node to be removed **has one child**
![bst-del3c](/gallery/trees/bst-remove-case-3-5.png)

---
##### **Case II:** Node to be removed **has one child**
![bst-del3d](/gallery/trees/bst-remove-case-3-6.png)

---
```c++
void remove( BSTNode *&tree, int data )
{
    if ( isEmpty( tree )) return;
    if ( data == tree->data ) removeNode( tree );
    else if ( data < tree->data ) remove( tree->left, data );
    else remove( tree->right, data );
}
```

---
```c++
void removeNode( BSTNode *&tree )
{
    if ( !isEmpty( tree->left ) && !isEmpty( tree->right ))
    {
        BSTNode *minRight = minNode( tree->right );
        tree->data = minRight->data;
        remove( tree->right, minRight->data );
    } else
    {
        BSTNode *discard = tree;

        if ( isLeaf( tree )) tree = nullptr;
        else if ( !isEmpty( tree->left )) tree = tree->left;
        else tree = tree->right;

        delete discard;
    }
}
```

---
class: center, middle

## .red[**Tutorial 7 ENDS HERE**]

---
class: left, top

## Abstract Data Types Built Upon BST

---
### Set

* **BST**: efficient insertions and removals.
--
* **modification**: in `insert` function, only insert unique values,
--
* Then, **set on BST (ADT)** will always contain unique values.

---
#### Operations

--
* `set::isEmpty` = `bst::isEmpty`
--
* `set::size` = `bst::size`
--
* `set::contains` = `bst::find`
--
* `set::remove` = `bst::remove`

---
#### Set: Add

--
* Slight modification of `bst::insert`,
* insertion is done only when it is not a duplicate of existing element

--
##### BST Insertion

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

---

##### Set: Insertion (solution 1)

1. use `contains` to check if the element doesn't already exist,
1. if the condition holds, use `bst::insert`, otherwise, do nothing.

--
```c++
void add( BSTNode *&tree, int data )
{
    if( !contains( tree, data ))
    {
        insert( tree, data );
    }
}
```

--
Growth function (average case) $$T(n) \approx 2 \log_2(n)$$

--
.green[Can we do better?]

---

##### Set: Insertion (solution 2)

1. Preserve uniqueness in the insertion routine.

--
```c++
void add( BSTNode *&tree, int data ) // Copy routine of `insert`
{
    if ( isEmpty( tree ))
        tree = new BSTNode{ data , nullptr , nullptr };
    else
    {
        if ( data < tree->data )
            add( tree->left, data );

        else add( tree->right, data );
    }
}
```


---

##### Set: Insertion (solution 2)

1. Preserve uniqueness in the insertion routine.


```c++
void add( BSTNode *&tree, int data )
{
    if ( isEmpty( tree ))
        tree = new BSTNode{ data , nullptr , nullptr };
    else
    {
        if ( data < tree->data )
            add( tree->left, data );

        else if( data > tree->data )
            add( tree->right, data );

        // If `data` happens to equal `tree->data`, then we are not in business.
        // So uniqueness is guaranteed here.
    }
}
```

--
Growth function (average case) $$T(n) \approx \log_2(n)$$

---
#### Set: Union

* `union`: given two sets $S_1$ and $S_2$ make a new data structure $S_3 = S_1  \cup S_2$

##### possible implementation:

--
1. make an empty set `S3`,
--
1. iterate over elements of `S1` inserting each element to `S3`, and similarly for `S2`.

---
#### Set: Intersect

* `intersect`: given two sets $S_1$ and $S_2$ make a new data structure $S_3 = S_1  \cap S_2$


##### possible implementation:

--
1. make an empty set `S3`,
--
1. iterate over elements of `S1` inserting each element that also exists in `S2` into `S3`.


---
#### Set: Equals

* `equals`: given two sets $S_1$ and $S_2$, check the equality of the two sets,

##### possible implementation:
  
1. first, check that $S_1$ and $S_2$ sizes are equal,
1. then, iterating **in-order** in parallel in both $S_1$ and $S_2$ to validate the equality of traversed elements.

---
#### Set Declarations (Procedural)

--
```c++
struct IntSet
{
    BSTNode *root = nullptr;
};

bool isEmpty( const IntSet &s ){ /* DRY */}

bool contains( const IntSet &s ){ /* DRY */ }

int size( const IntSet &s ){ /* DRY */}

void remove( const IntSet &s , int data ){ /* DRY */ }

void add( const IntSet &s, int data ){/* Logic */ }

void clear( IntSet &s ){/* DRY */}

bool equals( const IntSet &s1, const IntSet &s2 ){/* Logic */}

IntSet intersection( const IntSet &s1, const IntSet &s2 ){ /* Logic */}

IntSet union( const IntSet &s1, const IntSet &s2 ){ /* Logic */}

std::vector< int > enumerate( const IntSet &s1 ){ /* Logic */ }
```

---
#### Set Declarations (OOP)

--
```c++
struct IntSet
{
    BSTNode *root = nullptr;

    bool isEmpty( const IntSet &s ){ /* DRY */}

    bool contains( const IntSet &s ){ /* DRY */ }

    int size( const IntSet &s ){ /* DRY */}

    void remove( const IntSet &s , int data ){ /* DRY */ }

    void add( const IntSet &s, int data ){/* Logic */ }

    void clear( IntSet &s ){/* DRY */}

    bool equals( const IntSet &s1, const IntSet &s2 ){/* Logic */}

    IntSet intersection( const IntSet &s1, const IntSet &s2 ){ /* Logic */}

    IntSet union( const IntSet &s1, const IntSet &s2 ){ /* Logic */}

    std::vector< int > enumerate( const IntSet &s1 ){ /* Logic */ }
};
```

---
#### Set Declarations (OOP)

```c++
struct IntSet
{
    BSTNode *root = nullptr;

    bool isEmpty() const { /* DRY */}

    bool contains() const { /* DRY */ }

    int size() const { /* DRY */}

    void remove( int data ) const { /* DRY */ }

    void add( int data ) const {/* Logic */ }

    void clear(){/* DRY */}

    bool equals( const IntSet &s2 ) const {/* Logic */}

    IntSet intersection( const IntSet &s2 ) const { /* Logic */}

    IntSet union( const IntSet &s2 ) const { /* Logic */}

    std::vector< int > enumerate(){ /* Logic */ }
};
```

---
#### Set Declarations (OOP + Encapsulation)

--
```c++
struct IntSet
{
private:
    BSTNode *root = nullptr;
public:
    bool isEmpty() const { /* DRY */}

    bool contains() const { /* DRY */ }

    int size() const { /* DRY */}

    void remove( int data ) const { /* DRY */ }

    void add( int data ) const {/* Logic */ }

    void clear(){/* DRY */}

    bool equals( const IntSet &s2 ) const {/* Logic */}

    IntSet intersection( const IntSet &s2 ) const { /* Logic */}

    IntSet union( const IntSet &s2 ) const { /* Logic */}

    std::vector< int > enumerate(){ /* Logic */ }
};
```

---
#### Set Declarations (OOP + Encapsulation + Template)


--
```c++
template< typename T>
struct BSTNode
{
    BSTNode( T val )
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    T data
    BSTNode *left;
    BSTNode *right;
};
```

---
#### Set Declarations (OOP + Encapsulation + Template)


```c++

struct IntSet
{
private:
    BSTNode< int > *root = nullptr;
public:
    bool isEmpty() const { /* DRY */}

    bool contains() const { /* DRY */ }

    int size() const { /* DRY */}

    void remove( int data ) const { /* DRY */ }

    void add( int data ) const {/* Logic */ }

    void clear(){/* DRY */}

    bool equals( const IntSet &s2 ) const {/* Logic */}

    IntSet intersection( const IntSet &s2 ) const { /* Logic */}

    IntSet union( const IntSet &s2 ) const { /* Logic */}

    std::vector< int > enumerate(){ /* Logic */ }
};
```

---
#### Set Declarations (OOP + Encapsulation + Template)


```c++
template< typename T >
struct Set
{
private:
    BSTNode< T > *root = nullptr;
public:
    bool isEmpty() const { /* DRY */}

    bool contains() const { /* DRY */ }

    int size() const { /* DRY */}

    void remove( T data ) const { /* DRY */ }

    void add( T data ) const {/* Logic */ }

    void clear(){/* DRY */}

    bool equals( const Set &s2 ) const {/* Logic */}

    IntSet intersection( const Set &s2 ) const { /* Logic */}

    IntSet union( const Set &s2 ) const { /* Logic */}

    std::vector< T > enumerate(){ /* Logic */ }
};
```

---

### Map

Synonyms: Associative containers, dictionary, symbol table.

A **map** is a collection of searchable key-value pairs, where each key has a value.

---

#### Map: Example 1

we can have a **map** representing count of words in a page or textbook, so:

--
1. the **key** here is the *word*,
1. while the **value** is the count of this word.

---

#### Map: Example 2

for the function that counts characters in **DNA**:

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
    }
    return 0;
}
```

---

#### Map: Example 2

##### Elegant solution

* `countCharacter` was called four times (i.e to count **A**, **C**, **G**, and **T**).
* However, by using **map** data structure we can run this function to count all characters in a single run!

---

```c++
#include <map>
int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::string dna = getDNA( argv[1] );

        std::map< char, int > dnaCounter;

        for( int i = 0 ; i < dna.size() ; ++i )
            dnaCounter[ dna[i] ]++;
    }

    return 0;
}
```

---

#### Implementing a Dictionary (i.e Map) Using BST

Map implementation using **BST** would be as easy as implementing a **set** using the concrete routines of **BST**.

1. `isEmpty`: checks if dictionary is empty.
1. `size`: returns the size of the dictionary.
1. `insert`: inserts new key to the dictionary.
1. `remove`: remove an element by its key.
1. `at`: returns a reference to the value associated with a given dictionary. Crashes if the key is not found.
1. `value`: returns a reference to the value associated with a given key. If key not found, then insert a new key with the given key then returns a reference to the newly created value.
1. `contains`: checks if a key exists in the dictionary.

---

#### Dictionary Node Structure

* Consider a dictionary that maps words to counts.

--
```c++
struct BSTNode
{
    std::string data;
    BSTNode *left;
    BSTNode *right;
};
```

---

#### Dictionary Node Structure

* Consider a dictionary that maps words to counts.


```c++
struct MapNode
{
    std::string data;
    MapNode *left;
    MapNode *right;
};
```

---

#### Dictionary Node Structure

* Consider a dictionary that maps words to counts.

```c++
struct MapNode
{
    std::string key;
    int value;
    MapNode *left;
    MapNode *right;
};
```

---

#### Dictionary Node Structure

* Consider a dictionary that maps words to counts.

```c++
struct MapNode
{
    MapNode( const std::string &k, int v )
    {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }

    std::string key;
    int value;
    MapNode *left;
    MapNode *right;
};
```


---
```c++
bool isEmpty( const MapNode *wmap )
{

}

bool isLeaf( const MapNode *wmap )
{

}

int size( const MapNode *wmap )
{

}

bool find( const MapNode *wmap, const std::string &key )
{

}
```

---
```c++
void insert( MapNode * &wmap, const std::string &key, int data )
{

}

void remove( WordMap * &wmap, const std::string &key )
{

}

void clear( MapNode * &wmap )
{

}

void printAll( const MapNode *wmap )
{

}
```

---
#### Map: value


```c++
int &value( MapNode *&wmap, const std::string &key )
{

}
```

---

#### Map Declarations (procedural)

```c++
bool isEmpty( const MapNode *wmap ){ /* Logic */ }

bool isLeaf( const MapNode *wmap ){ /* Logic */ }

int size( const MapNode *wmap ){ /* Logic */ }

bool find( const MapNode *wmap, const std::string &key ){ /* Logic */}

void insert( MapNode * &wmap, const std::string &key, int data ){ /* Logic */}

void remove( WordMap * &wmap, const std::string &key ){ /* Logic */}

void clear( MapNode * &wmap ){ /* Logic */}

void printAll( const MapNode *wmap ){ /* Logic */}

int &value( MapNode *&wmap, const std::string &key ){ /* Logic */}
```

---

#### Map Declarations (OOP)

--
```c++
struct Map
{
    MapNode *root = nullptr;

    bool isEmpty( const MapNode *wmap ){ /* Logic */ }

    bool isLeaf( const MapNode *wmap ){ /* Logic */ }

    int size( const MapNode *wmap ){ /* Logic */ }

    bool find( const MapNode *wmap, const std::string &key ){ /* Logic */}

    void insert( MapNode * &wmap, const std::string &key, int data ){ /* Logic */}

    void remove( WordMap * &wmap, const std::string &key ){ /* Logic */}

    void clear( MapNode * &wmap ){ /* Logic */}

    void printAll( const MapNode *wmap ){ /* Logic */}

    int &value( MapNode *&wmap, const std::string &key ){ /* Logic */}
}
```

---

#### Map Declarations (OOP)

```c++
struct Map
{
    MapNode *root = nullptr;

    bool isEmpty() const { /* Logic */ }

    bool isLeaf() const { /* Logic */ }

    int size() const { /* Logic */ }

    bool find( const std::string &key ) const { /* Logic */}

    void insert( const std::string &key, int data ){ /* Logic */}

    void remove(const std::string &key ) { /* Logic */}

    void clear(){ /* Logic */}

    void printAll() const { /* Logic */}

    int &value( const std::string &key ){ /* Logic */}
}
```

--
* .red[What is the problem?]
--
* Hint: recursive functions!


---

#### Map Declarations (OOP)

```c++
struct Map
{
    MapNode *root = nullptr;

    ...

    int size() const { /* Logic */ }

    int size( const Map *root )
    {
        if( root )
        {
            return 1 + size( root->left ) + size( root->right );
        } else return 0;
    }
    ...
}
```

---

#### Map Declarations (OOP)

```c++
struct Map
{
    MapNode *root = nullptr;

    ...

    int size() const {  return size( root ); }

    int size( const Map *root ) // Method or free function?!
    {
        if( root )
        {
            return 1 + size( root->left ) + size( root->right );
        } else return 0;
    }
    ...
}
```

--
* `static` methods.

---

#### Map Declarations (OOP)

```c++
struct Map
{
    MapNode *root = nullptr;

    ...

    int size() const {  return size( root ); }

    static int size( const Map *root ) // Method or free function?!
    {
        if( root )
        {
            return 1 + size( root->left ) + size( root->right );
        } else return 0;
    }
    ...
}
```

--

```c++
// Client part
Map m;
std::cout << m.size();
```

---

#### Map Declarations (OOP)

```c++
struct Map
{
    MapNode *root = nullptr;

    bool isEmpty() const { /* Logic */ }
    bool isLeaf() const { /* Logic */ }

    int size() const { /* Logic */ }
    bool find( const std::string &key ) const { /* Logic */}
    void insert( const std::string &key, int data ){ /* Logic */}
    void remove(const std::string &key ) { /* Logic */}
    void clear(){ /* Logic */}
    void printAll() const { /* Logic */}
    int &value( const std::string &key ){ /* Logic */}
}
```

---
#### Map Declarations (OOP)

```c++
struct Map
{
    MapNode *root = nullptr;

    bool isEmpty() const { /* Logic */ }
    bool isLeaf() const { /* Logic */ }

    int size() const { return size( root ); }
    bool find( const std::string &key ) const { return find( root , key ); }
    void insert( const std::string &key, int data ){ insert( root , key, data );}
    void remove(const std::string &key ) { remove( root , key);}
    void clear(){ clear( root ); }
    void printAll() const { printAll( root ); }
    int &value( const std::string &key ){  return value( root , key ); }
}
```

---
#### Map Declarations (OOP)

```c++
struct Map
{

    MapNode *root = nullptr;

    bool isEmpty() const { /* Logic */ }
    bool isLeaf() const { /* Logic */ }

    int size() const { return size( root ); }
    bool find( const std::string &key ) const { return find( root , key ); }
    void insert( const std::string &key, int data ){ insert( root , key, data );}
    void remove(const std::string &key ) { remove( root , key);}
    void clear(){ clear( root ); }
    void printAll() const { printAll( root ); }
    int &value( const std::string &key ){  return value( root , key ); }

    static int size( const MapNode *root ) { /* Logic */ }
    static bool find( const MapNode *root, const std::string &key ) { /* Logic */}
    static void insert(  MapNode *&root , const std::string &key, int data ){ /* Logic */}
    static void remove(  MapNode *&root , const std::string &key ) { /* Logic */}
    static void clear(  MapNode *&root ){ /* Logic */}
    static void printAll( const MapNode *root ) { /* Logic */}
    static int &value(  MapNode *&root , const std::string &key ){ /* Logic */}
}
```

---
#### Map Declarations (OOP + Encapsulation)

```c++
struct Map
{
private:
    MapNode *root = nullptr;
public:
    bool isEmpty() const { /* Logic */ }
    bool isLeaf() const { /* Logic */ }

    int size() const { return size( root ); }
    bool find( const std::string &key ) const { return find( root , key ); }
    void insert( const std::string &key, int data ){ insert( root , key, data );}
    void remove(const std::string &key ) { remove( root , key);}
    void clear(){ clear( root ); }
    void printAll() const { printAll( root ); }
    int &value( const std::string &key ){  return value( root , key ); }
private:
    static int size( const MapNode *root ) { /* Logic */ }
    static bool find( const MapNode *root, const std::string &key ) { /* Logic */}
    static void insert(  MapNode *&root , const std::string &key, int data ){ /* Logic */}
    static void remove(  MapNode *&root , const std::string &key ) { /* Logic */}
    static void clear(  MapNode *&root ){ /* Logic */}
    static void printAll( const MapNode *root ) { /* Logic */}
    static int &value(  MapNode *&root , const std::string &key ){ /* Logic */}
}
```

---
#### Map Declarations (OOP + Encapsulation + Template)


--
```c++

struct MapNode
{
    MapNode( const std::string &k, int v )
    {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }

    std::string key;
    int value;
    MapNode *left;
    MapNode *right;
};
```

---
#### Map Declarations (OOP + Encapsulation + Template)


```c++
template< typename K, typename V >
struct MapNode
{
    MapNode( const K &k, V v )
    {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }

    K key;
    V value;
    MapNode *left;
    MapNode *right;
};
```

---
#### Map Declarations (OOP + Encapsulation + Template)

```c++

struct Map
{
private:
    MapNode *root = nullptr;
public:
    bool isEmpty() const { /* Logic */ }
    bool isLeaf() const { /* Logic */ }

    int size() const { return size( root ); }
    bool find( const std::string &key ) const { return find( root , key ); }
    void insert( const std::string &key, int data ){ insert( root , key, data );}
    void remove(const std::string &key ) { remove( root , key);}
    void clear(){ clear( root ); }
    void printAll() const { printAll( root ); }
    int &value( const std::string &key ){  return value( root , key ); }
private:
    static int size( const MapNode *root ) { /* Logic */ }
    static bool find( const MapNode *root, const std::string &key ) { /* Logic */}
    static void insert(  MapNode *&root , const std::string &key, int data ){ /* Logic */}
    static void remove(  MapNode *&root , const std::string &key ) { /* Logic */}
    static void clear(  MapNode *&root ){ /* Logic */}
    static void printAll( const MapNode *root ) { /* Logic */}
    static int &value(  MapNode *&root , const std::string &key ){ /* Logic */}
}
```

---
#### Map Declarations (OOP + Encapsulation + Template)

```c++
template< typename K, typename V>
struct Map
{
private:
    MapNode< K, V > *root = nullptr;
public:
    bool isEmpty() const { /* Logic */ }
    bool isLeaf() const { /* Logic */ }

    int size() const { return size( root ); }
    bool find( const K &key ) const { return find( root , key ); }
    void insert( const K &key, int data ){ insert( root , key, data );}
    void remove(const K &key ) { remove( root , key);}
    void clear(){ clear( root ); }
    void printAll() const { printAll( root ); }
    int &value( const K &key ){  return value( root , key ); }
private:
    static int size( const MapNode *root ) { /* Logic */ }
    static bool find( const MapNode *root, const K &key ) { /* Logic */}
    static void insert(  MapNode *&root , const K &key, V data ){ /* Logic */}
    static void remove(  MapNode *&root , const K &key ) { /* Logic */}
    static void clear(  MapNode *&root ){ /* Logic */}
    static void printAll( const MapNode *root ) { /* Logic */}
    static V &value(  MapNode *&root , const K &key ){ /* Logic */}
}
```

---
### Exercise and Assignment: Text Processing

Clone your group lab work and assignment from this link: TBA.

<iframe width="560" height="315" src="https://www.youtube.com/embed/wupToqz1e2g?rel=0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>


---
Consider the following text for [Carl Sagan](https://en.wikipedia.org/wiki/Carl_Sagan)

.smaller[Look again at that dot. That's here. That's home. That's us. On it everyone you love, everyone you know, everyone you ever heard of, every human being who ever was, lived out their lives. The aggregate of our joy and suffering, thousands of confident religions, ideologies, and economic doctrines, every hunter and forager, every hero and coward, every creator and destroyer of civilization, every king and peasant, every young couple in love, every mother and father, hopeful child, inventor and explorer, every teacher of morals, every corrupt politician, every "superstar," every "supreme leader," every saint and sinner in the history of our species lived there on a mote of dust suspended in a sunbeam. The Earth is a very small stage in a vast cosmic arena. Think of the rivers of blood spilled by all those generals and emperors so that, in glory and triumph, they could become the momentary masters of a fraction of a dot. Think of the endless cruelties visited by the inhabitants of one corner of this pixel on the scarcely distinguishable inhabitants of some other corner, how frequent their misunderstandings, how eager they are to kill one another, how fervent their hatreds. Our posturings, our imagined self-importance, the delusion that we have some privileged position in the Universe, are challenged by this point of pale light. Our planet is a lonely speck in the great enveloping cosmic dark. In our obscurity, in all this vastness, there is no hint that help will come from elsewhere to save us from ourselves. The Earth is the only world known so far to harbor life. There is nowhere else, at least in the near future, to which our species could migrate. Visit, yes. Settle, not yet. Like it or not, for the moment the Earth is where we make our stand. It has been said that astronomy is a humbling and character-building experience. There is perhaps no better demonstration of the folly of human conceits than this distant image of our tiny world. To me, it underscores our responsibility to deal more kindly with one another, and to preserve and cherish the pale blue dot, the only home we've ever known.]


---
#### Prelimenary Statistics

| Total count of words | count of words after removing duplicates (i.e word set) |
|----------------------|-----------------------|
| 362 | 205 |


---
#### Comparing `std::string`s

```c++
#include <string>
int main()
{
    std::string s1 = "batman";
    std::string s2 = "superman";

    int comparison = s1.compare( s2 );
}
```

---
| comparison value | explanation |
|------------------|-------------|
| positive | it means that `s1` comes after `s2` alphabetically, which is not the case |
| negative | it means that `s1` precedes `s2` alphabetically, which is the case |
| 0 | it means that `s1` equals `s2`, which is not the case |

---
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

---
### Individual assignment make-up

--
* Assignment on the linked lists, stacks, queues.
--
* To survive late penalty and team work penalty.
--
* Practice OOP.
--
* Practice Templates.
--
* Practice Const-correctness.
--
* Practice Encapsulation (access modifiers)
--
* Practice Enum classes and constructors.
--
* [Make-up individual assignment (Linked Lists, Stacks, and Queues)]({{ site.baseurl }}{% link 2019/data-structures/assignments/5_week5remake.md %}){:target="_blank"}



</textarea>
