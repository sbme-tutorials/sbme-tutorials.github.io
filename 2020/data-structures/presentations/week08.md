---
layout: presentation
style: laminal
highlighter: ir-black
code: "SBE201"
course: "SBE201 Data Structures and Algorithms"
category: "presentation"
semester: "Spring"
year: "2020"
title: "Section 7: Binary Search Trees (BST), Sets (ADT) and Maps (ADT)"
by: "Asem Alaa"
author: "Asem Alaa"
---



<textarea id="source" markdown="1">

# Section 8

## Binary Search Trees (BST), Sets (ADT) and Maps (ADT)

##### Presentation by *{{ page.author }}*

{% include presentation-margins.html %}

---
class: small
### Tree

<img src="/gallery/trees/tree.svg" style="width:80%;">

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
### Tree

<img src="/gallery/trees/tree.svg" style="width:80%;">


### Synonyms

* Node = Vertex = Point
* Edge = Link = Arc


---
### Violating Tree Structure

#### The following structure **is not tree**

.center[<img  src="/gallery/trees/Directed_graph,_cyclic.svg" style="width:80%;"> ]

---
### Violating Tree Structure

#### The following structures **is not tree**

.center[<img  src="/gallery/trees/Directed_graph_with_branching_SVG.svg" style="height:80%;">]

---
### Violating Tree Structure

#### The following structures **is not tree**

.center[<img src="/gallery/trees/Directed_graph,_disjoint.svg" style="height:80%;">]


---
## Binary Search Trees (BST)

* **Binary trees** is a special case of trees where each node can have at most 2 children. 
* Also, these children are named: **left child** or **right child**. 
* A very useful specialization of **binary trees** is **binary search tree (BST)**
* left children < parent < right children, 
* and this rule applies recursively across the tree.

---
## Binary Search Trees (BST)

.center[<img src="/gallery/trees/Binary_search_tree.svg" style="width:80%;">]

---
## Binary Search Trees (BST)

.center[<img src="/gallery/trees/graphtreevenn.svg" style="width:80%;">]


---
## Binary Search Trees (BST)

### Motivation

Efficient search/insertion/deletion in *logarithmic* time $O(\log(n))$

* Arrays:
  * .green[efficient search] on sorted arrays $O(\log(n))$,
  * .red[ineffiecient insertion/deletion] $O(n)$.
* Linked lists:
  * .red[inefficient search] $O(n)$,
  * .green[efficient insertion/deletion] $O(1)$.

---
## Binary Search Trees (BST)

### Intuition

* Tree combines the advantages of arrays and linked lists.
* Properties of **BST** (e.g being ordered) makes it potential for many applications.

---
## Binary Search Trees (BST)

### Implementation Using Linked Structures (Pointers)


* Trees can be stored in arrays (like Heaps) or stored as linked nodes (i.e using pointers). 
* We will implement the **BST** using linked nodes. 
* Recursion: Think of each node in a tree as a separate standalone tree. 

---
#### Node structure


```c++
template< typename T >
class BST
{
    struct BSTNode
    {
        T data;
        BSTNode *left;
        BSTNode *right;
    };
};
```


---
### Operations (isEmpty)


```c++
template< typename T >
class BST
{
    ...
    static bool isEmpty( const BSTNode *t )
    {
        return t == nullptr;
    }
};
```

---
### Operations (isLeaf)


```c++
template< typename T >
class BST
{
    ...
    static bool isLeaf( const BSTNode *t )
    {
        return !isEmpty(t)
                && isEmpty( t->left )
                && isEmpty( t->right );
    }
};
```


---
### Operations (size)


```c++
template< typename T >
class BST
{
    ...
    static size_t size( const BSTNode *t )
    {
        if ( !isEmpty( t ) )
            return 1 + size( t->left ) + size( t->right );
        else return 0;
    }
};
```

---
### Operations (insert)


<img src="/gallery/trees/binary-search-tree-insertion-animation.gif" style="width:80%;">


---
### Operations (insert)


```c++
template< typename T >
class BST
{
    ...
    static BSTNode * insert( BSTNode *t, T data )
    {
        if ( isEmpty( t ))
            return new BSTNode{ data , nullptr , nullptr };
        else
        {
            if ( data < t->data )
                t->left = insert( t->left, data );
            else t->right = insert( t->right, data );
            return t;
        }
    }
};
```


