---
layout: page
course: "sbe404"
category: "notes"
year: "2018"
title:  "Week 9: Revision"
by: "Eslam"
---
* TOC
{:toc}

# Image Segmentation
For Image segmentation we studied three methods 

* Histogram based segmentation (Image thresholding and binarization)

* Region based segmentation (Region or seed growing) 

* Clustering based segmentation (Mean shift segmentation) 

## Mean Shift 

Basic steps are : 

1. Select a random mean.
2. Get points around this mean within a specific bandwidth and multiply them by selected kernel. 
3. Calculate the mean of these points.
4. Repeat till convergence (new mean $$\sim$$ old mean) within a threshold.
5. Cluster all visited points to that final mean. 
6. repeat till all points in the space are clustered. 

### Example 
Points (1,2) (1,3) (1,3) (2,3) (3,3)  (3,3) (4,5) (5,4) (5,4) (5,4) (5,4) (5,4) (5,4) (6, 2) (6, 5) represent the feature space apply mean shift clustering with bandwidth of 2 and flat kernel.


## Coordinates 

Homogenous coordinates and transformation matrices 4 x 4

* Translation 
* Rotation 
* Scaling

## Example 

points [2, 3, 0], [3, 7, 0] apply rotation 90 degree around y then translation in x direction with 3.
