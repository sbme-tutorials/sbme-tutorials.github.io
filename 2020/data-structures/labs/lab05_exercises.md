---
layout: page
course: "sbe201"
category: "lab"
year: "2020"
title:  "Lab 5: Doubly linked lists, classes, templates"
by: "Asem"
pdf: true
---

* TOC
{:toc}

## Initialization

### Dowloading files using `wget`

You need to download the initial source files. `wget` program can help you in general to download files from the internet. In case you don't have it in your system you can install it using:

```
sudo apt install wget
```

### Download source files

Before downloading files, go to your lab repository and make `lab05` directory then go to the newly created folder:

```
mkdir lab05 # Execute in repo folder
cd lab05
```

There are **eight files** we need to download. However, we can first download a single text file that includes the links for the other 8 files.

```
wget https://raw.githubusercontent.com/sbme-tutorials/sbme-tutorials.github.io/master/2020/data-structures/snippets/lab05/linkedlists/download.txt
```

Now to download the **eight files** in a single command:

```
wget -i download.txt
```

Now if you list the files in the current directory you should see the following output:

<pre><font color="#8AE234"><b>asem@asem-pc</b></font>:<font color="#729FCF"><b>~/GP/sbe201-2020-labs-A-Alaa/lab05</b></font>$ ls
CMakeLists.txt  DLL2.hpp  download.txt   main_dll2.cpp  main_std.cpp
DLL1.hpp        DLL3.hpp  main_dll1.cpp  main_dll3.cpp
</pre>

From the QtCreator, open the current directory as a project by selecting `CMakeLists.txt` file.


<br>
<img src="qt1.png" style="width:60%">
<br>

<br>
<img src="qt2.png" style="width:60%">
<br>

<br>
<img src="qt3.png" style="width:60%">
<br>



## Application 1: remove duplicates from doubly linked list


### A) Procedural Paradigm

#### Requirement 1: implementation of doubly linked list of integers

Complete the implementation of the following functions in the `DLL1.hpp` file:

1. `bool isEmpty( DLL &list )`
2. `void pushFront( DLL &list, int data )`
3. `void pushBack( DLL &list, int data )`
4. `void popNode( DLL &list, Node *node )`
5. `void popFront( DLL &list )`
6. `void popBack( DLL &list )`
7. `int getAt( DLL &list, int index )`
8. `void clear( DLL &list )`
9. `void print( DLL &l )`
10. `int size( DLL &list )`

#### Requirement 2: implementation of duplicates removal algorithm

In the `main_dll1.cpp`, implement a function `removeDuplicates` that deletes duplicate elements in the linked list you just made in `DLL1.hpp`.

```c++
#include <iostream>
#include <random>
#include "DLL1.hpp"

void removeDuplicates( DLL &l )
{}
int main()
{
    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,500); // distribution
    DLL l{nullptr}; // Empty list
    for( int i = 0; i < 500 ; ++i) // Populate with 500 random integers
        pushBack( l , udist(sampler));
    removeDuplicates( l ); 
}
```

### B) Object-oriented Paradigm 

#### Requirement 1: from free functions to member functions

In this part, you will work on `DLL2.hpp`. You are required to copy your functions from `DLL1.hpp` and transform the **free functions** into **member functions** inside the `struct DLL`.

```c++
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DLL
{
    // Data members
    Node *front;
    // Member functions (methods)
    bool isEmpty(){ /** Logic **/}
    void pushFront( int data ){ /** Logic **/}
    void pushBack( int data ){ /** Logic **/}
    void popNode( Node *node ){ /** Logic **/}
    void popFront(){ /** Logic **/}
    void popBack(){ /** Logic **/}
    int getAt( int index ){ /** Logic **/}
    void clear(){ /** Logic **/}
    void print(){ /** Logic **/}
    int size(){ /** Logic **/}
    // Constructors
    DLL() // default constructor
    { 
        front = nullptr; 
    } 
};
```

#### Requirement 2: adapt the program to work with the new paradigm

Now you will work in a new source file `main_dll2.cpp` which will use the linked list in `DLL2.hpp` as an object with methods.

```c++
#include <iostream>
#include <random>
#include "DLL2.hpp"

void removeDuplicates( DLL &l )
{}
int main()
{
    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,500); // distribution
    DLL l; // Empty list
    for( int i = 0; i < 500 ; ++i) // Populate with 500 random integers
        pushBack( l , udist(sampler)); // CHANGE THIS
    removeDuplicates( l ); 
}
```


### C) Templates


#### Requirement 1: from concrete class to template class

In this part, you will work on `DLL3.hpp`. You are required to copy your lines from `DLL2.hpp` and transform the **doubly linked list of integers** into **generic doubly linked list**.

