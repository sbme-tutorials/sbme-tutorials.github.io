---
layout: page
title:  "Assignment 3: Texture, Models & Medical Visualization"
pdf: true
---

## Objectives

Part 1

* Object animation. 
* texture mapping
* loading external objects.
* lighting and coloring.

Part2

* Loading DICOM images
* Surface rendering 
* Ray casting rendering
* GUI application 
* Report your results and comments.

## Deadline

Deadline for online submission will be  on  **Tuesday 1/6/2021 11:59 PM**

## Joining to Assignment Repository

This is a Group assignment 5 members maximum.

1. Go to the [Assignment Page](https://classroom.github.com/g/w4lJaTKb).
2. Accept the assignment.
3. Wait till your repository created.
4. Open the link and Clone repository.

## Part 1: 

Previously you designed the a robotic body with full of movements.
1. draw a floor and put the full body on top of it.
2. put a texture on the floor
3. use a menu binned to the right mouse button to change the floor texture.
4. you are required to to design two animations:
    * Using the robotic body without interaction with any object.
    *  The robotic body should interact with loaded objects

5. download different objects and load it in your scene to make sense of the animation environment.

## Part 2: 

* Build your own volume rendering app with VTK & Qt
* Use datasets provided in data directory (Head and Ankle)

**Note** You must use [vtkDICOMImageReader](https://vtk.org/doc/nightly/html/classvtkDICOMImageReader.html#details) object.

* Features 
    * Support loading DICOM series dynamically using load button
    * Surface rendering (With adjustable iso value) using sliders
    * Ray casting rendering (with a fixed transfer function)
        * Bonus (Adjustable transfer function)


## Part 3: Written

Report all details about your implementations in markdown file (Report.md). Report must show sample results of your code. Organize the report and be concise. State issues you faced in the assignment and how you treated with it. Mention any kind of contribution of other students.


## Important Notes 

* Each team should design unique animations than other teams.
* All images used in texture mapping in the provided code should be .bmp format.
* you should neither use the provided texture not the provided object in class tutorial **don`t be lazy and download another object anywhere**.
* You are allowed to discuss task problems with your mates. But code must be on your own.
* You can get code lines from internet and include them in your own code and you must cite the source.
* Sharing few code lines of your own with your classmates is allowed for identifying and fixing bugs, it is not allowed to see others solution before submitting.
* Report must include summary about your implementation, sample results and issues that you faced and how you fixed it.
* You must mention any kind of contribution of other mates.

### Submitting

```terminal
git commit -a -m "solved all problems!"
git push origin master
```