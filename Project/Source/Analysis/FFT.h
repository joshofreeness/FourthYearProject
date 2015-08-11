/*
  ==============================================================================

    FFT.h
    Created: 11 Aug 2015 1:12:12pm
    Author:  Joshua

  ==============================================================================
*/

#ifndef FFT_H_INCLUDED
#define FFT_H_INCLUDED

class FFT
{
public:
	FFT();
	~FFT();
	float* FFT::PerformFFT(float* data, int length);
private:
};




#endif  // FFT_H_INCLUDED
