---
layout: presentation
style: laminal
highlighter: ir-black
code: "SBE201"
course: "SBE201 Data Structures and Algorithms"
category: "presentation"
semester: "Spring"
year: "2020"
title: "Section 7: Heap & Priority Queue (ADT)"
by: "Asem Alaa"
author: "Asem Alaa"
---

<textarea id="source" markdown="1">

# Section 7

## Abstract Data Types: Heap & Priority Queue (ADT)

##### Presentation by *{{ page.author }}*

{% include presentation-margins.html %}

---
## Heaps

#### Max-Heap Logical Representation

![heaptree](/gallery/heaptree.png)

#### Max-Heap Storage

![heapconcrete](/gallery/heapconcrete.png)

---
## Heaps


| Max-Heap |
|---------------|
| ![heap1](/gallery/Heap-as-array.svg) |
|  Creative Commons - [Maxinator](https://commons.wikimedia.org/w/index.php?title=User:Maxiantor&action=edit&redlink=1) |


---
## Heap Applications

* Sorting Algorithms (Heapsort)
* The Shortest Path Problem (Dijkstra's Algorithm)
* Data Compression Algorithms (Huffman Tree)
* Unsupervised Machine Learning (Agglomerative Clustering)

<div class="row text-center">
<div class="col-md-6 align-self-center" markdown="1">
<img height="300" class="center-block" src="/gallery/trees/map.png">
</div>
<div class="col-md-6 align-self-center" markdown="1">
<img height="300" class="center-block" src="/gallery/plot_lena_ward_segmentation_0012.png">
</div>


<div class="my-footer"><span><a href="https://scikit-learn.org/0.15/auto_examples/cluster/plot_lena_ward_segmentation.html">{A demo of structured Ward hierarchical clustering on Lena image}</a><a href="https://github.com/scikit-learn/scikit-learn/blob/4755ae76d2df10bbf41bc93fb7083b0142ef1044/sklearn/cluster/_agglomerative.py">{Agglomerative Clustering Algorithm Using Heap}</a></span></div>



---
### Glossary

.center[<img src="/gallery/btreefull.png" style="width:500px;">]

* Complete Tree: A balanced tree in which the distance from the root to any leaf is either $\lfloor \log(n) \rfloor$ or $\lfloor \log(n)-1 \rfloor$. [source](https://www.cs.auckland.ac.nz/software/AlgAnim/heaps.html).

---
### Complete Tree: Relating $n$ to $h$

- $h$: the height of a full binary tree and 
- $n$: the number of nodes

.center[<img src="/gallery/btreefull.png" style="height:200px;">]

$$\begin{align} n &= 1 + 2 + 4 + \ldots + 2^h \\\
n + 1 &= (1 + 1) + 2 + 4 + \ldots + 2^h \\\
n + 1 &= (2 + 2) + 4 + \ldots + 2^h \\\
&\vdots \\\
n + 1 &= 2^h + 2^h \\\
n + 1 &= 2^{h+1} \label{eq:nh}\tag{E2}
\end{align}$$

---
### Heap Operations: Insert

| We first place the new element 15 in the position marked by the X as a leaf. | <img src="/gallery/heapindel/Heap_add_step1.svg.png" style="width:300px;"> |
|--|--|
|  However, the heap property is violated since 15 > 8, so we need to swap the 15 and the 8 |  <img src="/gallery/heapindel/Heap_add_step2.svg" style="width:300px;"> |
| The heap property is still violated since 15 > 11, so we need to swap again | <img src="/gallery/heapindel/Heap_add_step3.svg" style="width:300px;"> |

<div class="my-footer"><span><a href="https://en.wikipedia.org/wiki/Binary_heap">{Binary_heap - Wikipedia}</a></span></div>


---
### Heap Operations: Extract

| Extract element 11. | <img src="/gallery/heapindel/Heap_delete_step0.svg" style="width:300px;">  |
|--|--|
| 11 is replaced by the the left-most leaf 4. | <img src="/gallery/heapindel/Heap_delete_step1.svg" style="width:300px;">  |
| Heap property is violated (8 is greater than 4). Swapping the two elements 4 and 8 is enough to recover the heap.| <img src="/gallery/heapindel/Heap_delete_step2.svg" style="width:300px;">  |

<div class="my-footer"><span><a href="https://en.wikipedia.org/wiki/Binary_heap">{Binary_heap - Wikipedia}</a></span></div>

---
### Min-heap Implementation 

#### +Priority Queue Interface

```c++
template< typename T >
class Heap
{
public:
    // Return heap size
    size_t size() const {}
    // 1. Insert as leaf
    // 2. Recover heap properties
    void insert(T value){}
    // 1. Extract the root
    // 2. Recover heap properties
    T extract(){}
private:
    // Private details
};
```
---
#### Implementation: Heap Storage

```c++
template< typename T >
class Heap
{
public:
    size_t size() const {}
    void insert(T value){}
    T extract(){}
private:
    std::vector< T > data;
};
```

---
#### Implementation: From Parent to Child (+vice versa)


.center[<img src="/gallery/btree-index.png" style="height:300px;">]

---
#### Implementation: From Parent to Child (+vice versa)

```c++
template< typename T >
class Heap {
public:
    size_t size() const {}
    void insert(T value){}
    T extract(){}
private:
    static size_t leftChildIdx(size_t parent){
        return parent * 2 + 1;
    }
    static size_t rightChildIdx(size_t parent){
        return parent * 2 + 2;
    }
    static size_t parentIdx(size_t child){
        if (child % 2 == 1) return (child - 1) / 2;
        else return (child - 2) / 2;
    } 
    std::vector< T > data;
};
```

---
#### Implementation: Heap size

```c++
template< typename T >
class Heap
{
public:
    size_t size() const { return data.size();}
    void insert(T value){}
    T extract(){}
private:
    // Private methods
    static size_t leftChildIdx(size_t parent){... }
    static size_t rightChildIdx(size_t parent){... }
    static size_t parentIdx(size_t child){... }
private: 
    // Private data members
    std::vector< T > data;
};
```

---
#### Implementation: Insert & SiftUp


```c++
template< typename T >
class Heap
{
public:
    ...
    void insert(T value){
        data.push_back(value);
        size_t childIdx = size() - 1;
        siftUp( childIdx ); // Recover heap
    }
    ...
private:
    void siftUp( size_t child ){
        auto parent = parentIdx(child);
        if( child > 0  && data[child] < data[parent]){
            std::swap(data[child], data[parent]);
            siftUp( parent );
        }
    }
    ...
};
```

* Worst case time: $O(T(n)) = O(h) = O(\log(n))$

---
#### Implementation: Extract & SiftDown

```c++
template< typename T >
class Heap
{
public:
    ...
    T extract(){
        if( data.empty()) exit( 1 ); // Crash
        size_t child = size() - 1;
        std::swap(data[child], data[0]);
        int value = data.back();
        data.pop_back();
        siftDown(0);
        return value;
    }
private:
    void siftDown( size_t parent){
        size_t left = leftChildIdx(parent);
        size_t right = rightChildIdx(parent);
        size_t length = size();
        size_t minimum = parent;
        if (left < length && data[left] < data[minimum])
            minimum = left;
        if (right < length && data[right] < data[minimum])
            minimum = right;
        if (minimum != parent){
            std::swap(data[minimum], data[parent]);
            siftDown( minimum );
        }
    }
    ...
};
```

* Worst case time: $O(T(n)) = O(h) = O(\log(n))$

---
#### Implementation: Heapifying Arbitrary Array

```c++
template< typename T >
class Heap
{
public:
    ...
    static Heap make( std::vector< T > data )
    {
        Heap h;
        h.data.swap( data ); // O(1)
        if( h.size() <= 1 ) return h;

        auto lastChild = h.size() - 1;
        for( int subHeap = parentIdx( lastChild ); subHeap >= 0 ; --subHeap )
            h.siftDown( subHeap );
        return h;
    }
    ...
};
```

---
#### Complexity Analysis: Heapifying Arbitrary Array

<img src="/gallery/btree-levels.png">

| Level |  #Sub\_Heaps | Heapify Cost |
|---|---|---|
|  $h$    |   $2^h$   |   0   |
|  $h-1$  |   $2^{h-1}$ | 1  |
|   ...   | ... | ... |
|  1  | 2  | $h-1$ |
|  0  | 1  | $h$ |

$$T(n) = 2^h \times 0 + 2^{h-1} \times 1 + \ldots + 2^0 \times h = \sum\_{j=0}^h j 2^{h-j} \label{eq:tn}\tag{E1}$$

---
##### Useful Equations

- The power series: 
$$\begin{equation}
\sum\_{j=0}^{\infty} x^j = \frac{1}{1-x};  |x|<0 \label{eq:PS1}\tag{PS1}
\end{equation}$$
- Differentiating Equation \eqref{eq:PS1} with respect to $x$ yields:
$$\begin{align*}
\sum\_{j=0}^{\infty} j x^{j-1} &= \frac{1}{(1-x)^2} \\ \quad &\textrm{multiplying by x:} \quad \\ \sum\_{j=0}^{\infty} j x^{j} &= \frac{x}{(1-x)^2}  \label{eq:PS2}\tag{PS2}
\end{align*}$$
 
---
##### Evaluating $T(n)$ & $O(n)$

From \eqref{eq:tn} we estimated $T(n)$ as:
$$\begin{align*}
T(n) &= \sum\_{j=0}^h j 2^{h-j} \\
&= \sum\_{j=0}^h j \frac{2^h}{2^j} \\
&= 2^h \sum\_{j=0}^h \frac{j}{2^j} \\
\textrm{by substituting $x=\frac{1}{2}$ in \eqref{eq:PS2}:} \\
\sum\_{j=0}^\infty \frac{j}{2^j} &= \sum\_{j=0}^\infty j(\frac{1}{2})^j = \frac{\frac{1}{2}}{(1 - \frac{1}{2})^2} = 2  \\
\textrm{therefore: }& \\
 2^h \sum\_{j=0}^h \frac{j}{2^j} &< 2^h \sum\_{j=0}^\infty \frac{j}{2^j} = 2^h (2) \\
\textrm{therefore: } & \\
T(n) &< 2^{h+1} \\
\textrm{From \eqref{eq:nh}: } & \\
T(n) &< n + 1 \\
\textrm{therefore, the big-O notation of $T(n)$:}& \\ 
O(T(n)) &= O(n)
\end{align*}$$


<div class="my-footer"><span><em>Reference (Heapify Analysis and O(n) derivation):</em> <a href="https://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf">Lecture 14: HeapSort Analysis and Partitioning - CMSC 251</a></span></div>

---
class: small
### Heap Applications: Heapsort

```c++
template< typename T >
class Heap
{
public:
    ...
    static Heap make( std::vector< T > data )
    {
        Heap h;
        h.data.swap( data ); // O(1)
        ...
    }
    ...
};
```

```c++
std::vector< int > heapSort( std::vector< int > a )
{
    auto h = Heap<int>::make( a ); // Heapify: O(n)
    a.clear();
    while( h.size() > 0 ) // O( n * log(n) )
        a.push_back( h.extract()); // O(log(n))
    return a;
}
```

Time Complexity: $O(T(n)) = O(n) + O(n\log(n)) = O(n\log(n))$

---
### Heap Applications: Heapsort (avoiding $O(n)$ deep copy)

```c++
std::vector< int > heapSort( std::vector< int > a )
{
    auto h = Heap<int>::make( std::move( a ));
    while( h.size() > 0 )
        a.push_back( h.extract());
    return a;
}
```

To understand what is happening:

- [{Advanced C++: Understanding rvalue and lvalue}](https://www.youtube.com/watch?v=UTUdhjzws5g)
- [{C++ 11: Rvalue Reference -- Move Semantics}]("https://www.youtube.com/watch?v=IOkgBrXCtfo")


---
#### Visualization & Links

| Heapsort |
|-----------|
| <img src="/gallery/Sorting_heapsort_anim.gif" style="width:500px;"> |


---
#### Visualization & Links

<iframe width="560" height="315" src="https://www.youtube.com/embed/H5kAcmGOn4Q" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

* [{Heaps and Heap Sort}](http://www.zutopedia.com/hs_vs_ms.html)


---
class: center, middle
## Read the Notes

Read the notes for more details and to download the source files.

.small.blue[[{sbme-tutorials.github.io/2020/data-structures/notes/week07.html}](https://sbme-tutorials.github.io/2020/data-structures/notes/week07.html)]


---
# Thank you

{% include presentation-margins.html %}


</textarea>