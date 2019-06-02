# ----------------------------------------------------------------------
# CONVERTED TO PYTHON BY 
# ----------------------------------------------------------------------
# Matheus Bento - matheus.costa@inpe.br
# INPE - 2019
# ----------------------------------------------------------------------
# 
# ----------------------------------------------------------------------
# This function generates a multifractal time series using the p-model.
# Optionally you can also filter the result from the p-model in Fourier
# space to give it another fractal slope, e.g. to make it continuous and
# nonstationary. This is also called fractional integration. The p-model 
# itself can only produce stationary time series, i.e time series where 
# the variance is finite if you would extrapolate its power spectrum to 
# infinite large scales.
# 
# The parameter of the p-model is p. With p values close to 1 or 0 the time
# series is very peaked. With values close to 0.5 the p-model is much
# calmer; p=0.5 results in a constant unity vector.
# The parameter for the fractal integration is the slope of the power
# spectrum. Davis et al. calls slopes flatter than -1 stationary, and
# slopes between -1 and -3 nonstationary, with stationary increments. 
# These nonstationary cases are at least continuous, but not
# differentiable. Slopes steeper than -3 are nonstionary and
# differentiable.
# 
# Possible calls:
# [pModelTimeSeries] = pmodel
# [pModelTimeSeries] = pmodel(noValues)
# [pModelTimeSeries] = pmodel(noValues, p)
# [fractionalIntegratedTimeSeries] = pmodel(noValues, p, slope)
# [fractionalIntegratedTimeSeries, pModelTimeSeries] = pmodel(noValues, p, slope)
# If no number of values (noValues) is specified or it is empty, the
# default value of 256 is used.
# If no p is specified or it is empty, the default value of 0.375 is used.
# If no slope is specified, you will get a time series without fractional
# integration.
# If a slope is specified you will get the fractionally integrated time
# series, or if you use two output variables you will get both the p-model
# time series as well as its fractionally integrated version.

# This Matlab function is based on the article: Davis, A., A. Marshak, R.
# Cahalan, and W. Wiscombe, The landsat scale break in stratocumulus as a
# three-dimensional radiative transfer effect: implications for cloud
# remote sensing. Journal of the Atmospheric Sciences, Vol. 54, no. 2,
# 1997.
# First version by Victor Venema, Victor.Venema@uni-bonn.de, 25 January
# 2006.
# ----------------------------------------------------------------------

import numpy as np
import math


def next_step_1d(y, p):                     
    length = len(y)                         
    y2 = np.zeros(length * 2)
    sign = np.random.uniform(0, 1, length) - 0.5
    sign = sign / abs(sign)
    y2[::2] = y + sign * (1 - 2 * p) * y  
    y2[1::2] = y - sign * (1 - 2 * p) * y  
    return y2



def fractal_spectrum_1d(noValues, slope):
    ori_vector_size = noValues             
    ori_half_size = int(ori_vector_size / 2) 
    a = np.zeros(ori_vector_size)      
    for t2 in range(1, (ori_half_size+1)+1, 1):
        index = t2 - 1                  
        t4 = 2 + ori_vector_size - t2     
        if t4 > ori_vector_size :      
            t4 = t2                       
        with np.errstate(divide='ignore') :
            coeff = np.array([index])**slope  
        a[t2-1] = coeff                   
        a[t4-1] = coeff                  
    a[0] = 0    
    return a


def pmodel(**kwargs) :
    noValues = kwargs.get('noValues')
    p = kwargs.get('p')
    slope = kwargs.get('slope')

    if len(kwargs) < 1 or kwargs.get('noValues') == 'None' :
        noValues = 4096                 
    if len(kwargs) < 2 or kwargs.get('p') == 'None' :
        p = 0.375               
    if len(kwargs) < 3 :             
        slope = []             


    noOrders = int(math.ceil(math.log(noValues, 2)))

    y = [1]                           
    for n in range(1, noOrders + 1, 1): 
        y = next_step_1d(y, p)          

    if not slope == [] :      
        fourierCoeff = fractal_spectrum_1d(noValues, slope / 2.0)
        meanVal = np.mean(y)          
        stdy = np.std(y)              
        x = np.fft.ifft(y - meanVal)   
        phase = np.angle(x) 
        x = fourierCoeff * np.exp(1j * phase)
        x = np.real(np.fft.fft(x))     
        x = x * stdy / np.std(x)        
        x = x + meanVal       
    else:
        x = y                       

    x = x[0:noValues+1]
    return x


x = pmodel()
print(x)