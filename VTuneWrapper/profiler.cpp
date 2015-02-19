#include "profiler.h"

//#include "ittnotify.h"

// Reference count of how many profilers are alive and profiling
std::atomic<int> Profiler::reference_count_ = 0;

Profiler::Profiler() 
{
	StartProfiling();
	reference_count_++;
}


Profiler::~Profiler()
{
	StopProfiling();
}


void Profiler::StartProfiling()
{
	//__itt_resume();
	is_profiling_ = true;
}


void Profiler::StopProfiling()
{
	//__itt_stop();
	is_profiling_ = false;
	reference_count_--;
}


void Profiler::Reset()
{
	StopProfiling();
}
