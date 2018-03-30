---
layout: page
course: "sbe404"
category: "notes"
year: "2018"
title:  "Week 7: Segmentation (Thresholding and Region growing)"
by: "Eslam"
---

* TOC
{:toc}


## Image Segmentation

Image segmentation is the process of partitioning the image into isolated areas or segment. Each segment has similar features, for example have same intensity or same color etc, and is considered as an object in the image. 

There are many applications of image segmentation of medical images including automatic diagnostic applications and other application related to treatment. Treatment planning is an example of 3D image segmentation. 

3D object is reconstructed from series of images. Here an example of reconstruction of 3D human skull. 

<span style="display:block;text-align:center"><img style="width:45%"  src="../images/Selection_061.png"></span>

From that skull we can segment different interested regions or object. Here we are interested in segmentation of mandible, maxilla, upper and lower tooth. Each object now is separated and we can treat with it independently. Using these object dentist can plane process of dental implant or orthodontic treatment or any other process. 

<span style="display:block;text-align:center"><img style="width:60%"  src="../images/results.png"></span>

This was a project I worked on for a subject in my pre-master year under title "An optimized technique for 3D segmentation for orthodontic treatment plane". I used [VTK](https://www.vtk.org/) for reconstruction and segmentation processes and [Qt](https://www.qt.io/) for GUI design. Segmentation was based on thresholding and connectivity testing which is similar to region growing approach but in 3D.

## Histogram Based Segmentation

* Image Binarization

* Only two classes (object , background)

* Basic Idea 
$$
I(x,y) = 
\begin{cases}
0, I(x,y) < T \\\ 
1, I(x,y) > T 
\end{cases}
$$

* How to select threshold ?


class: left, top
## Optimal Threshold
* Object, background histogram 
<img style="width:85%" src="../images/Selection_065.png"> 

* Example 

<img style="width:85%" src="../images/Selection_064.png"> 

## Otsu Thresholding 
* Trying to find Optimal threshold

* Optimal threshold in range 0 to 255

* Recall (We have two classes)

* Criteria 
1. Select t that minimize within class variance.

2. Select t that maximize between class variance.


## Otsu Thresholding cont'd
* Calculating within class variance 
$$
\sigma_w^2  = c_1 \sigma_1^2 + (1-c_1) \sigma_2^2 
$$
* Calculating Between class variance 
$$
\sigma_b^2  = c_1 (1-c_1) (\mu_1 - \mu_2)^2  
$$
Where $$c_1$$ is cumulative sum at t 
* Recall 
$$
E[x] = \sum x p(x)
$$
and 
$$
\sigma^2 = E[x^2] - \mu^2
$$


## Basic Algorithm 
* Basic algorithm is 
* Maximize between class variance 
```python 
Get Histogram of the image
Get relative histogram (PDF)
Get cumulative Histogram (CDF)
initialize OptThreshold = 1 and maxVariance = 0
For each t in range 1 to 255 
  m1 =  mean value class 1 
  m2 =  mean value class 2  
  c1 = CDF[t]
  varBet = c1 * (1-c1) * (m1 - m2)**2   
  if value > maxVariance 
      maxVariance = value
      OptThreshold = t  
```

**Lets try to implement it** 

* What about minimizing within class variance 

## Seed Pixels (Region Growing)
* Initial Seed 
* Check connected pixels 
* Add them to region (Intensity , colored based)
* repeat.

<img style="width:85%" src="../images/Selection_066.png"> 

