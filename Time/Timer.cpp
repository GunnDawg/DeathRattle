#include "Timer.h"

void Timer::Start()
{
	m_StartTime = std::chrono::system_clock::now();
	m_bRunning = true;
}

void Timer::Stop()
{
	m_EndTime = std::chrono::system_clock::now();
	m_bRunning = false;
}

//void Timer::reset()
//{
//	m_StartTime = std::chrono::system_clock::now();
//	m_EndTime = m_StartTime;
//}

double Timer::elapsedMilliseconds()
{
	std::chrono::time_point<std::chrono::system_clock> endTime;

	if (m_bRunning)
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
