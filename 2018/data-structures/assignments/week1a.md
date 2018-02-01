---
layout: page
course: "sbe201"
category: "assignment"
year: "2018"
title:  "Assignment 1 - part 2: Your first experience with Git and our Github classroom"
by: "Asem"
pdf: true
---


## Objectives

* Registration on both Github and Bitbucket.
* Registration on our Github classroom.
* First experience with git.
* First experience on submitting on the Github classroom.

## Prerequisites

Read the notes of the first week: \[[Part 1: C++ Basics]({{ site.baseurl }}{% link 2018/data-structures/notes/1_week1a.md %}){:target="_blank"}\] \[[Part 2: Using Git and Github]({{ site.baseurl }}{% link 2018/data-structures/notes/1_week1b.md %}){:target="_blank"}\].

## Grading

Since all steps are straightforward and dependent on each other, getting to the last step secures you the full mark of this part (50% of this week).

## Deadline

**Monday 12 AM**.

## 1. Registration on Github and Our Classroom

* Sign-up new account, then follow any further instructions by the website. You should receive a message in your e-mail to verify your e-mail. **Do not proceed to next step unless you verify your e-mail address**.
* Afterwards, send a message to me (i.e `asem.a.abdelaziz@gmail.com`):

  * subject: [SBE201] classroom registration
  * contents:

      1. your github id/name
      2. your bench number (If you don’t know your bench number, refer to this [document](http://eng.cu.edu.eg/wp-content/uploads/StudentsLists2016/SBE/2.xls)).
      3. first and last names.

* Visit the [classroom registration page](https://classroom.github.com/a/1jyf5WHm), and give the classroom authorization to access your profile data. If you find an entry in the list that belongs to you 2\_\[BN\]\_\[Firstname\]\_\[Lastname\], click on. Otherwise, skip to next page. Press **Accept this assignment**.

## 2. Submitting your first single line project on our classroom

* Clone the repository. You do not need to initialize that repository, it is already initialized and the current files are controlled by the repo.
* Open the file `favorite-saying.txt` and add a line of saying that you have recently read and impacted you, also include the name of the sayer (no politics please :), be professional).
* Save the file.
* Commit changes on that file:

{% highlight bash %}
$ git commit -a -m "Add a saying by <the sayer>"
$ git push origin master
{% endhighlight %}