---
### Operations (find)

<img src="/gallery/trees/binary-search-tree-sorted-array-animation.gif">

---
### Operations (find)


```c++
template< typename T >
class BST
{
    ...
    static bool find( const BSTNode *t, T data )
    {
        if ( isEmpty( t ))
            return false;
        else
        {
            if ( data == t->data )
                return true;
            else if ( data < t->data )
                return find( t->left , data );
            else return find( t->right , data );
        }
    }
};
```


---
### Traversal Operations

<script src="https://www.khanacademy.org/computer-programming/depth-first-traversals-of-binary-trees/934024358/embed.js?editor=no&buttons=yes&author=yes&embed=yes"></script>

---
#### Traversal Operations: In-order

<img src="/gallery/trees/InorderTrav.gif" style="width:80%;">


---
#### Traversal Operations: In-order


```c++
template< typename T >
class BST
{
    ...
    static void inorder( const BSTNode *t )
    {
        if( !isEmpty( t ))
        {
            inorder( t->left );
            std::cout << t->data << " ";
            inorder( t->right );
        }
    }
};
```

---
#### Traversal Operations: Pre-order

<img src="/gallery/trees/PreOrderTrav.gif" style="width:80%;">

---
#### Traversal Operations: Pre-order

```c++
template< typename T >
class BST
{
    ...
    static void preorder( const BSTNode *t )
    {
        if( !isEmpty( t ))
        {
            std::cout << t->data << " ";
            preorder( t->left );
            preorder( t->right );
        }
    }
};
```

---
#### Traversal Operations: Post-order

<img src="/gallery/trees/PostorderTrav.gif" style="width:80%;"> 

---
#### Traversal Operations: Post-order


```c++
template< typename T >
class BST
{
    ...
    static void postorder( const BSTNode *t )
    {
        if( !isEmpty( t ))
        {
            postorder( t->left );
            postorder( t->right );
            std::cout << t->data << " ";
        }
    }
};
```

---
#### Traversal Operations: Breadth-first

<img src="/gallery/trees/bfs.gif" style="width:80%;">

---
#### Traversal Operations: Breadth-first

```c++
template< typename T >
class BST
{
    ...
    static void breadthfirst( const BSTNode *tree )
    {
        std::queue< const BSTNode * > q;
        q.push( tree );
        while( !q.empty())
        {
            auto t = q.front();
            q.pop();
            if( !isEmpty( t->left )) q.push( t->left );
            if( !isEmpty( t->right )) q.push( t->right );
            std::cout << t->data << " ";
        }
    }
};
```



---
### Operations (clear)

```c++
template< typename T >
class BST
{
    ...
    static void clear( BSTNode *t )
    {
        if ( !isEmpty( t )) {
            clear( t->left );
            clear( t->right );
            delete t;
        }
    }
};
```

---
### Operations (remove)

##### **Case I:** Node to be removed **has no children** 

###### Example: `remove( tree , -4 )`

![bst-del1](/gallery/trees/bst-remove-case-1.png)


---
### Operations (remove)

##### **Case II:** Node to be removed **has one child**

###### Example: `remove( tree , 18 )`

##### **Case II:** Node to be removed **has one child**
![bst-del2a](/gallery/trees/bst-remove-case-2-1.png)


---
### Operations (remove)

##### **Case II:** Node to be removed **has one child**

###### Example: `remove( tree , 18 )`

##### **Case II:** Node to be removed **has one child**
![bst-del2b](/gallery/trees/bst-remove-case-2-2.png)


---
### Operations (remove)

##### **Case II:** Node to be removed **has one child**

###### Example: `remove( tree , 18 )`

![bst-del2c](/gallery/trees/bst-remove-case-2-3.png)


---
### Operations (remove)

##### **Case III:** Node to be removed **has two children**

###### Example: `remove( tree , 18 )`

##### **Case II:** Node to be removed **has one child**
![bst-del3a](/gallery/trees/bst-remove-case-3-3.png)

---
### Operations (remove)

##### **Case III:** Node to be removed **has two children**

