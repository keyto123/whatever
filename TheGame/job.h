#ifndef SOMEGAME_JOB_H_INCLUDED
#define SOMEGAME_JOB_H_INCLUDED

#include "stats.h"

const char* JOB_STATS_PATH = "job_stats.txt";
const char* JOB_NAMES_PATH = "job_names.txt";

class Job {
public:
	Job();
	Job(int job);
	int set_name(int job);
	int change_job(int job);	
private:
	char* name;
};

enum JOBS {
	NOVICE, KNIGHT, SAMURAI, NINJA, WHITE_MAGE, BLACK_MAGE, DEFENDER
};

#endif // SOMEGAME_JOB_H_INCLUDED
