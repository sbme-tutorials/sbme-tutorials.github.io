
# import the necessary packages
from os import listdir
from os.path import isfile , join
import numpy as np
from scipy import signal


def rgb2gray(rgb_image):
    return np.dot(rgb_image[...,:3], [0.299, 0.587, 0.114])

def binarize( gray_image , threshold ):
    threshold = np.max( gray_image ) * threshold
    return 1 * ( gray_image > threshold )

def gaussian_kernel1d(kernlen=7, std=1.5):
    """Returns a 1D Gaussian window."""
    kernel1d = signal.gaussian(kernlen, std=std)
    kernel1d = kernel1d.reshape(kernlen, 1)
    return kernel1d / kernel1d.sum()

def gaussian_kernel2d(kernlen=7, std=1.5):
    """Returns a 2D Gaussian kernel array."""
    gkern1d = gaussian_kernel1d(kernlen,std)
    gkern2d = np.outer(gkern1d, gkern1d)
    return gkern2d

def get_img_stats(img):
    _,mnmx, mn, var,_,_ = stats.describe(img.ravel())
    return '%.4f' % mnmx[0],  '%.4f' % mnmx[1], '%.4f' % mn,  '%.4f' % var

from tabulate import tabulate

def print_imgs_stats( names_imgs ):
    rows = []
    headers = ["Name", "Shape", "min", "max", "mean", "variance"]
    for name,img in names_imgs:
        rows.append([name, img.shape, *get_img_stats(img)])
    
    return tabulate(rows, headers, tablefmt="fancy_grid")

def print_img_stats(name,img):
    mn,mx, mean, var = get_img_stats(img)
    print("Img ({}): minmax =({:2f},{:2f}), mean={:2f}, var={:2f}".format(name,mn,mx,mean,var))
