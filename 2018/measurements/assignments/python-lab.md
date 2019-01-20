---
layout: page
course: "sbe206a"
category: "notes"
year: "2018"
title:  "Python lab"
by: "Asem"
---

* TOC
{:toc}

## Objectives

* Fresh introduction to basics of Python.
* Writing functions in Python.
* Using Numpy library.
* Solving basic statistical problems using Python.
* Basic normality test using Chi-squared in Python.

## Prerequisites (Before you start)

* **Required**: background in basics of Python and Numpy.

## Deadline

**Friday 25/1/2019 11:59 PM**.

## 1. Registration on Github and Our Classroom

* Register to the [task page](https://classroom.github.com/a/vUIXJKqc). Press **Accept this assignment**.

## 2. Working in your assignment

After your clone your assignment to your local machine, you can start working on your assignment by using Jupyter Notebook or Google Colaboratory.

You should find 3 jupyter notebooks:

1. `mathfuns.ipynb`, which walks you through writing simple functions in Python, and comparing your output with expected output.
1. `errors.ipynb`, which you are required to solve the 2nd question you had in the Midterm using Python.
1. `histograms.ipynb`, which requires you to plot histogram of given data and test their normality.

### A) Using Jupyter Notebook

Interestingly, there is a big scientific package that is shipped with Python, Spyder IDE, Jupyter Notebooks, scientifice libraries, and others in a single big package, Anaconda!

You can download Anaconda from its official website:

[![](https://www.anaconda.com/wp-content/themes/anaconda/images/logo-dark.png)](https://www.anaconda.com/download)

Make sure to download Anaconda compatible with **Python 3.7**.


### B) Using Google Colaboratory

Alternatively, you can open and run the tasks notebooks using [Google Colaboratory](https://colab.research.google.com).

* Upload the notebooks of your tasks from your local machine.



## 2. Submitting your task on our classroom


* After you finish your tasks on either Jupyter notebooks or Google Colaboratory, make sure that the repository files are updated with your solutions.
* Commit changes on task files, then submit:

{% highlight bash %}
$ git commit -a -m "Solving problems"
$ git push origin master
{% endhighlight %}