#include "ChangeVolume.h"

ChangeVolume::ChangeVolume(){ SetVolume(1.0f); }
ChangeVolume::~ChangeVolume(){}

void ChangeVolume::SetVolume(float volume) {
    m_volume=volume;
}

void ChangeVolume::ClockProcess(float* LeftSample, float* RightSample) {
	*LeftSample = *LeftSample * m_volume;
	*RightSample = *RightSample * m_volume;
}