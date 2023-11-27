#pragma once

#include <iostream>
#include <chrono>

template<typename T>
class TBasicStopwatch : T
{
    typedef typename T BaseTimer;
public:
    explicit TBasicStopwatch(bool bStart)
        : m_Activity(nullptr), m_Lap(0), m_Log(std::cout)
    {
        if (bStart)
        {
            Start();
        }
    }
    
    explicit TBasicStopwatch(const char* InActivity = "Stopwatch", bool bStart = true)
        : m_Activity(InActivity), m_Lap(0), m_Log(std::cout)
    {
        if (bStart)
        {
            Start();
        }
    }
    
    TBasicStopwatch(std::ostream& InLog, const char* InActivity = "Stopwatch", bool bStart = true)
        : m_Activity(InActivity), m_Lap(0), m_Log(InLog)
    {
        if (bStart)
        {
            Start();
        }
    }
    
    ~TBasicStopwatch()
    {
        if (IsStarted())
        {
            Stop();
        }
    }

    unsigned LapGet() const
    {
        return m_Lap;
    }

    bool IsStarted() const
    {
        return BaseTimer::IsStarted();
    }

    unsigned Show(const char* InEvent = "Show")
    {
        if (IsStarted())
        {
            m_Lap = BaseTimer::GetMs();
        }
        m_Log << m_Activity << ": " << InEvent << " " << m_Lap << "ms" << std::endl;
        return m_Lap;
    }

    unsigned Start(const char* InEvent = "Start")
    {
        if (IsStarted())
        {
            m_Lap = BaseTimer::GetMs();
            BaseTimer::Clear();
        }
        BaseTimer::Start();
        m_Log << m_Activity << ": " << InEvent << std::endl;
        return m_Lap;
    }

    unsigned Stop(const char* InEvent = "Stop")
    {
        if (IsStarted())
        {
            m_Lap = BaseTimer::GetMs();
            BaseTimer::Clear();
        }
        m_Log << m_Activity << ": " << InEvent << " " << m_Lap << "ms" << std::endl;
        return m_Lap;
    }

private:
    const char*   m_Activity;
    unsigned      m_Lap;
    std::ostream& m_Log;
};

class TimerBase
{
public:
    TimerBase() : m_Start(std::chrono::system_clock::time_point::min()) { }

    void Clear()
    {
        m_Start = std::chrono::system_clock::time_point::min();
    }

    bool IsStarted() const
    {
        return m_Start.time_since_epoch() != std::chrono::system_clock::duration(0);
    }

    void Start()
    {
        m_Start = std::chrono::system_clock::now();
    }

    unsigned long GetMs() const
    {
        if (IsStarted())
        {
            std::chrono::system_clock::duration Diff = std::chrono::system_clock::now() - m_Start;
            return (unsigned)(std::chrono::duration_cast<std::chrono::milliseconds>(Diff).count());
        }
        return 0;
    }

private:
    std::chrono::system_clock::time_point m_Start;
};

typedef TBasicStopwatch<TimerBase> Stopwatch;