```c++
// T: template parameter. It will be the type of element data.
template< typename T > 
struct Node
{
    T data; // Generic type
    Node *next;
    Node *prev;
};


// T: template parameter. It will be the type of element data.
template< typename T >
struct DLL
{
    // Data members
    Node< T > *front;
    // Member functions (methods)
    bool isEmpty(){ /** Logic **/}
    void pushFront( T data ){ /** Logic **/}
    void pushBack( T data ){ /** Logic **/}
    void popNode( Node< T > *node ){ /** Logic **/}
    void popFront(){ /** Logic **/}
    void popBack(){ /** Logic **/}
    T getAt( int index ){ /** Logic **/}
    void clear(){ /** Logic **/}
    void print(){ /** Logic **/}
    int size(){ /** Logic **/}
    // Constructors
    DLL() // default constructor
    { 
        front = nullptr; 
    } 
};
```

#### Requirement 2: adapt the program to work with the template class

Now you will work in a new source file `main_dll3.cpp` which will use the linked list in `DLL3.hpp` as a template class (and will **instantiate** an integer doubly linked list from it).

```c++
#include <iostream>
#include <random>
#include "DLL2.hpp"

void removeDuplicates( DLL<int> &l )
{}
int main()
{
    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,500); // distribution
    DLL<int> l; // Empty list
    for( int i = 0; i < 500 ; ++i) // Populate with 500 random integers
        pushBack( l , udist(sampler)); // CHANGE THIS
    removeDuplicates( l ); 
}
```


## Application 2: print COVID19 statistics (group by country)

