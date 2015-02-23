#pragma once

#include "ittnotify.h"

#if (_MSC_VER > 1700 || LINUX)
#include <atomic>
typedef RefcountInt std::atomic<int>;
#else
typedef int RefcountInt;
#endif

namespace VTune {

class Profiler
{
public:
	Profiler();
	~Profiler();
	static RefcountInt reference_count_;
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
	Task(const __itt_domain* domain, const char* task_name);
	~Task();
private:
	const __itt_domain* domain_;
};

}
