class ChangeVolume {
public:
	ChangeVolume();
	~ChangeVolume();

    //Parameters
    void SetVolume(float volume);
    float GetVolume(void){ return m_volume; };

    //Use
    void ClockProcess(float* LeftSample, float* RightSample); 

private:
    float m_volume;
};