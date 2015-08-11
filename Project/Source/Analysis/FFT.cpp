/*
  ==============================================================================

    FFT.cpp
    Created: 11 Aug 2015 1:12:12pm
    Author:  Joshua

  ==============================================================================
*/

#include "FFT.h"

Analysis::FFT::FFT(){};
Analysis::FFT::~FFT(){};


/*
==============================================================================

Cooley-Tukey FFT algorithm

https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm

Pseudo code

X0,...,N-1 <- ditfft2(x, N, s):             DFT of (x0, xs, x2s, ..., x(N-1)s):
    if N = 1 then
        X0 <- x0                                      trivial size-1 DFT base case
    else
        X0,...,N/2-1 <- ditfft2(x, N/2, 2s)             DFT of (x0, x2s, x4s, ...)
        XN/2,...,N-1 <- ditfft2(x+s, N/2, 2s)           DFT of (xs, xs+2s, xs+4s, ...)
        for k = 0 to N/2-1                           combine DFTs of two halves into full DFT:
            t <- Xk
            Xk <- t + exp(-2(pi)i k/N) Xk+N/2
            Xk+N/2 <- t - exp(-2(pi)i k/N) Xk+N/2
        endfor
    endif

	Here, ditfft2(x,N,1), computes X=DFT(x) out-of-place by a radix-2 DIT FFT, where N is an integer power of 2 and s=1 is the stride of the input x array. x+s denotes the array starting with xs.

==============================================================================
*/

float* Analysis::FFT::PerformFFT(float* data, int length)
{
	
	float temp = 2.0f;
	return &temp;
}