###### Example: `remove( tree , 18 )`

##### **Case II:** Node to be removed **has one child**
![bst-del3b](/gallery/trees/bst-remove-case-3-4.png) 

---
### Operations (remove)

##### **Case III:** Node to be removed **has two children**

###### Example: `remove( tree , 18 )`

##### **Case II:** Node to be removed **has one child**
![bst-del3c](/gallery/trees/bst-remove-case-3-5.png)

---
### Operations (remove)

##### **Case III:** Node to be removed **has two children**

###### Example: `remove( tree , 18 )`

##### **Case II:** Node to be removed **has one child**
![bst-del3d](/gallery/trees/bst-remove-case-3-6.png)

---
### Operations (remove)


```c++
template< typename T >
class BST
{
    ...
    static BSTNode * remove( BSTNode *t, T data )
    {
        if ( isEmpty( t )) return nullptr;
        if ( data == t->data ) t = removeNode( t );
        else if ( data < t->data ) t->left = remove( t->left, data );
        else t->right = remove( t->right, data );
        return t;
    }
};
```

---
class:small
### Operations (remove)


```c++
template< typename T >
class BST
{
    ...
    static BSTNode * minNode( BSTNode *t )
    {
        auto min = t;
        while( min->left ) min = min->left;
        return min;
    }
    static BSTNode * removeNode( BSTNode *t )
    {
        if ( !isEmpty( t->left ) && !isEmpty( t->right ))
        {
            BSTNode *minRight = minNode( t->right );
            t->data = minRight->data;
            t->right = remove( t->right, t->data );
        } else
        {
            BSTNode *discard = t;
            if ( isLeaf( t )) t = nullptr;
            else if ( !isEmpty( t->left )) t = t->left;
            else t = t->right;
            delete discard;
        }
        return t;
    }
};
```


---
class: left, top

## Abstract Data Types (ADT) based on BST

### Set

* **BST**: efficient insertions and removals.
* **modification**: in `insert` function, only insert unique values,



---
#### Set: Add

--
* Slight modification of `bst::insert`,
* insertion is done only when it is not a duplicate of existing element

--
##### BST Insertion

```c++
template< typename T >
class BST
{
    ...
    static BSTNode * insert( BSTNode *t, T data )
    {
        if ( isEmpty( t ))
            return new BSTNode{ data , nullptr , nullptr };
        else
        {
            if ( data < t->data )
                t->left = insert( t->left, data );
            else t->right = insert( t->right, data );
            return t;
        }
    }
};
```

---
#### Set Insertion (solution 1)


```c++
template< typename T >
class Set
{
    ...
    static SetNode * insert( SetNode *t, T data )
    {
        if ( isEmpty( t ))
            return new SetNode{ data , nullptr , nullptr };
        else if ( data != t->data )
        {
            if ( data < t->data )
                t->left = insert( t->left, data );
            else t->right = insert( t->right, data );
        }
        return t;
    }
};
```


---
##### Set: Insertion (solution 2)

1. use `find` to check if the element doesn't already exist,
2. if so, use `insert`.

```c++
template< typename T >
class Set
{
    ...
public:
    void add( T data )
    {
        if ( !find( data ))
            insert( data );
    }
};
```


---
#### Excercises: Set Union

* `union`: given two sets $S_1$ and $S_2$ make a new data structure $S_3 = S_1  \cup S_2$

##### possible implementation:


1. make an empty set `S3`,
1. iterate over elements of `S1` inserting each element to `S3`, and similarly for `S2`.

---
#### Excercises: Set Intersection

* `intersect`: given two sets $S_1$ and $S_2$ make a new data structure $S_3 = S_1  \cap S_2$


##### possible implementation:

1. make an empty set `S3`,
1. iterate over elements of `S1` inserting each element that also exists in `S2` into `S3`.


---
#### Excercises: Set Equality

* `equals`: given two sets $S_1$ and $S_2$, check the equality of the two sets,

##### possible implementation:
  
1. first, check that $S_1$ and $S_2$ sizes are equal,
2. then what?

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
};
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
};
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
};
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
};
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
};
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
};
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
};
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
};
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
};
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
};
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
};
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

</textarea>
