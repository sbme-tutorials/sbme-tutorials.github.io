---
layout: page
course: "sbe404"
category: "notes"
year: "2018"
title:  "Week 4: Hough Transform and Corner Detector"
by: "Eslam"
---

* TOC
{:toc}

## Readings 
[Survey of Hough transform](https://arxiv.org/pdf/1502.02160.pdf)
## Review 
What we have taken ?? 
Image Filtering as preprocessing, edge detection. 
What will we do with edge images?
object detection and shape recognition.
How can we detect lines and circles in images ?  
What is the applications? 
Object recognition and tracking. Medical Application A real-time tracking system of surgical instruments in laparoscopic operations
## Hough Line
### Original Hough transform
Mapping pixels to another space based on equation of line. 
### Alternative Parameter Space 
Limitation of equation of line for division by zero. so move to polar coordinate
### Algorithm
```
Extract edges of the image How ?? Canny
initialize parameter space rs, thetas
Create accumulator array and initialize to zero
for each edge pixel     
    for each theta
        calculate r = x cos(theta) + y sin(theta)
        Increment accumulator at r, theta
Find Maximum values in accumulator (lines)
Extract related r, theta
```
**Lets try to implement**

## Hough Circle
### Parameter Space (3D Space)

### Algorithm

## General Hough Transform 

### Basic Algorithm

## Corner detection 
Why Corners ? 
Uniqueness 
Corner as an image feature?
Strong and unique feature. 
### Hessian Matrix 
### Harris operator
## What's Next 
Feature descriptor.
