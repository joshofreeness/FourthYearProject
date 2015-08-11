/*
  ==============================================================================

    FFT.h
    Created: 11 Aug 2015 1:12:12pm
    Author:  Joshua

  ==============================================================================
*/

#ifndef FFT_H_INCLUDED
#define FFT_H_INCLUDED
#include <vector>

namespace Analysis{
	class FFT
	{
	public:
		FFT();
		~FFT();
		static float* PerformFFT(std::vector<float> data, int length);
	private:
		static void ditfft2(std::vector<float> freqXModify, std::vector<float> xArray, int xStart, int N, int s);
	};

}


#endif  // FFT_H_INCLUDED
