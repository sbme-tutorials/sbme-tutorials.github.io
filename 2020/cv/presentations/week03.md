---
layout: presentation
style: laminal
highlighter: github
course: "sbe404"
category: "presentation"
year: "2020"
title: "Section 3: Histogram Equalization, Filtration in Frequency Domain, and Hough Transform"
by: "Asem Alaa"
author: "Asem Alaa"
---


<textarea id="source">

---
class: left, top
## Histogram Processing: Equalization

* Intensity image (3 bits): [0-7]
* Image size = 64x64 = 4096

### Step 1: Compute the discrete PDF (histogram)

--
.center[<img style="width:40%" src="../images/histexample.png"> <img style="width:40%" src="../images/pdfexample.png">]

---
class: left, top

## Histogram Processing: Equalization (cont'd)

### Step 2: Compute the discrete CDF (cumulative histogram)

| `i` | accumulative | accumulative x 7 | rounded |
|--|--|--|--|
| `s0` | 0.19 | 1.33 | 1 |
| `s1` | 0.44 | 3.08 | 3 |
| `s2` | 0.65 | 4.55 | 5 |
| `s3` | 0.81 | 5.67 | 6 |
| `s4` | 0.89 | 6.23 | 6 |
| `s5` | 0.95 | 6.65 | 7 |
| `s6` | 0.98 | 6.86 | 7 |
| `s7` | 1.00 | 7.00 | 7 |

---
class: left, top
## Histogram Processing: Equalization (cont'd)

### Step 2: Compute the discrete CDF (cumulative histogram)

.center[<img style="width:40%" src="../images/pdfexample.png"> ===> <img style="width:40%" src="../images/cdfexample.png">]


---
class: left, top
## Histogram Processing: Equalization (cont'd)

### Step 3: Use the previous table to map the pixels values

--
.center[<img style="width:40%" src="../images/equalizedexample.png"> ]


---
class: left, top
## Histogram Processing: Matching

* Intensity image (3 bits): [0-7]
* Image size = 64x64 = 4096
--
* Obtain an image with an **arbitrary distribution** instead of a uniform distribution
--
* Target distribution

.center[<img style="width:40%" src="../images/targetpdf.png"> ]

---
class: left, top
## Histogram Processing: Matching (cont'd)

### Step 1: Obtain the scaled histogram equalized values (previous example)

* `s0` = 1   `s1` = 3   `s2` = 5   `s3` = 6
* `s4` = 7   `s5` = 7   `s6` = 7   `s7` = 7

---
class: left, top
## Histogram Processing: Matching (cont'd)

### Step 2: compute the discrete CDF of the target distribution

| `i` |  accumulative x 7 | rounded |
|--|--|--|
| `z0` | 0.00 | 0 |
| `z1` | 0.00 | 0 |
| `z2` | 0.00 | 0 |
| `z3` | 1.05 | 1 |
| `z4` | 2.45 | 2 |
| `z5` | 4.55 | 5 |
| `z6` | 5.95 | 6 |
| `z7` | 7.00 | 7 |


---
class: left, top
## Histogram Processing: Matching

### Step 2: compute the discrete CDF of the target distribution

.center[<img style="width:40%" src="../images/targetpdf.png"> ===> <img style="width:40%" src="../images/targetcdf.png">]

---
class: left, top
## Histogram Processing: Matching

### Step 3: use the previous table to map the pixels values

--
.center[<img style="width:40%" src="../images/matchedexample.png"> ]


---
class: center, middle

## Histogram Processing: Demo

<img src="../images/jnb.png">

