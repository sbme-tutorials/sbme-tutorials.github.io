---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Code Styling (formatting): Enhancing Your Code Readability"
by: "Asem"
---

* TOC
{:toc}


## Introduction

Always make your code clean and tidy. This will enhance the readability for your code, and accordingly saving a lot of time (and somtimes saving lives).

### Better Errors Detection

Styling your code during development makes it easier to detect basic errors, like **braces inbalances** (i.e missing or excessive braces).

### Healthy Collaboration

When you work with a team, you have to make your code representing your logic very clearly. This will also guarantees a healthier friendships (if your team members are also your friends).

![](/gallery/code_quality.png)

### Maintainability

With a good code quality, you can always return back to your code after a long time to make some edits and new features.

![](/gallery/code_quality_3.png)

## Formatting Your Code on Visual Studio Code

### Install the C/C++ Extension

![](/gallery/vscode_formatting1.png)

![](/gallery/vscode_formatting2.png)

### Use Shortcuts During Coding

After finishing several lines of code let the Visual Studio Code auto-style your code using `Ctrl+Shift+I`. You can also do it for the entire source code.

## Naming Conventions

The style we use in naming variables should be consistent. There are many naming conventions out there on the web. You can use any naming convention, **but you should stick to that convention for the whole project for consistency**. Moreover, you should always pick a **concise** and **descriptive** name for your variables.

### Function Names

Functions are made to perform some actions. Try to name your function describing what it does in a concise way.

```c++
double s( double a , double b); // Bad example

double SummationOfTwoDoubles( double a, double b); // Lengthy example

double sum( double a, double b); // Looks fine

double Sum( double a, double b); // Also good. But this is another naming convention.


double ecganls( double *ecg , int size ); // Very vague!

double analyzeECG( double *ecg, int size ); // Looks good. It is called camelCase style.

double AnalyzeECG( double *ecg, int size ); // Looks good. It is called PascalCase style.

double analyze_ecg( double *ecg, int size); // Looks good. A common style for Python language.
```

### Pointer Variables

To distinguish pointers from other types, let's give it a special prefix in their names.

```c++
int m = 9;
double *x = &m; // Not so readable.
double *pm = &m; // Might be better.
double *p_m = &m; // Also better. 
```


