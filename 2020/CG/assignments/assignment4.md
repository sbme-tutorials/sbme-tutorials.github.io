---
layout: page
course: "sbe306"
category: "assignment"
year: "2019"
title:  "Assignment 4: Volume Rendering (VTK)"
pdf: true
---

## Objectives

* Loading DICOM images
* Surface rendering 
* Ray casting rendering
* GUI application 


## Prerequisites (Before you start)

* [week7]({{ site.baseurl }}{% link 2019/CG/notes/7-week7.md %}){:target="_blank"}

* [week8]({{ site.baseurl }}{% link 2019/CG/presentations/8_week8/index.md %}){:target="_blank"}

## Deadline

Deadline for this assignment is **17/04/2019**


## Joining to Assignment Repository

This is a Group assignment 4 members maximum.

1. Go to the [Assignment Page](https://classroom.github.com/g/7frpyset).
2. Accept the assignment.
3. Open the link and Clone repository.

## Part 1: Programming

* Build your own volume rendering app with VTK & Qt
* Use datasets provided in data directory (Head and Ankle)

**Note** You must use [vtkDICOMImageReader](https://vtk.org/doc/nightly/html/classvtkDICOMImageReader.html#details) object.

* Features 
    * Support loading DICOM series dynamically using load button
    * Surface rendering (With adjustable iso value) using sliders
    * Ray casting rendering (with a fixed transfer function)
        * Bonus (Adjustable transfer function)

## Part 2: Written

Report all details about your implementations in markdown file (Report.md). Report must show sample results of your code. Organize the report and be concise. State issues you faced in the assignment and how you treated with it. Mention any kind of contribution of other students.

### Submitting

```terminal
git commit -a -m "solved all problems!"
git push origin master
```


