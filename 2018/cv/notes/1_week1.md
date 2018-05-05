---
layout: page
course: "sbe404b"
category: "notes"
year: "2018"
title:  "Week 1: Warming up with Python Basics"
by: "Asem"
---

* TOC
{:toc}

## Introduction: Python Basics

### Variables

Variables in python are very flexible, unlike C++:

* Interpreted language.
* No need to declare the variable type.
* The same variable can be assigned to different types.


```python
x = 5
y = 'Hello SBME'
z = 5
z = "Hello SBME"
```

### Lists

```python
# List construction
subjects = ['Technical Writing','Computer Vision']

# Append an element
subjects.append('Biochemistry')

# Append another list
subjects.extend(['Bioelectronics','Stochastic'])

print( subjects ) # ??
print( subjects[0] ) # ??
print( subjects[1] ) # ??
```


### Arithmetic Operations

```python

x = 19
y = 18 

z = x / y
z = x * y
z = x + y
z = x - y

```

### Logical Opertations

```python
x = 17 % 2 == 1

y = 9 / 3 < 1 

b = x or y ## True

b = x and y ## False
```

- `and` => `&&` in C++ 

- `or` => `||` in C++

### If, elif, else

```python 

x = 23 
y = 22 

if x < y:
  z = 13 # Local scope

elif x % 2 == 1 and x > y :
  h = 17 # Local scope

else:
  v = 80 # Local scope

print( z ) # Error: z is out of scope
print( h ) # Error: h is out of scope
```

### Loops

```python

for i in range(10):
  print( i )

i = 0
while i < 10 :
  print( i )
  i += 1
```



### Functions

```python
def mean( list ):
  sum = 0
  for element in list:
    sum += element
  return sum / len( sum )

m = mean([1,12,42,1,23,12])
print( m )
```

### Importing Libraries

```python 
import numpy as np
```

### Numpy


Reference: [{NumPy Reference}](https://docs.scipy.org/doc/numpy-1.13.0/reference/#numpy-reference)


```python
import numpy as np

a = np.array([12,23,44,21,23])

print( np.mean( a ))
print( np.std( a ))
```

###  Matplotlib

* `Matplotlib` is Matlab-like visualization library.


```python
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

image1 = mpimg.imread("images.jpg")
image2 = mpimg.imread("cameraman1.png")

print( image1.shape )
print( image2.shape )

plt.imshow(image2)
plt.show()

```


## Getting Started with Python: Installing Anaconda

### Anaconda


* Shipped +1000 Data Science Packages (DSP, Image Processing, Machine Learning, AI, Statistics).
* Shipped with Python IDE (Spyder).
* Shipped with Jupyter Notebook.

[Download Anaconda 3 (Python 3)](https://www.anaconda.com/download)


### References: Image Processing with Python

* [Scikit-image](http://scikit-image.org/docs/dev/user_guide)
* [Programming Computer Vision with Python, *Jan Erik Solem*](http://programmingcomputervision.com/downloads/ProgrammingComputerVision_CCdraft.pdf)
* [Image Processing in Numpy, *Computer Vision Laboratory, Link ̈oping Universit*](https://www.cvl.isy.liu.se/education/undergraduate/tsbb15/computer-exercises/lektion_python.pdf)


## Demo 

You can find the demo files on this repository at *github* [cv-week1-demo](https://github.com/sbme-tutorials/cv-week1-demo)

### Prerequisites

1. Anaconda3 installed.
2. git installed

### Downloading the Demo

Issue the following command:

```terminal
$ git clone https://github.com/sbme-tutorials/cv-week1-demo.git
$ cd cv-week1-demo
```

Expect soon migration to Python notebooks for more convenience.