---
layout: page
course: "sbe201"
category: "assignment"
year: "2018"
title:  "Assignment 1 - part 1: Your first experience with Git and our Github classroom"
by: "Asem"
pdf: true
---


## Objectives

* Registration on both Github and Bitbucket.
* Registration on our Github classroom.
* First experience with git.
* First experience on submitting on the Github classroom.

## Prerequisites (Before you start)

* **Required**: Read the notes of the first week (part 2): \[[Part 2: Using Git and Github]({{ site.baseurl }}{% link 2018/data-structures/notes/1_week1b.md %}){:target="_blank"}\].
* **Recommended**: Play with the [interactive git tutorial](https://try.github.io/levels/1/challenges/1).

## Grading

Since all steps are straightforward and dependent on each other, getting to the last step secures you the full mark of this part (60% of this week).

## Deadline

**Tuesday 6/2/2018 11:59 PM**.

## 1. Registration on Github and Our Classroom

* If you do not have a GitHub account, [sign-up new account](https://github.com/join?source=header-home), then follow any further instructions by the website. You should receive a message in your e-mail to verify your e-mail. **Do not proceed to next step unless you verify your e-mail address**.
* Afterwards, send a message to me (i.e `asem.a.abdelaziz@gmail.com`):

  * subject: [SBE201] classroom registration
  * contents:

      1. your github id/name
      2. your bench number (If you don’t know your bench number, refer to this [document](http://eng.cu.edu.eg/wp-content/uploads/StudentsLists2016/SBE/2.xls)).
      3. first and last names.

* Visit the [classroom registration page](https://classroom.github.com/a/1jyf5WHm), and give the classroom authorization to access your profile data. If you find an entry in the list that belongs to you 2\_\[BN\]\_\[Firstname\]\_\[Lastname\], click on. Otherwise, skip to next page. Press **Accept this assignment**.

## 2. Submitting your first project (single line) on our classroom

* First, register yourself for the assignment from this [link](https://classroom.github.com/a/FombgUoF).
* Similarly, give the classroom authorization to access your profile. If you find an entry in the list that belongs to you 2\_\[BN\]\_\[Firstname\]\_\[Lastname\], click on. Otherwise, skip to next page. Press **Accept this assignment**.
* You should find this dialoge, **click on the highlighted link:** ![dialog](/gallery/assignments/ds/step1.png).
* Copy your repository link from the repository page: ![step2](/gallery/assignments/ds/step2.png).
* In your terminal, clone the repository in the current directory (you can change directory before cloning): 
{% highlight bash %}
git clone <the link you have copied>
{% endhighlight %}
For example, `git clone https://github.com/sbme-tutorials/sbe201-week1-first-project-Asem0.git`.
* Change directory to the directory of the downloaded repository. For example, `cd sbe201-week1-first-project-Asem0`
* You do not need to initialize that repository, it is already initialized and the current files are controlled by the repo.
* Open the file `favorite-saying.txt` and add a line of saying that you have recently read and impacted you, also include the name of the sayer (no politics please :blush:, be professional).
{% highlight bash %}
gedit favorite-saying.txt
{% endhighlight %}
![pumpa](/gallery/assignments/ds/pumpa.png)
* Save the file.
* Commit changes on that file, then submit:

{% highlight bash %}
$ git commit -a -m "Add a saying by <the sayer>"
$ git push origin master
{% endhighlight %}