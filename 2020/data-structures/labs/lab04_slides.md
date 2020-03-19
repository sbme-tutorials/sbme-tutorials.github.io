---
layout: presentation
style: laminal
highlighter: ir-black
code: "SBE201"
course: "SBE201 Data Structures and Algorithms"
category: "presentation"
semester: "Spring"
year: "2020"
title: "Lab 4: STL vectors & Sorting"
by: "Asem"
author: "Asem Alaa"
---

<textarea id="source" markdown="1">

# Lab 4

## STL vectors & Sorting

##### Presentation by *{{ page.author }}*

{% include presentation-margins.html %}

#### Quadratic Performance

Consider the following function `varianceArray`

```c++
double meanArray( double *array, int size){.....} // O(an + b) = O(n)

double varianceArray( double *array, int size ) // n = size
{
    double sum = 0 ; // O(1)
    double mean = meanArray( array ); // O(n)
    for( int i = 0; i < size ; ++i )  // O(n)
    {
        double diff = mean - array[i]; // O(1)
        sum = sum + diff * diff ; // O(1)
    }
    return sum / size; // O(1)
}
```

--
$$ O(T(n)) = O(1) + O(n) + O(1) = O(n) $$

.green[$O(n) is better than O(n^2)$]

.blue[Can we do better?]

---
#### Quadratic Performance

Let's use `std::vector<double>` instead of using the raw array..


```c++
double meanArray( std::vector<double> a ){.....} // O(an + b) = O(n)

double varianceArray( std::vector< double > a )
{
    double sum = 0 ; // O(1)
    double mean = meanArray( a ); // O(n)
    for( int i = 0; i < a.size() ; ++i )  // O(n)
    {
        double diff = mean - a[i]; // O(1)
        sum = sum + diff * diff ; // O(1)
    }
    return sum / a.size; // O(1)
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