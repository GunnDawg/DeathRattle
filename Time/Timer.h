#pragma once
#include <chrono>

class Timer
{
public:
	void Start();
	void Stop();
	//void reset();

	double ElapsedMilliseconds();
	double ElapsedSeconds();

private:
	std::chrono::time_point<std::chrono::system_clock> m_StartTime;
	std::chrono::time_point<std::chrono::system_clock> m_EndTime;

	bool mRunning = false;
};