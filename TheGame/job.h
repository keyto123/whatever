#ifndef SOMEGAME_JOB_H_INCLUDED
#define SOMEGAME_JOB_H_INCLUDED

#include "stats.h"

class Job {
public:
	int change_job(int job);
	Stats stats;

private:
	char* name;
};

#endif // SOMEGAME_JOB_H_INCLUDED
