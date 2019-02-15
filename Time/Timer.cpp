#include "Timer.h"

void Timer::Start()
{
	m_StartTime = std::chrono::system_clock::now();
	mRunning = true;
}

void Timer::Stop()
{
	m_EndTime = std::chrono::system_clock::now();
	mRunning = false;
}

//void Timer::reset()
//{
//	m_StartTime = std::chrono::system_clock::now();
//	m_EndTime = m_StartTime;
//}

double Timer::elapsedMilliseconds()
{
	std::chrono::time_point<std::chrono::system_clock> endTime;

	if (mRunning)
	{
		endTime = std::chrono::system_clock::now();
	}
	else
	{
		endTime = m_EndTime;
	}

	return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
}

double Timer::elapsedSeconds()
{
	return elapsedMilliseconds() / 1000.0;
}
