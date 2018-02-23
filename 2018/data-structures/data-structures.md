---
layout: coursepage
category: "coursepage"
course: "sbe201"
year: "2018"
---

# Data Structures \(SBE201\) - Spring 2018

## Teaching Staff

Instructor: Prof. Ahmed H. Kandil  
Demonstrator:  Eng. Asem Alaa  

## Lecture Hours

**Tuesday**, **1st slot** (+2nd slot each two weeks).

## Section Hours

| Section | Day | Time Slot |
|---------|-----|-----------|
|   1     | Sunday | 3rd |
|   2     | Sunday | 4th |

## Office Hours

| Day | Time |
|-----|-----------|
| Sunday | from **10am** to **12pm** |
| Monday | from **4pm** to **6pm** |

Exception: first two weeks you are very welcome to visit any day from **4pm** to **6pm** (exclude Monday).

## Course Outline

| Week | Data Structures & C++ | Ecosystem & Miscellaneous |
|------|----------------------|-----------|
| 1 | **Introduction**: Brief intro to DS; C++ Basics; A welcome to our guest *Ahmed Magdy Elfarrash* | Briefly: Unix, compilation, git, github |
| 2 | Static and Dynamic Arrays; Categorize your logic with `namespace` scopes; Processing command line arguments (`argc` & `argv`)  | Compilation of multiple files; Basic Unix commands; bitbucket |
| 3 | Array-Based Linked List; Naming conventions; Const correctness | Brief intro to build systems |
| 4 | Array-Based Stack; Array-Based Queue; C++ template structs | Brief intro to  git for teams; `.gitignore` file |
| 5 | Binary Trees; C++ classes and objects  | Briefly: CMake; Git on large scale; How to contribute on **this** website using pull requests? |
| 6 | **Open Talk 1**: C++ access control on class members; Brief intro to STL; Interesting applications in C++ | Markdown vs. WYSIWYG editors; Mercurial |
| 7 | Bubble sort; Selection sort  | Open source vs. proprietary software  |
| 8 | Divide and conquer: merge sort, quick sort; Recursion  | Briefly: Development on Windows |
| 9 | Binary search on sorted array; Binary search tree (BST)  |  Conan.io; External dependencies |
| 10 | Algorithms complexity: big O notation  | Documenting your code |
| 11 | Project  | Documenting your project on the website using Markdown and pull requests |
| 12 | **Open Talk 2**: Other programming languages; Data Structures in Bioinformatics and other domains; C++ libraries, IDEs, and blogs you need to know about; STL vs. Qt vs. Boost | clang-tidy; MOOCs: Coursera & Edx |

## Tutorials

1. Week 1:
    * [Slides]({{ site.baseurl }}{% link 2018/data-structures/presentations/1_week1/index.html %}){:target="_blank"}
    * Section Notes: \[[Part 1: C++ Basics]({{ site.baseurl }}{% link 2018/data-structures/notes/1_week1a.md %}){:target="_blank"}\] \[[Part 2: Using Git and Github]({{ site.baseurl }}{% link 2018/data-structures/notes/1_week1b.md %}){:target="_blank"}\].
    * Assignment: \[[Part 1: Git]({{ site.baseurl }}{% link 2018/data-structures/assignments/1_week1a.md %}){:target="_blank"}\] \[[Part 2: C++]({{ site.baseurl }}{% link 2018/data-structures/assignments/1_week1b.md %}){:target="_blank"}\]
    * [Assignment resubmission]({{ site.baseurl }}{% link 2018/data-structures/assignments/1_week1re.md %}){:target="_blank"}
    * [Special Gift from Github + Linux Basic Commands + Excercise]({{ site.baseurl }}{% link 2018/data-structures/presentations/1_week1_recap/index.html %})
2. Week 2:
    * [Slides]({{ site.baseurl }}{% link 2018/data-structures/presentations/2_week2/index.html %}){:target="_blank"}
    * Section Notes: \[[Part 1: Memory, pointers, and references]({{ site.baseurl }}{% link 2018/data-structures/notes/2_week2a.md %}){:target="_blank"}\].
    * [Code Styling]({{ site.baseurl }}{% link 2018/data-structures/notes/2_code_formatting.md %}){:target="_blank"}
    * [Assignment]({{ site.baseurl }}{% link 2018/data-structures/assignments/2_week2a.md %}){:target="_blank"}
3. Week 3:
    * [Slides]({{ site.baseurl }}{% link 2018/data-structures/presentations/3_week3/index.html %}){:target="_blank"}
    * Section Notes: \[[Part 1: Static Arrays and Dynamic Arrays]({{ site.baseurl }}{% link 2018/data-structures/notes/3_week3a.md %}){:target="_blank"}\] \[[Part 2: Command Line Arguments and Compilation of Multiple Files]({{ site.baseurl }}{% link 2018/data-structures/notes/3_week3b.md %}){:target="_blank"}\].
    * [FAQ #1: Why `using namespace arbitrary_name;` is a bad practice]({{ site.baseurl }}{% link 2018/data-structures/notes/3_faq1.md %}){:target="_blank"}
    * [FAQ #2: Why `int *p = &x` != `*p = &x`]({{ site.baseurl }}{% link 2018/data-structures/notes/3_faq2.md %}){:target="_blank"}
    * [FAQ #3: Why not using `std::cin` inside functions of particular logic]({{ site.baseurl }}{% link 2018/data-structures/notes/3_faq3.md %}){:target="_blank"}
    * Assignments: \[[Assignment: Part 1]({{ site.baseurl }}{% link 2018/data-structures/assignments/3_week3a.md %}){:target="_blank"}\]

## Frequently Asked Questions

### I have a Unix-based system installed other than Ubuntu 16, should I install Ubuntu 16 instead?

* If you are using a different distribution (e.g Fedora, Suse, etc.), it is fine as long as it is still receiving support through updates.
* If you have Ubuntu 17, it is fine but you need to know that version 17 is not long term support (LTS) version. Ubuntu 16 support will last until 2021.
* If you have an older version (e.g Ubuntu 14.03), make sure that your version is still receiving support from [Ubuntu release end of life](https://www.ubuntu.com/info/release-end-of-life).