[{`histograms.ipnyb`}](https://github.com/sbme-tutorials/sbme-tutorials.github.io/blob/master/2020/cv/notebooks/histograms.ipynb)


---
class: center, middle

## Filtration in Frequency Domain: Demo

<img src="../images/jnb.png">

[{`frequency_filter.ipnyb`}](https://github.com/sbme-tutorials/sbme-tutorials.github.io/blob/master/2020/cv/notebooks/frequency_filter.ipynb)

---
class: left, top

## Hough Transform

Proposed by Paul V.C Hough 1962

* Got USA [Patent](https://patents.google.com/patent/US3069654) 
* Originally for line detection 
* Extended to detect other shapes like, circle, ellipse etc.

---
## Hough Transform: Line Detection (Cartesian Coordinates)

In image space line is defined by the slope $m$ and the y-intercept $b$ :


$$y = mx + b$$


--
.center[<img style="width:100%" class="center" src="../images/hough-mb_parameter_space.png">]

---
## Hough Transform: Line Detection (Cartesian Coordinates)

--
* Each point proposes list of candidate lines
--
* Overall, how to find the true lines?

--
.center[<img style="width:80%" class="center" src="../images/describing and elephant5.JPG">]

---
## Hough Transform: Line Detection (Cartesian Coordinates)

In image space line is defined by the slope $m$ and the y-intercept $b$ :


$$y = mx + b$$



.center[<img style="width:100%" class="center" src="../images/hough-mb_parameter_space.png">]

---
class: left, top

## Hough Transform: Line Detection (Polar Coordinates)

--
* Some lines cannot be be defined in Cartesian
--
* So we have to move to polar coordinates. 
--
* In polar coordinates line is define by $\rho$ and $\theta$ 
--
* $\rho$ is the norm distance of the line from origin. 
* $\theta$ is the angle between the norm and the horizontal $x$ axis. 
* The equation of line in terms of $\rho$ and $\theta$ now is 

$$y = \frac{-cos(\theta)}{sin(\theta)} x + \frac{\rho}{sin(\theta)}$$

and 

$$\rho = x cos(\theta)  + y sin(\theta)$$

---
class: left, top

## Hough Transform: Line Detection (Polar Coordinates)

.center[<img style="width:60%" class="center" src="../notebooks/media/hough_deriving-rho.png">]


---
class: left, top

## Hough Transform: Line Detection (Polar Coordinates)

.center[<img style="width:30%" class="center" src="../notebooks/media/hough_deriving-rho.png">]

The Range of values of $\rho$ and $\theta$ 

--
* $\theta$: in polar coordinate takes value in range of -90 to 90 
* The maximum norm distance is given by diagonal distance which is $\rho$max $= \sqrt{x^2 + y^2}$
* So $\rho$ has values in range from $-\rho$max to $\rho$max


---
## Hough Transform: Line Detection (Polar Coordinates)

### Algorithm

Basic Algorithm steps for Hough transform is : 

```
# Extract edges of the image (For example, using Canny)

1. initialize parameter space rs, thetas
2. Create accumulator array and initialize to zero
3. for each edge pixel     
4.     for each theta
5.         calculate r = x cos(theta) + y sin(theta)
6.         Increment accumulator at r, theta
7. Find Maximum values in accumulator (lines)

Extract related r, theta
```


---
## Hough Transform: Line Detection (Polar Coordinates)

### Basic Implementation

At first import used libraries


```python
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
```

---
## Hough Transform: Line Detection (Polar Coordinates)

### Basic Implementation

```python
def hough_line(image):
    Ny = image.shape[0]
    Nx = image.shape[1] 
    Maxdist = int(np.round(np.sqrt(Nx**2 + Ny ** 2)))
    thetas = np.deg2rad(np.arange(-90, 90))
    rs = np.linspace(-Maxdist, Maxdist, 2*Maxdist)
    accumulator = np.zeros((2 * Maxdist, len(thetas)))

    for y in range(Ny):
        for x in range(Nx):
            if image[y,x] > 0:
                 for k in range(len(thetas)):
                    r = x*np.cos(thetas[k]) + y * np.sin(thetas[k])
                    accumulator[int(r) + Maxdist,k] += 1
    return accumulator, thetas, rs
```

---
## Useful links


* [{Understanding Hough transform in python}](https://alyssaq.github.io/2014/understanding-hough-transform/)
* [{OpenCV Hough Line Transform}](http://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_imgproc/py_houghlines/py_houghlines.html)
* [{Scikit-image Hough Line}](http://scikit-image.org/docs/dev/auto_examples/edges/plot_line_hough_transform.html)
* [{OpenCV Hough Circle}](https://docs.opencv.org/3.1.0/da/d53/tutorial_py_houghcircles.html)
* [{Survey of Hough transform}](https://arxiv.org/pdf/1502.02160.pdf)


---
## Hough Transform: Line Detection (Polar Coordinates)

<img src="../images/jnb.png">

[{`hough_transform.ipnyb`}](https://github.com/sbme-tutorials/sbme-tutorials.github.io/blob/master/2020/cv/notebooks/hough_transform.ipynb)





</textarea>
