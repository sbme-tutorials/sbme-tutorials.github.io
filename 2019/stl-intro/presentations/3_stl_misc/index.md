---
layout: presentation
style: laminal4
highlighter: github
course: "stl2019"
category: "presentation"
year: "2019"
title: "Introduction to the STL"
by: "Asem"
author: "Asem Alaa"
---

<textarea id="source">

---
## Output of this tutorial

1. Classes in STL
2. STL Containers (data structures)
3. STL Iterators
4. STL Algorithms

???
* Comparison with Python

---
## STL categories


---
#### The **Segmentation fault** error:

* Dereferencing a `nullptr`.
* Dereferencing an un-initialized pointer, as a side-effect of undefined behavior.
* Dereferencing a pointer of a de-allocated place:
  * De-allocated place in stack memory after going out of scope.
  * De-allocated place in heap memory after `delete`ing that place using its pointer.
* Exceeding array boundaries.
* Stack overflow


---
### Memory Management and Memory Leakage

### Valgrind

---
#### Installing Valgrind

```terminal
sudo apt-get install valgrind
```

---
#### Running Valgrind

In order to trace your code to the point of the crash you need to compile your code with an additional flag `-g`. The flag `-g` tells your compiler to compiler your program in *Debugging* mode.

```bash
g++ -g -std=c++11 -Wall test.cpp -o test
```

* `-g` for debugging mode.
* `-std=c++11` to use the C++ standards of 2011.
* `-Wall` to emit any compilation warnings, very useful flag.
* `test.cpp` the source file that has a `main` function.
* `-o test` a flag for the compiler output followed by the output name of the executable.

```bash
valgrind -v --leak-check=full --show-leak-kinds=all ./test
```


---
## Testing


* In practice, testing your program is done in a more principled way.
* read about [Test-Driven Development (TDD)](https://en.wikipedia.org/wiki/Test-driven_development)
* In C++, there are famous unit testing frameworks, for example:
    * [{Google Test}](https://github.com/google/googletest).
    * [{Catch2}](https://github.com/catchorg/Catch2).
    * [{Boost.Test}](http://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html)
* read about continuous integration (CI)



---
## Self-reading

* Destructors
* [Learn C++](https://www.learncpp.com/)

</textarea>
