#pragma once

#include "stats.h"
#include <string>

extern const char* JOB_STATS_PATH;
extern const char* JOB_NAMES_PATH;

class Job {
public:
	Job();
	Job(int job);
	int set_name(int job);
	int change_job(int job);	
private:
	std::string name;
};

enum JOBS {
	NOVICE, KNIGHT, SAMURAI, NINJA, WHITE_MAGE, BLACK_MAGE, DEFENDER
};
