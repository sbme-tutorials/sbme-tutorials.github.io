---
layout: page
course: "sbe201"
category: "assignment"
year: "2020"
title:  "Assignment 1: Markdown Resume and Revision on C++"
by: "Asem"
pdf: true
---


## Objectives

* Git: Collaborate in teams using Git.
* Markdown: Use Markdown as a markup language to write simple resume.
* C++: Creating variables.
* C++: Using arithmetic operations on variables.
* C++: Using control statements: If, else if, else, while, for, switch-case.
* C++: Play with simple functions.
* C++: Play with namespace.

## Prerequisites (Before you start)

* Read the notes of the first week [Part 1: C++ Basics]({{ site.baseurl }}{% link 2020/data-structures/notes/week01a.md %}){:target="_blank"} and [Part 2: Basics of Git and Github]({{ site.baseurl }}{% link 2020/data-structures/notes/week01b.md %}){:target="_blank"}.
* Install an editor for Markdown files like [VSCode](https://code.visualstudio.com/download).
* Install Qt for the C++ part. See [Installing and running Qt Creator IDE]({{ site.baseurl }}{% link 2020/data-structures/notes/qt.md %}){:target="_blank"}

## Deadline

**TBA**.

## Assignment Registration: creating a team or joining an existing team

* Know your team id from [this sheet](TBA).
* Join the assignment page [from here](TBA). **skip** this first dialogue.
    * If you are the team leader, create a new team using the label **SBE201-2022 Teamxx** (e.g for team \#1, **SBE201-2022 Team01**).
    * Otherwise, if you are not the team leader, find your team **label** as **SBE201-2022 Teamxx**, where `xx` is the group number in two digits, then join it. If you don't find it then ask your team leader to register your team as described above.
* After that, team members can clone the remote repository to their local machines.

## Assignment Part 1: Markdown Resumes

#### Start working in your resume

* After cloning your repository of your team, open the folder using *Visual Studio Code*, and work in your Markdown file.
* The team should write their plain resumes in separate files. You should find **6 files**, choose the one associated with order your name appeared [this sheet](TBA).
* Start drafting a basic resume of yours, you may use [this file](/2020/data-structures/assignments/resumes/asem) as a template.
* You can find extra guidelines in the README.md file of your repository.
* After finishing, add your name in the table in the `README.md` file.
* [A reference for GitHub emojis](https://gist.github.com/rxaviers/7360908)

## Assignment Part 2: C++ Basics

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
$ git commit -a -m "solved all problems, where is my GitHub sticker?!"
$ git push origin master
```

* You can push all solutions with a single `commit` and a single `push`.
* You can also solve each problem separately and `commit` and `push` for each problem you solve:

  * So you practice yourself with `git` commands.
  * So you realize some significance of using `git` to work on large projects.
