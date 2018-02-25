---
layout: page
course: "sbe404"
category: "notes"
year: "2018"
title:  "Week 3: Images in Frequency Domian"
by: "Eslam"
---

* TOC
{:toc}

## Discrete Fourier Transform (DFT)
Fourier transform is a decompisition of a signal into some basis functions. Here basis functions are wiegted sum of sin and cos functions 
Geiven a discrete image I(x,y) the fourier transform of it is  :
``` 
I(u,v) = sum_{x= 0}^{N_{clos} - 1 } sum_{y = 0}^{N_{rows} - 1}  I(x,y) .e^{-i2pi(\frac{xu}{N_cols)}+\frac{yv}{N_rows}}
```

## Properties of DFT 

 * FT is a complex representation of the image. So it includes a magnitude and a phase 
  Magnitude component is the desired one in visualization. It represents the weight of each frequency component and give an intuitive impression about frequcy spectrum of the image. Due to large variations in magnitudes (Center of the image has a high value compared with other values) we display it in a log scale to compress dynamic range  see link https://homepages.inf.ed.ac.uk/rbf/HIPR2/pixlog.htm
 ```
 log 10 (1 + ||I(u, v )|| 2 )
 ```
 Phase is very important for image recovery but has no significance in visulaization 
 * In Fourier domain central regions represent the low frequency components and prepheral regions represent the high frequency components and the center of the image represents the DC value with zero frequency which is the average intensity of the image. Note (image profile within a scan line gives you an impression about the frequncy in that direction)
 * Direction of change in intensity has the same direcion in frequency domain
 * No one to one corresponding where each point in frequency domain is calculated from the whole spatial image
 ```
 I(u,v) = T(I)(x,y) not T(I(x,y)) 
 ```
 * Fourier transfor of the image is symmetric which mean that we can recover the image if we have only the half of fourier domain. This is a very important property in fourier transfrom and used in MRI imaging see partial fourier imaging http://mriquestions.com/partial-fourier.html 
 
 Question: Where redundancy comes from ?? 
 Answer : Each point in fourier domain is a complex with two informations magnitude and phase or real part and imaginary part. So half of fourier image actually hold up the whole information of the spatial domain image.
 * DFT is periodic (remember discretization implies periodicity) and aliasing in frequecny domain leads to overlapping in image domain. 
 
## Inverse Fourier Transform
 ``` 
I(u,v) = 1 / N *M sum_{x= 0}^{N_{clos} - 1 } sum_{y = 0}^{N_{rows} - 1}  I(x,y) .e^{-i2pi(\frac{xu}{N_cols)}+\frac{yv}{N_rows}}
```




