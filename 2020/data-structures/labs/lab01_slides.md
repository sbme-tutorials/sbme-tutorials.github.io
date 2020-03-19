---
layout: presentation
style: laminal
highlighter: ir-black
code: "SBE201"
course: "SBE201 Data Structures and Algorithms"
category: "presentation"
semester: "Spring"
year: "2020"
title: "Lab 1: Linux and C++ Revision"
by: "Asem Alaa"
author: "Asem Alaa"
---

    
<textarea id="source" markdown="1">

# Lab 1

## Linux and C++ Revision

##### Presentation by *{{ page.author }}*

{% include presentation-margins.html %}

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
updates guarantees your system to be safe against hackable vulnerabilities. For example, *Spectre* and *Meltdown* vulnerabilities that exposed all Operating Systems (including Widnows and Linux), for more [info](https://www.pcworld.com/article/3245606/security/intel-x86-cpu-kernel-bug-faq-how-it-affects-pc-mac.html).

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
## C++ Struct

### Types in C++

--
* Premitive Data Types (PDT), or first-class citizens, such as: `int`, `double`, `char`, etc.
--
* Custom, user-defined types, for example using: `struct` or `enum class`.


---
### `struct` example


Consider the following application:


```c++
double area( double w , double h )
{
    return w * h;
}

int main()
{
    double w = 0, h = 0;

    std::cin >> w >> h;

    std::cout << area( w, h ) << std::endl;
    return 0;
}
```

---
### `struct` example (cont'd)

Using `struct`:

--
```c++
struct Rectangle
{
    double w;
    double h;
};
```

--
* `Rectangle` is now a custom type, 
--
* consists of two `double`s. 
--
* Think of it as a package.


---
### `struct` example (cont'd)

--
```c++
struct Rectangle
{
    double w; // First member
    double h; // Second member
}; // Don't forget a semicolon here!
```

--
```c++
double area( Rectangle rectangle )
{
    return rectangle.w * rectangle.h;
}
```

--
```c++
int main()
{
    Rectangle rect;
    rect.w = 3;
    rect.h = 5;
    std::cout << area( rect ) << std::endl;
    return 0;
}
```

---
### `struct` example (cont'd)


```c++
struct Rectangle
{
    double w; // First member
    double h; // Second member
}; // Don't forget a semicolon here!
```


```c++
double area( Rectangle rectangle )
{
    return rectangle.w * rectangle.h;
}
```


```c++
int main()
{
    Rectangle rect;
    std::cin >> rect.w >> rect.h;
    std::cout << area( rect ) << std::endl;
    return 0;
}
```
</textarea>
