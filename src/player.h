#pragma once

#include "alive.h"
#include "job.h"
#include "utils.h"

const int MAX_EXP = 99999;

class Player: public Alive, Job {
public:
	Player(const char* name, Stats stats, int job);
	int exp_up(int exp_gain);
	int set_exp(int exp);
	int add_job_bonus(int job);
	int change_job(int job);
	int level_up();
	int stat_up(int stat, int rnd, int amount = 1);
	Stats stats;
private:
	int total_exp;
	Utils utils;
	Job job;
};
