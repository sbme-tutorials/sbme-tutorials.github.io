---
layout: page
course: "sbe404b"
category: "notes"
year: "2018"
title:  "Week 9: Exercises"
by: "Eslam"
---
* TOC
{:toc}

# Image Segmentation
For Image segmentation we studied three methods 

* Histogram based segmentation (Image thresholding and binarization) 

  Maximize Between class variance or minimize within class variance.

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

Homogenous coordinates in 2D  $$\begin{bmatrix} x \\\ y  \\\ w \end{bmatrix}$$ and transformation matrices. w = 0 for point at infinity and w = 1 for object coordinates (Computer Graphics)

* Translation  

$$
\begin{bmatrix}
1 & 0 & t1 \\\
0 & 1 & t2 \\\ 
0 & 0 & 1
\end{bmatrix}
$$

* Rotation

$$
\begin{bmatrix}
cos(\theta) & -sin(\theta) & 0\\
sin(\theta) & cos(\theta) & 0\\
0 & 0 & 1
\end{bmatrix}
$$

* Both 


$$
T = \begin{bmatrix}
cos(\theta) & -sin(\theta) & t1\\
sin(\theta) & cos(\theta) & t2\\
0 & 0 & 1
\end{bmatrix}
$$

$$
\begin{bmatrix}
x_1 \\ y_1 \\ 1 
\end{bmatrix} = T \times
\begin{bmatrix} 
x\\ y \\ 1
\end{bmatrix} 
$$

### Example 

points [2, 3], [3, 7] apply rotation 90 degree and translation in x direction with 3.

## SIFT 

Find 8 elements feature vector for following 4x4 block

$$
\begin{bmatrix}
96 & 98&  127&  189 \\\ 
72 & 68 & 94&  163 \\\
69 & 69&  86&  146 \\\
62 & 70 & 79 & 119
\end{bmatrix} 
$$

## Quiz 3 

### Question 1

For The following 3 bit image 

$$
\begin{bmatrix}
0 & 1&  1&  2 \\\ 
2 & 5 & 5&  4 \\\
6 & 7&  6&  2 \\\
4 & 6 & 5 & 0
\end{bmatrix} 
$$

Between class variance for all possible thresholds is found as follow : 


t | 1 | 2 | 3 |  4 |  5 |  6 |  
---|---|---|---|---|----|----|
$$\sigma_b^2$$ | 1.5 | 2.5| 7 | 3.5 |2 | 1|

1. What is the optimal threshold ?

2. Binarize the image based on this threshold

### Question 2 True or false and correct 

1. Mean shift clustering algorithm can handle clusters of irregular shapes. 
2.  In Otsu binarization, minimizing the within-class variance is the same as maximizing the
between-class variance 
3. Harris operator is invariant to rotations, translations, and scale.
4. Each point on a line maps to exponential curves in polar Hough Transform.
5. Feature points should be geometric and photometric variant.
6. For a corner point: both Eigenvalues of the H matrix have large values
7. H matrix is computed using the gradients of the image.

