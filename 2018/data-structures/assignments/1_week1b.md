---
layout: page
course: "sbe201"
category: "assignment"
year: "2018"
title:  "Assignment 1 - part 2: Revision on C++"
by: "Asem"
pdf: true
---


## Objectives

* Creating variables.
* Using arithmetic operations on variables.
* Using control statements: If, else if, else, while, for, switch-case.
* Simple functions
* Make custom namespace

## Prerequisites (Before you start)

* **Required**: Read the notes of the first week: \[[Part 1: C++ Basics]({{ site.baseurl }}{% link 2018/data-structures/notes/1_week1a.md %}){:target="_blank"}\] .

## Grading

* This part constitutes 40% of the week grades.
* Grading per line.
* +20% bonus.

## Deadline

**Tuesday 14/2/2018 11:59 PM**.

## Writing Your First C++ Basics

* First, register yourself for the assignment from this [link](https://classroom.github.com/a/A6ntQkKJ).

![](a1.png)

then,

![](a2.png)

then,

![](a3.png)

* As you did in the first part, clone the remote repository to your local machine.
* Jump to the assignment folder and open the `main.cpp` file.
* You will find the questions as in-line comments. Questions `P1` and `P3` are solved for you to be more familir.
* If you feel uncomfortable with any question, do not panic, you can ask for explanation at office hours before deadline.

## Important notes

### How to compile my source code

After you attempt all problems, open the terminal on the task folder. Make sure you are on the right directory by listing the files and finding `main.cpp` file.

```terminal
$ ls
main.cpp
```

To compile, you need to introduce to your compiler the `main.cpp` and the executable name (which is an arbitrary name)

```terminal
$ g++ main.cpp -o app
```

To run,

```terminal
$ ./app
```

🎉🎉🎉

### About submitting

* As you did in first part, after solving problems, save the file, then commit and push.

```terminal
$ git commit -a -m "solved all problems, where is my github sticker?!!"
$ git push origin master
```

* You can push all solutions with a single `commit` and a single `push`.
* You can also solve each problem separately and `commit` and `push` for each problem you solve:

  * So you practice yourself with `git` commands.
  * So you realize some significance of using `git` to work on large projects.
