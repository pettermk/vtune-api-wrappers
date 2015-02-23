#include "profiler.h"

using namespace VTune;
// Reference count of how many profilers are alive and profiling
RefcountInt Profiler::reference_count_ = 0;

Profiler::Profiler() 
{
	reference_count_++;
	StartProfiling();
}


Profiler::~Profiler()
{
	if (is_profiling_) {
		StopProfiling();
	}
}


void Profiler::StartProfiling()
{
	if (reference_count_ == 1) { //I'm the only one alive
		__itt_resume();
	}
	is_profiling_ = true;
}


void Profiler::StopProfiling()
{
	if (reference_count_ == 1) {
		reference_count_--;
		__itt_pause();
	}
	is_profiling_ = false;
}


void Profiler::Reset()
{
	StopProfiling();
}

Task::Task(const __itt_domain* domain, const char* task_name) : domain_(domain) {
	__itt_string_handle* task_name_handle =
		__itt_string_handle_create(task_name);
	__itt_task_begin(domain, __itt_null, __itt_null, task_name_handle);
}

Task::~Task() {
	__itt_task_end(domain_);
}
