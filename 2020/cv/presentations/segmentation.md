---
layout: presentation
style: laminal
highlighter: ir-black
code: "SBE201"
course: "SBE404 Computer Vision"
category: "presentation"
semester: "Spring"
year: "2020"
title: "Segmentation"
by: "Asem Alaa"
author: "Asem Alaa"
---

## Otsu Thresholding

---
## Otsu Thresholding (segmentation)

.center[![](/2019/cv/images/Otsu's_Method_Visualization.gif)]


---
## Otsu Thresholding (segmentation)
### Minimization of $\sigma_w^2(u)$

$$ \sigma_w^2(u) =  n_1 \sigma_1^2(u)  + n_2 \sigma_2^2(u)  $$

* .red[Computation of $\sigma_w^2(u)$ at each $u$ is very costly]
* can we do better?

---
## Otsu Thresholding (segmentation)
### Maxmimiztion of $\sigma_b^2(u)$

$$ 
\sigma^2 = \sigma_b^2(u) + \sigma_w^2(u) \\\ 
\sigma_w^2(u) = \sigma^2 - \sigma_b^2(u)
$$

$\therefore$ minimization of $\sigma_w^2(u)$ = maximization of $\sigma_b^2(u)$


---
## Otsu Thresholding (segmentation)
### Maxmimiztion of $\sigma_b^2(u)$

$$ 
\sigma^2 = \sigma_b^2(u) + \sigma_w^2(u) \\\ 
\sigma_w^2(u) = \sigma^2 - \sigma_b^2(u)
$$

$\therefore$ minimization of $\sigma_w^2(u)$ = maximization of $\sigma_b^2(u)$


---
## Otsu Thresholding (segmentation)
### Maxmimiztion of $\sigma_b^2(u)$


$$ \sigma_b^2(u) =  n_1 n_2 ( \mu_1(u) - \mu_2(u) )^2  $$

.center[![](/2019/cv/images/Otsu's_Method_Visualization.gif)]


---
## Otsu Thresholding (segmentation)
### Python implementation 


```python
def otsu_threshold(im):
    # Histogram
    pixel_counts = [np.sum(im == i) for i in range(256)]

    s_max = (0,-np.inf)
    
    for threshold in range(256):
        # update
        n1 = sum(pixel_counts[:threshold])
        n2 = sum(pixel_counts[threshold:])

        mu_0 = sum([i * pixel_counts[i] for i in range(0,threshold)]) / n1 if n1 > 0 else 0       
        mu_1 = sum([i * pixel_counts[i] for i in range(threshold, 256)]) / n2 if n2 > 0 else 0

        # calculate 
        s = n1 * n2 * (mu_0 - mu_1) ** 2

        if s > s_max[1]:
            s_max = (threshold, s)
            
    return s_max[0]
```

---
## Region Growing


---
## Split and Merge


---
## K-means Clustering


---
## Agglomerative Clustering


---
## Mean-shift Clustering


---
## DBScan Clustering


---
## Spectral Clustering