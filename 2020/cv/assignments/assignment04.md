---
layout: page
course: "sbe404b"
category: "assignment"
year: "2020"
title:  "Assignment 4: Eigenfaces"
by: ["Eman Marzban","Asem Alaa"]
pdf: true
---

## Objectives

1. Given standard face datasets 
   * http://vis-www.cs.umass.edu/lfw/ 
   * Consider images that contain only faces at different poses, lighting, expression, etc.
2. Split the data set to training and test sets; e.g. 70% and 30% respectively.
3. Use the training set to generate eigenfaces
4. Use the test set to recognize faces and report the performance

## Deadline

**Sunday 10/5/2020 11:59 PM**

## Joining to Assignment Repository

Refer to this sheet to know your **Group number**: (https://docs.google.com/spreadsheets/d/1H0mGNnDtruLanYVxQH6439rXLTpPglXzglBmYt1J_ow/edit?usp=sharing)

1. Register your team in the assignment through [https://classroom.github.com/g/6mrU3o1l](https://classroom.github.com/g/6mrU3o1l).
2. Join your team that you already worked with in the previous assignment.

## Deliverables

You will start working from the source code you delivered for previous task.

Only one member in each team will do the following:

1. First, copy the remote url of the newly generated repository.
2. From the folder of the previous repository, upload the source to the new repository.

For example, for team **SBE404-2020-Team01**, in the folder of the previous task, the responsible member may run the following command:

```bash
git push git@github.com:sbme-tutorials/cv404-2020-assignment-04-sbe404-2020-team01.git master -u
```

Now you will find your work of the previous task uploaded to the new repository. Now clone the new repository in an independent folder.


### A) Computer Vision Functions

You need to implement Python functions which will support the following tasks:

1. Load standard face dataset that contain only faces at different poses, lighting, expression, etc.: 
      * [http://vis-www.cs.umass.edu/lfw/](http://vis-www.cs.umass.edu/lfw/)
2. Split the data set to training and test sets; e.g. 70% and 30% respectively.
3. Construct the Eigenfaces from the training images, and keep the Eigenfaces that satisies a *given explained variance*.
4. Project the training data to the selected Eigenfaces to get a vector of coefficients per training image. 
5. Load the test set images (not used in the training) and project to the slected Eigenfaces to get a vector of coefficents per test image.
6. Recognize the face in the test image using the *best match* or *k-Nearest Neighbor (kNN)* against the coefficients of training images. FYI, best match is *kNN* with *k=1*.
7. Display the original image from test against the best match image from the training.

* Add new Python file `CV404Recognition.py` to organize your implementation of the core functionalities.

Important notes:

* You should implement these tasks **without depending on OpenCV library or alike**.
* You should not include any GUI related lines within `CV404Recognition.py`, it should include the core computer vision functionalities.
* You should have only one scipt file to run the whole GUI.
* More than 1-2 scenarios lead to your program crash will affect your submission score.
* Plagiarizing lines will not be tolerated.
* Every member should have clear contribution in the task and that should be obvious through the git commits.

### B) GUI Integration

Integrate your functions in part (A) to new tabs in the following Qt suggested design (you can develop your own UI if it enhances the usability):

| Tab 9 |
|---|
| <img src="tab9.png" style="width:1100px;"> |