#pragma once

#include <atomic>

class Profiler
{
public:
	Profiler();
	~Profiler();
	static std::atomic<int> reference_count_;
public:
	void Reset();
private:
	void StartProfiling();
	void StopProfiling();
	bool is_profiling_;
};

class Task
{
public:
	Task(const char* )
};

