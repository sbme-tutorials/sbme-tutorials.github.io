
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

def rgb2ycbcr(im):
    xform = np.array([[.299, .587, .114], [-.1687, -.3313, .5], [.5, -.4187, -.0813]])
    ycbcr = im.dot(xform.T)
    ycbcr[:,:,[1,2]] += 128
    return np.uint8(ycbcr)

def ycbcr2rgb(im):
    xform = np.array([[1, 0, 1.402], [1, -0.34414, -.71414], [1, 1.772, 0]])
    rgb = im.astype(np.float)
    rgb[:,:,[1,2]] -= 128
    rgb = rgb.dot(xform.T)
    np.putmask(rgb, rgb > 255, 255)
    np.putmask(rgb, rgb < 0, 0)
    return np.uint8(rgb)

def padded_slice(img, sl):
    output_shape = np.asarray(np.shape(img))
    output_shape[0] = sl[1] - sl[0]
    output_shape[1] = sl[3] - sl[2]
    src = [max(sl[0], 0),
           min(sl[1], img.shape[0]),
           max(sl[2], 0),
           min(sl[3], img.shape[1])]
    dst = [src[0] - sl[0], src[1] - sl[0],
           src[2] - sl[2], src[3] - sl[2]]
    output = np.zeros(output_shape, dtype=img.dtype)
    output[dst[0]:dst[1],dst[2]:dst[3]] = img[src[0]:src[1],src[2]:src[3]]
    return output