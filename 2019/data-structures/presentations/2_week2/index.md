---
layout: presentation
style: laminal
highlighter: monokai
course: "sbe201"
category: "presentation"
year: "2019"
title: "Week2: Memory, pointers, and references"
by: "Asem"
author: "Asem Alaa"
---

    
<textarea id="source">


---
class: left, middle
## Linux Spaces
### System-wise space vs. User space

<img style="width:80%" src="/gallery/linux-spaces.png">

* When working on your projects, you are a **USER**.
* When installing/upgrading system-wise application/library, you are an **ADMIN**. 


---
class: left, top
## Jumping between folders (changing directories)

```terminal
$ cd (Relative Path|Absolute Path)
```

* In terminal commands, with `A|B`, I mean "Either A or B". 

---
class: left, top
## Listing files in the current directory (folder)

### List files/directories inside the current directory of the terminal
```terminal
$ ls 
```

### List files/directories on from other directory
```terminal
$ ls (Relative Path|Relative Path)
```


---
class: left, top
## Change folder name or moving folder name

```terminal
$ mv (file|directory) (new file|new directory)
```

---
class: left, top
## Copy file 


```terminal 
$ cp (file) (target path)
```

---
class: left, top
## Copy directory

```terminal
$ cp -r (directory) (target path)
```

---
class: left, top
## Create a new directory (folder)


```terminal
$ mkdir (new folder name)
```


---
class: left, top
## Removing a file

```terminal
$ rm (file)
```

---
class: left, top
## Remove a directory  

```terminal
$ rm -r (directory)
```


---
class: left, top
## WARNING: Did you say `rm`?

### HOW ABOUT `sudo rm -rf /`

DO NOT DO THIS!
```terminal
$ sudo rm -rf /
```

--
<img style="width:80%" src="/gallery/delete.webp">



---
class: left, top
## Updating & Upgrading your Linux

