#pragma once
#include <chrono>

class Timer
{
public:
	void Start();
	void Stop();
	//void reset();

	double elapsedMilliseconds();
	double elapsedSeconds();

private:
	std::chrono::time_point<std::chrono::system_clock> m_StartTime;
	std::chrono::time_point<std::chrono::system_clock> m_EndTime;

	bool m_bRunning = false;
};