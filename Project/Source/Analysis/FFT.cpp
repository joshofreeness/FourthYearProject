/*
  ==============================================================================

    FFT.cpp
    Created: 11 Aug 2015 1:12:12pm
    Author:  Joshua

  ==============================================================================
*/

#include "FFT.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>


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

float* Analysis::FFT::PerformFFT(std::vector<float> data, int length)
{
	std::vector<float>* freqX = new std::vector<float>(length);
	ditfft2(*freqX, data, 0, length, 1);

	float temp = 2.0f;
	return &temp;
}

//I am going to use vector for now for ease of coding, might be faster to change to pointers later
void Analysis::FFT::ditfft2(std::vector<float> freqXModify, std::vector<float> xArray, int xStart, int n, int s)
{
	if (n = 1)
	{
		freqXModify[xStart] = xArray[xStart];
	} else
	{
		ditfft2(freqXModify, xArray, xStart, n/2, 2*s);
		ditfft2(freqXModify, xArray, xStart+s, n / 2, 2 * s);
		

		for (int k = 0; k < (n / 2 - 1); k++)
		{
			std::complex<float>* twiddleFactor = new std::complex<float>();
			twiddleFactor->imag(-2 * M_PI);
			twiddleFactor->real(k/n);

			float t = freqXModify[k];
			//freqXModify[k] = t + exp(*twiddleFactor) * freqXModify[k + n / 2];
			//freqXModify[k + n / 2] = t - exp(*twiddleFactor) * freqXModify[k + n / 2];
		}
	}
}