The following folder [csse_covid_19_daily_reports](https://github.com/CSSEGISandData/COVID-19/tree/master/csse_covid_19_data/csse_covid_19_daily_reports) contains reports on COVID figures around the globe cities that are updated daily.


For example, the file [04-15-2020.csv](https://github.com/CSSEGISandData/COVID-19/blob/master/csse_covid_19_data/csse_covid_19_daily_reports/04-15-2020.csv) includes the COVID figures updated until 15/April/2020.


Each of these files are formatted as tables using the standard **comma-separated-values (csv)** format. You can view the raw **csv** file in this link [04-15-2020.csv](https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/04-15-2020.csv).


The first line of any **csv** file is called the header line that defines the columns names. In that file, you will see the first line as:

```
FIPS,Admin2,Province_State,Country_Region,Last_Update,Lat,Long_,Confirmed,Deaths,Recovered,Active,Combined_Key
```

It means that the following lines will consist of **12 values** separated by commas and they represent in order: the FIPS (the county code), Admin2 (adminstration), ..etc.


In the table, you will see some countries like **US, China, Canada, United Kingdom, France** are distributed by cities, and other countries are reported as a single row representing the overall figures in that country.

You can directly download these files to your machine using `wget`.

```
wget https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/04-15-2020.csv
```

After downloading, you can open the `04-15-2020.csv` using the Excel program (or alike).


Instead of downloading as a file, you can directly print the file contents to your terminal:

```
wget -q -O - https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/04-15-2020.csv
```


#### Requirement 1 (done): merge by country using `std::list`

We are interested to print a table that shows: **the confirmed cases**, **deaths**, **recoveries**, **active cases** for each country. So if there are many rows representing different cities for a single country, we will sum the figures in a single row representing the whole country.


In the `main_std.cpp` file, use a **linked list** to load the whole table data, then merge the rows of single countries summing their figures. Use the `std::list` from the C++ STL. 

To run your program, we can **redirect the standard output of the following command as a standard input to your compiled program**

The standard output here printed in the terminal:

```
wget -q -O - https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/04-15-2020.csv
```

This command redirects the standard output as a standard input to your program `std_ll` (after compiled):

```
wget -q -O - https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/04-15-2020.csv | ./std_ll
```

You should see the following output:

<pre><font color="#8AE234"><b>asem@asem-home</b></font>:<font color="#729FCF"></font>$ wget -q -O - https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_daily_reports/04-15-2020.csv | ./std_ll
+----------------------------------+-----------+--------+-----------+--------+
|<font color="#D3D7CF">              </font><font color="#EEEEEC"><u style="text-decoration-style:single"><b>Country</b></u></font><font color="#D3D7CF">             </font>|<span style="background-color:#06989A"><font color="#D3D7CF"> </font></span><span style="background-color:#06989A"><font color="#EEEEEC"><u style="text-decoration-style:single"><b>Confirmed</b></u></font></span><span style="background-color:#06989A"><font color="#D3D7CF"> </font></span>|<span style="background-color:#CC0000"><font color="#D3D7CF"> </font></span><span style="background-color:#CC0000"><font color="#EEEEEC"><u style="text-decoration-style:single"><b>Deaths</b></u></font></span><span style="background-color:#CC0000"><font color="#D3D7CF"> </font></span>|<span style="background-color:#4E9A06"><font color="#D3D7CF"> </font></span><span style="background-color:#4E9A06"><font color="#EEEEEC"><u style="text-decoration-style:single"><b>Recovered</b></u></font></span><span style="background-color:#4E9A06"><font color="#D3D7CF"> </font></span>|<span style="background-color:#3465A4"><font color="#D3D7CF"> </font></span><span style="background-color:#3465A4"><font color="#EEEEEC"><u style="text-decoration-style:single"><b>Active</b></u></font></span><span style="background-color:#3465A4"><font color="#D3D7CF"> </font></span>|
+----------------------------------+-----------+--------+-----------+--------+
|                <b>US</b>                |<font color="#06989A">   </font><font color="#34E2E2"><b>636350</b></font><font color="#06989A">  </font>|<font color="#CC0000">  </font><font color="#EF2929"><b>28326</b></font><font color="#CC0000"> </font>|<font color="#4E9A06">   </font><font color="#8AE234"><b>52096</b></font><font color="#4E9A06">   </font>|<font color="#3465A4"> </font><font color="#729FCF"><b>555928</b></font><font color="#3465A4"> </font>|
+----------------------------------+-----------+--------+-----------+--------+
|              <b>Canada</b>              |<font color="#06989A">   </font><font color="#34E2E2"><b>28209</b></font><font color="#06989A">   </font>|<font color="#CC0000">  </font><font color="#EF2929"><b>1007</b></font><font color="#CC0000">  </font>|<font color="#4E9A06">    </font><font color="#8AE234"><b>8966</b></font><font color="#4E9A06">   </font>|<font color="#3465A4">  </font><font color="#729FCF"><b>18236</b></font><font color="#3465A4"> </font>|
+----------------------------------+-----------+--------+-----------+--------+
|          <b>United Kingdom</b>          |<font color="#06989A">   </font><font color="#34E2E2"><b>99483</b></font><font color="#06989A">   </font>|<font color="#CC0000">  </font><font color="#EF2929"><b>12894</b></font><font color="#CC0000"> </font>|<font color="#4E9A06">    </font><font color="#8AE234"><b>368</b></font><font color="#4E9A06">    </font>|<font color="#3465A4">  </font><font color="#729FCF"><b>86221</b></font><font color="#3465A4"> </font>|
+----------------------------------+-----------+--------+-----------+--------+
|               <b>China</b>              |<font color="#06989A">   </font><font color="#34E2E2"><b>83356</b></font><font color="#06989A">   </font>|<font color="#CC0000">  </font><font color="#EF2929"><b>3346</b></font><font color="#CC0000">  </font>|<font color="#4E9A06">   </font><font color="#8AE234"><b>78311</b></font><font color="#4E9A06">   </font>|<font color="#3465A4">  </font><font color="#729FCF"><b>1699</b></font><font color="#3465A4">  </font>|
+----------------------------------+-----------+--------+-----------+--------+
|            <b>Netherlands</b>           |<font color="#06989A">   </font><font color="#34E2E2"><b>28316</b></font><font color="#06989A">   </font>|<font color="#CC0000">  </font><font color="#EF2929"><b>3145</b></font><font color="#CC0000">  </font>|<font color="#4E9A06">    </font><font color="#8AE234"><b>304</b></font><font color="#4E9A06">    </font>|<font color="#3465A4">  </font><font color="#729FCF"><b>24867</b></font><font color="#3465A4"> </font>|
+----------------------------------+-----------+--------+-----------+--------+
|             <b>Australia</b>            |<font color="#06989A">    </font><font color="#34E2E2"><b>6440</b></font><font color="#06989A">   </font>|<font color="#CC0000">   </font><font color="#EF2929"><b>63</b></font><font color="#CC0000">   </font>|<font color="#4E9A06">    </font><font color="#8AE234"><b>2186</b></font><font color="#4E9A06">   </font>|<font color="#3465A4">  </font><font color="#729FCF"><b>4191</b></font><font color="#3465A4">  </font>|
+----------------------------------+-----------+--------+-----------+--------+
|              <b>Denmark</b>             |<font color="#06989A">    </font><font color="#34E2E2"><b>6876</b></font><font color="#06989A">   </font>|<font color="#CC0000">   </font><font color="#EF2929"><b>309</b></font><font color="#CC0000">  </font>|<font color="#4E9A06">    </font><font color="#8AE234"><b>2925</b></font><font color="#4E9A06">   </font>|<font color="#3465A4">  </font><font color="#729FCF"><b>3642</b></font><font color="#3465A4">  </font>|
+----------------------------------+-----------+--------+-----------+--------+
|              <b>France</b>              |<font color="#06989A">   </font><font color="#34E2E2"><b>134582</b></font><font color="#06989A">  </font>|<font color="#CC0000">  </font><font color="#EF2929"><b>17188</b></font><font color="#CC0000"> </font>|<font color="#4E9A06">   </font><font color="#8AE234"><b>31470</b></font><font color="#4E9A06">   </font>|<font color="#3465A4">  </font><font color="#729FCF"><b>85924</b></font><font color="#3465A4"> </font>|
+----------------------------------+-----------+--------+-----------+--------+
</pre>

(The output is pruned)

#### Requirement 2: replace `std::list` with your implemented linked list

Replace the usage of `std::list` with an instantiated `DLL<CovidItem>` from the template class `DLL` in `DLL3.hpp`.

