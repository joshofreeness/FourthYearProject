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

namespace Input{
	class FFT
	{
	public:
		double pi;
		unsigned long int fundamental_frequency;
		float *vector;
		FFT(void);
		~FFT(void);
		// FFT 1D
		void perform_FFT(float data[], unsigned long number_of_samples, unsigned int sample_rate, int sign);
	};
}
#endif  // FFT_H_INCLUDED