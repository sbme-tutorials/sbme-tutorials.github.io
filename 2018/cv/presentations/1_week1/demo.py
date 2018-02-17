import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as pyplt
from scipy import misc

def visualize( image  ):
    pyplt.figure()
#    pyplt.gray( )
    pyplt.imshow( image )
#
#    pyplt.figure()
#    pyplt.hist( image )


image1 = misc.imread( "cameraman1.png" )
image2 = misc.imread("Linda.jpg")
images = [ image1 , image2 ]

[ visualize( image ) for image in images ]

pyplt.show()