Upgrades are very important. Many hardware drivers issues are being fixed through these updates. Also, security-wise,
updates guarantees your system to be safe against hackable vulnerabilities. For example, *Spectre* and *Meltdown* vulnerabilities that exposed all
 Operating Systems (including Widnows and Linux), for more [info](https://www.pcworld.com/article/3245606/security/intel-x86-cpu-kernel-bug-faq-how-it-affects-pc-mac.html).

```terminal
$ sudo apt-get update
$ sudo apt-get upgrade
```


---
class: left, top
## Installing packages from the apt store

```terminal
$ sudo apt-get install (package name)
```

---
class: left, top
## Installing local `.deb` packages

```terminal
$ sudo dpkg -i (package path)
```

---
class: left, top
## Interesting Appliactions

| Category      | package name                          |
| ------------- | ------------------------------------- |
| Music & Video | vlc, rhythm box (shipped with Ubuntu) |
| PDFs          | Okular, Foxit, PdfShuffler            |
| Screenshots   | Shutter                               |
| C++ IDEs      | Qt Creator, Jet-brains CLion, VSCode  |
| Python IDEs   | Pycharm, Anaconda (Spyder)            |
| Web IDEs      | VSCode, Jet-brains WebStorm           |


---
class: left, top
## Memory Layout

--
![stack](/gallery/stackheap.png)

--

| Flexible languages               | Opinionated languages                     |
| -------------------------------- | ----------------------------------------- |
| * .green[Powerful and efficient] | * .red[Usually inefficient in comparison] |
| * .red[ Overhead to learn ]      | * .green[ Easier to learn ]               |
| * C++, C                         | * Java, C#, Python                        |
---
class: left, top
## Variables on Stack Memory

--
Last week, all our variables were allocated on the stack

```c++
char x = 's';

float pi = 3.1415;

int k = 0;

int j = k;

double e {2.71828};
```

--
- Automatically deleted after going out of their scope.
--
- Very simple.


---
class: left, top
## Address of a Variable in the Memory

* Variables exist in memory. 
* A variable in memory has an address.

---
class: left, top

```c++
// Declare integer x and initialize it with 13.
int x = 13;

// Declare integer y and initialize it with 1.
int y = 1;

// Declare integer z and initialize it with 5.
int z = 5;
```

Their physical presence in memory looks like this:

![](/gallery/stackaddress.png)

---
class: left, top
## Address of a variable in C++

--
But how to get (retrieve) the address of a variable in C++?

* By using `&` (ampersand operator).

--
```c++
int x = 5;

std::cout << &x << std::endl; // Prints: the location of x in memory

```

---
class: left, top
## Pointers 

--
We store the address of a variable in a special type called **pointer**.

- **Pointer** is a primitive data type.
- **Pointer** type occupies **8 bytes** (64-bit machines).
- **Pointer** is declared using the syntax `target_type *`.

--
```c++
int x = 13;
int y = 1;
int z = 5;

// Declare `pointer to integer` px and initialize with address of x.
int *px = &x; 

// Declare `pointer to integer` py and initialize with address of y.
int *py = &y;

// Declare `pointer to integer` pz and initialize with address of z.
int *pz = &z;
```

---
class: left, top
## Primitive Data Types in C++ (Revisited)

#### Primitive Data Types (PDT) in C++

* `bool`: holds logical value, occupies **1 byte** of memory.
* `char`: a character, occupies **1 byte** of memory.
* `int`: an integer, occupies **4 bytes** of memory.
* `float`: a real-number-like, occupies **4 bytes** of memory.
* `double`: like float, but higher precision, occupies **8 bytes** of memory.
--
* pointer: holds the location of a variable in memory, occupies **8 bytes** of memory.

---
class: left, top
## Why using Address?

--
### Flexibility

Addresses gives a lot of flexibility to control variables. For example, you can modify a variable value if you have its address.

```c++
int x = 9;

std::cout << x << std::endl; // prints: 9

int *px = &x ;

// Derefrencing px to access x.
*px = 13;

std::cout << x << std::endl; // prints 13
```

---
class: left, top
### Passing arguments by pointer

--
You can pass a **pointer to variable** as argument to a function.

--
```c++
void sum( double a , double b , double *presults )
{
    // Dereference the presults to access the underlying variable.
    *presults = a + b;
}
int main()
{
    double results = 0;
    
    sum( 13 , 5 , &results ); // Now results has new value.
    
    std::cout << results << "\n"; // Prints: 18
}
```

* this style acceptable in C language. 
* not preferred in C++, and always prefer to return the results.

---
class: top, left
### Cont'd

```c++
void sum( double a , double b , double *presults )
{
    // Dereference the presults to access the underlying variable.
    *presults = a + b;
}
int main()
{
    double results = 0;
    
    sum( 13 , 5 , &results ); 
    // Now results has new value (13 + 5).
    
    std::cout << results << std::endl; // Prints: 18
}
```

--
This is better and simpler.
```c++
double sum( double a , double b )
{
    return a + b;
}

int main()
{
    double results = sum( 13 , 5 );
}
```

---
class: left, top
## Stack Memory vs. Heap Memory

| Stack Memory                            | Heap Memory                                        |
| --------------------------------------- | -------------------------------------------------- |
| * .red[ Limited capacity ]              | * .green[ Large capacity for scalable structures ] |
| * .green[ Automatic memory management ] | * .red[ Manual memory management ]                 |

---
class: left, top
## Variables on Heap Memory

Variables can also be created on heap.

```c++
// Allocate integer with initializing to zero on heap memory, and save the address in px.
int *px = new int{0};

// Allocate integer with initializing to 4 on heap memory, and save the address in py.
int *py = new int(4); // Another syntax to initialize heap memory variables.

int *pz = new int(8);
```

Physically, they would look like this: 

![](/gallery/heapaddress.png)

---
class: left, top
## Memory Management

--
* Variables created on heap memory (using `new` operator), should be deleted manually when they are no longer used. 
* Otherwise, you will allocate a lot of space that will become unusable.


--
```c++
int *px = new int{0};

int *py = new int(4);

int *pz = new int(8);

delete px;
delete py;
delete pz;
```

---
### Important rule for memory management

--
* When you finish coding, make sure to balance heap memory allocations/deallocations.
--
* \#`new` = #`delete`.

---
class: left, top
## Reference types

--
* Very important type in C++, 
--
* Using it in the right way makes your program very efficient. 
--
* **References** are alternative for pointers to enhance the readability of your code.
--
* When you make a reference to a variable, you actually making an alias to that variable.
--
* In other words, you are making another name for the same variable.

---
class: left, top
## Primitive Data Types in C++ (Revisited 2)

#### Primitive Data Types (PDT) in C++

* `bool`: holds logical value, occupies **1 byte** of memory.
* `char`: a character, occupies **1 byte** of memory.
* `int`: an integer, occupies **4 bytes** of memory.
* `float`: a real-number-like, occupies **4 bytes** of memory.
* `double`: like float, but higher precision, occupies **8 bytes** of memory.
--
* **pointer**: holds the location of a variable in memory, occupies **8 bytes** of memory.
--
* **reference**: an alias to an existing variable, occupies **8 bytes** of memory.

---
class: left, top
## References in C++

--
```c++
// Declaration of integer x and initializing with zero.
int x = 0;

// Declaration of reference y and to be reference for x.
int &y = x;

// Now x and y, are the same variable, but with different name.

// Chaning y value, will also affect x, and vice versa.
y = 10;

std::cout << x << std::endl; // prints: 10
```

---
class: left, top
### Cont'd

Recall the example of passing pointer as argument:

```c++
void sum( double a , double b , double *presults )
{
    // Dereference the presults to access the variable results.
    *presults = a + b;
}

int main()
{
    double results = 0;

    sum( 13 , 5 , &results );

    std::cout << results << std::endl;
}
```

---
class: left, top
This can be written in more elegant way using references:

```c++
void sum( double a , double b , double &results )
{
    // No need for dereference as we did in pointers, like it is a real variable!
    results = a + b;
}

int main()
{
    double results = 0;

    // No need to pass the address explicitly.
    sum( 13 , 5 , results );

    std::cout << results << std::endl;
}
```

---
class: left, top
## KISS: keep it simple and stupid

More about [{KISS}](https://en.wikipedia.org/wiki/KISS_principle) principle.

**But again, it is very preferred to use the simplest form when possible**!

```c++
double sum( double a , double b )
{
    return a + b;
}

int main()
{
    double results = sum( 13 , 5 );
}
```

We used pointer and references in previous examples just for explanations!

---
class: left, top
# Thank you

* Please Read the notes <a href="/2019/data-structures/notes/2_week2a" target="_blank">{Part 1: Memory, pointers, and references}</a>
* Assignment [{page}](/2019/data-structures/assignments/2_week2a.html)
* Deadline: next Monday 25/2/2019


</textarea>
