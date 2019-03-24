
<!DOCTYPE html>
<html>
  <head>

    <meta charset="utf-8">
    <title>Week 6: Recursion, Big-Oh Notation, Queue Applications</title>
    <link rel="stylesheet" href="/css/laminal.css">

  </head>
  <body>
    <textarea id="source">

---
## Recursion

### Factorial example

<img src="/gallery/recursion1.gif" style="width:100%">


---
```c++
#include <iostream>
int factorial( int n )
{
    if( n <= 1 )
        return 1;
    else
        return n * factorial( n - 1 );
}

int main()
{
    std::cout << "5!=" << factorial( 5 );
    return 0;
}
```

---
```python
factorial(5) 
   factorial(4) 
      factorial(3) 
         factorial(2) 
            factorial(1) 
               return 1 
            return 2*1 = 2 
         return 3*2 = 6 
      return 4*6 = 24 
   return 5*24 = 120
```

---
<img src="/gallery/fact5rec/8.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/7.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/6.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/6.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/5.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/4.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/3.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/2.svg" style="width:100%;">

---
<img src="/gallery/fact5rec/1.svg" style="width:100%;">



---
### How recursion work in stack memory

[{Demo: How Recursive Factorial Work in Memory}](https://www.cs.usfca.edu/~galles/visualization/RecFact.html)

---
### Recursion is not Function Overloading

--
The following is not recursion

```c++
struct Rectangle
{
    double a = 0;
    double b = 0;
};

double area( double a , double b )
{
    return a * b;
}

double area( Rectangle rect )
{
    return area( rect.a , rect.b ); // This is not recursion.
}
```

---
However, the following calling `area` is recursive, it calls itself

```c++
struct Rectangle
{
    double a = 0;
    double b = 0;
};

double area( Rectangle rect )
{
    return area( rect ); // This is a recursion. Very pointless and buggy function!
}
```

* infinite recurions, 
* until .red[stack memory overflow] happens, 
* and finally the program crashes.
* pointless function.
--
* **Add to your glossary**: *[Stack Memory Overflow](https://en.wikipedia.org/wiki/Stack_overflow)*

---
### **Exercise**: Power Function

--
Implement a function `power` that uses recursion to compute the power of the input number.


---
### Recursion is very important technique

--
* Tree data structure.
--
* Divide and conquer & dynamic programming algorithms.
--
* Elegant functions with less codes.

---
## Big-Oh Notation

--
### What is an Algorithm

--
> According to Donald Knuth, the word *algorithm* is derived from the name “al-Khowârizmı̂,” a ninth-century Persian mathematician.

--
#### In programming, 

--
* *algorithm* is a function with clever logic. 
--
* However, it is a very general term. 
--
* The `meanArray` function is an *algorithm 
--
* Similary, `varianceArray`, `minArray`, `maxArray`, `factorial`, and `power`.


--
We are concerned about the function running time w.r.t input size `n`.

---
### How to measure an algorithm performance

#### Constant Performance


--
```c++
int sqaure( int x )
{
    int y = x * x; // T1(n) = 1
    return y; // T2(n) = 1
}
```

--
$$ T(n) = T1 + T2 = 2 $$


--
$$ O( T(n) ) = O(2) = O(1) $$


--
**constant execution time**. 


---
#### Constant Performance

```c++
bool isEmpty( CharacterStackLL &stack )
{
    return stack.front == nullptr; // T(n) = 1
}
```

--
$$ T(n) = 1 $$

--
$$ O( T(n) ) = O(1) $$


--
*Related terms: Performance, complexity, growth function*


---
#### Linear Performance


--
```c++
void printLL( Node* front )
{
    Node *current = front; // T1(n) = 1

    while( current != nullptr ) // T2(n) = n * ( T3 + T4 )
    {
        std::cout << current->data; // T3(n) = 1
        current = current->next; // T4(n) = 1
    }
}
```
--
$$  T(n) = T1 + T2 = 1 + n ( T3 + T4 ) = 1 + 2n $$


--
$$ O(T(n)) = O( 1 + 2n ) = O(n) $$


--
* linear in execution time.

---

<img src="/gallery/complexity.svg" style="width:80%;">

---
* How to approximately estimate the function running time for $n=1000000$, i.e linked-list of **1-million** element
* **Givens**:

    * The function has complexity of $ O(n) $.
    * The function executed in *2 melliseconds* when $n=2000$.


---
#### Quadratic Performance

Consider the following **naive** inefficient function `varianceArray`

--
```c++
double varianceArray( double *base, int arraySize )
{
    double sum = 0 ;
    for( int i = 0; i < arraySize ; ++i ) 
    {
        double diff = meanArray(&base[0],arraySize ) - base[i]; 
        sum = sum + diff * diff ; 
    }
    return sum / arraySize;
}
```

--
* `std::vector< double >` version?

---
#### Quadratic Performance

Consider the following **naive** inefficient function `varianceArray`


```c++
double varianceArray( std::vector< double > &array )
{
    double sum = 0 ;
    for( int i = 0; i < array.size() ; ++i ) 
    {
        double diff = meanArray( array ) - array[i]; 
        sum = sum + diff * diff ;
    }
    return sum / array.size();
}
```

--
* Analyse lines

---
#### Quadratic Performance

Consider the following **naive** inefficient function `varianceArray`


```c++
double varianceArray( std::vector< double > &array )
{
    double sum = 0 ; // T1(n) = 1
    for( int i = 0; i < array.size() ; ++i ) // T2(n) = n ( T3 + T4 )
    {
        double diff = meanArray( array ) - array[i]; // T3(n) = n
        sum = sum + diff * diff ; // T4(n) = 1
    }
    return sum / array.size(); // T5(n) = 1
}
```

--
$$  T(n) = T1 + T2 + T5 = 1 + n ( T3 + T4 ) + 1 = 1 + n( n + 1 ) + 1$$ 
$$ = n^2 + n + 2 $$

$$ O(T(n)) = O(n^2 + n + 2) = O(n^2) $$

---
#### Quadratic Performance

Consider the following **naive** inefficient function `varianceArray`


```c++
double varianceArray( std::vector< double > &array )
{
    double sum = 0 ; // T1(n) = 1
    for( int i = 0; i < array.size() ; ++i ) // T2(n) = n ( T3 + T4 )
    {
        double diff = meanArray( array ) - array[i]; // T3(n) = n
        sum = sum + diff * diff ; // T4(n) = 1
    }
    return sum / array.size(); // T5(n) = 1
}
```

.red[Can we do better?]

---
#### Quadratic Performance

.green[mean is constant for the same array!]


```c++
double varianceArray( std::vector< double > &array  )
{
    double sum = 0 ; // T1(n) = 1
    double mean = meanArray( array ); // T2(n) = O(n)
    for( int i = 0; i < array.size() ; ++i ) // T2(n) = n ( T3 + T4 )
    {
        double diff = mean - array[i]; // T3(n) = 1
        sum = sum + diff * diff ; // T4(n) = 1
    }
    return sum / array.size(); // T5(n) = 1
}
```

--
$$  T(n) = T1 + T2 + T5 = 1 + n ( T3 + T4 ) + 1 = 1 + n( 1 + 1 ) + 1$$ 
$$ = 2n + 2 $$

$$ O(T(n)) = O(2n + 2) = O(n) $$

---
#### Quadratic Performance

##### Again..


```c++
double varianceArray( std::vector< double > &array  )
{
    double sum = 0 ; // T1(n) = 1
    double mean = meanArray( array ); // T2(n) = O(n)
    for( int i = 0; i < array.size() ; ++i ) // T2(n) = n ( T3 + T4 )
    {
        double diff = mean - array[i]; // T3(n) = 1
        sum = sum + diff * diff ; // T4(n) = 1
    }
    return sum / array.size(); // T5(n) = 1
}
```

.red[Can we do better in sense of safety?]

---
#### Quadratic Performance

##### const-correctness


```c++
double varianceArray( const std::vector< double > &array  )
{
    double sum = 0 ; // T1(n) = 1
    double mean = meanArray( array ); // T2(n) = O(n)
    for( int i = 0; i < array.size() ; ++i ) // T2(n) = n ( T3 + T4 )
    {
        double diff = mean - array[i]; // T3(n) = 1
        sum = sum + diff * diff ; // T4(n) = 1
    }
    return sum / array.size(); // T5(n) = 1
}
```



---
### Further: Orders of common functions

<img src="/gallery/complexity.svg" style="width:80%;">


---
[{Orders of common functions}](https://en.wikipedia.org/wiki/Big_O_notation#Orders_of_common_functions)


---
### Exercises

```c++

// n = input array `sequence` size
int countCharacter( const std::string &sequence , char query )
{
    int x = 0; // T1(n) = 1
    for ( int i = 0; i < sequence.size(); ++i) // T2(n) = n * T3(n)
    {
        if ( query == sequence[i] ) T3(n) = 1
            ++x;
    }
    return x; // T4(n) = 1
}
// T(n) = T1 + T2 + T4 = 1 + n * T3 + 1 = 2 + n
// O(T(n)) = O(n)
```


---
```c++
char *analyzeDNA( const std::string &sequence, int &countA, int &countC, int &countG, int countT)
{
    countA = arrays::countCharacter( sequence, 'A'); // T1(n) = 2 + n => O(n)
    countC = arrays::countCharacter( sequence, 'C'); // T2 = same
    countG = arrays::countCharacter( sequence, 'G'); // T3 = same
    countT = arrays::countCharacter( sequence, 'T'); // T4 = same
    return complementarySequence( sequence ); // T5 = 1
}

// T(n) = 4 * (2 + n) + 1 = 9 + 4n
// O(T(n)) = O(n)
```

---
## Sorting Algorithms

--
**Problem** given a collection of **n** elements, it is required to sort the elements in ascending order.

--
* **Example** the following arbitrary array:

| 1 | 9 | 4 | 7 | 3 |

--
* After applying sorting in ascending order will result as:


| 1 | 3 | 4 | 7 | 9 |

---
### Bubble Sort

--
#### Visualized Bubble Sort 1

<iframe width="560" height="315" src="/gallery/bubblesort.mp4" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

---
#### Visualized Bubble Sort 2

<img src="/gallery/Bubble-sort-example-300px.gif">
> Credits: [CC BY-SA 3.0](https://commons.wikimedia.org/w/index.php?title=User:Swfung8&action=edit&redlink=1)

---
#### Implementation

```c++
#include <algorithm>
// A function to implement bubble sort
void bubbleSort( std::vector< double > &array )
{
    for ( int i = 0; i < array.size()-1; i++ )
    {
        for ( int j = 0; j < array.size()-1; j++ )
        {
            if ( array[j] > arr[j+1])
                std::swap( array[j] , array[j+1] );
        }
    }
}
```

---
#### Complexity Analysis

```c++
#include <algorithm>
// A function to implement bubble sort
void bubbleSort( std::vector< double > &array )
{
    for (int i = 0; i < array.size()-1; i++ ) // T1 = n * T2
    {
        for ( int j = 0; j < array.size()-1; j++ ) T2 = n * T3
        {
            if ( array[j] > arr[j+1] ) // T3 = 1
                std::swap( array[j] , array[j+1] );
        }
    }
}
```

--
$ T(n) = T_1 = n \times T_2 = n \times n = n^2 $


--
$ O(T(n)) = O(n^2) $


---
### Selection Sort


--
<img src="/gallery/selectionsort.gif">
> credits: [GNU license](https://en.wikipedia.org/wiki/Joestape89)


---
#### Implementation


--
```c++
#include <algorithm>
void selectionSort( std::vector< double > &array )
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < array.size() -1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;

        for (int j = i+1; j < array.size() ; j++)
        {
            if ( array[j] < array[min_idx] )
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        std::swap( array[min_idx] ,  array[i] );
    }
}
```

---
#### Complexity Analysis

```c++
#include <algorithm>
void selectionSort( std::vector< double > &array )
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < array.size() -1; i++) // T1 = n * ( T2 + T3 + T4 )
    {
        // Find the minimum element in unsorted array
        int min_idx = i; // T2 = 1

        for (int j = i+1; j < array.size() ; j++) // T3 = O(n)
        {
            if ( array[j] < array[min_idx] )
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        std::swap( array[min_idx] ,  array[i] ); // T4 = 1
    }
}
```

--
$ T(n) = T_1 = n \times (T_2 + T_3 + T_4) = n \times( O(n) + 2 ) $


--
$ O(T(n)) = O(n^2)$









    </textarea>
    
    

     

    <script src="/javascript/jquery-3.3.1.min.js" type="text/javascript"></script>

    <script src="/javascript/remark.min.js"></script>
  
    <script type="text/javascript">
      var hljs = remark.highlighter.engine;
    </script>
    <script src="/javascript/terminal.language.js" type="text/javascript"></script>
  
    <script type="text/javascript">
      var options = {
        ratio: '4:3',
        highlightStyle: 'github',
        countIncrementalSlides: false
      };
      var slideshow = remark.create(options);
  
      // extract the embedded styling from ansi spans
      $('code.terminal span.hljs-ansi').replaceWith(function (i, x) {
        return x.replace(/&lt;(\/?(\w+).*?)&gt;/g, '<$1>')
      });
  
    </script>
  
    <script src="/mathjax/MathJax.js"></script>
  
    <script type="text/javascript">
      MathJax.Hub.Config({
        extensions: ["tex2jax.js"],
        tex2jax: { inlineMath: [['$', '$'], ['\\(', '\\)']], skipTags: ['script', 'noscript', 'style', 'textarea', 'pre'] },
        jax: ["input/TeX", "output/HTML-CSS"],
        "HTML-CSS": {
          availableFonts: ["TeX"],
          imageFont: null
        },
        MathMenu: {
          showRenderer: false,
          showFontMenu: false,
          showLocale: false
        }
      });
    </script>

    <script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>

  
  
  </body>
</html>

