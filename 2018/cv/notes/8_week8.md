---
layout: page
course: "sbe404"
category: "notes"
year: "2018"
title:  "Week 7: Segmentation (Clustering Segmentation)"
by: "Eslam"
---

* TOC
{:toc}

## Clustering Segmentation 

Clustering is the process of grouping similar data points together and marking them as a same cluster or group. It is used in many fields including machine learning, data analysis and data mining. We can consider segmentation as a clustering problem. We need to cluster image into different object, each object pixels has common features for example same color or same intensity. 

[Put illustration image here]

Talking about similarity criteria takes us to what so called feature. A feature is a value that measures or identify characteristic of subject, it must discriminate between different subjects. One of important rules in machine learning is that Good feature with simple classifier is more accurate that bad feature with robust classifier. 

Feature space is an alternative space of ordinary data space. Its coordinates are feature values and each data point is represented by its value of different features. For example, color components R, G, and B are the coordinates of our feature space. Each pixel in the image will be represented as a 3D vector of its R, G, and B values. 
  
## K means Clustering

K means clustering assumes random initial cluster centers in feature space. cluster data to these centers according to the distance between these data points and our centers. Now we can update the value of the center for each cluster, it is the mean of its points. Process is repeated and data are re-clustered for each iteration, new mean is calculated till convergence. Finally we have our centers and related data points. The process is shown in the following figure. 

![](../images/K-means_convergence.gif)

So basic Algorithm steps for k means segmentation are

```python
Construct feature space from your image (number of data point = number of pixels)
Set number of required clusters k 
Set Max number of iterations for clustering
Get random k points in your feature space (initial centers)
for i in range(max number of iterations)
    #Cluster remaining data points to centers according to distance
    for each data point:
        for each cluster:
            distances =  distance between it cluster center
        its cluster = min(distances)
    #Calculate the new centers 
    for each cluster:
        newCenter = mean(RelatedPoints)
    #Check distance between new and old centers.
    distances = new - old 
```

## Mean shift Clustering

Mean shift clustering is non-parametric technique for clustering, it doesn't require specifying number of clusters. Also it is robust for outliers as clusters aren't in spherical shape it takes a random shape according to clustering procedure. It is computationally complex so it will fail for higher dimensions 
