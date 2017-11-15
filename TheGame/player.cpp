#include "player.h"
#include "utils.h"

Player::Player(const char* name, Stats stats, int job = 0) : Job(job), Alive(name, stats) {
	Player::job = job;
}

int Player::exp_up(int exp_gain) {
	if(total_exp == MAX_EXP) {
		return 0;
	}

	total_exp += exp_gain;

	if(stats.level == MAX_LEVEL) {
		return 0;
	}

	if(stats.experience < 100) {
		if(stats.experience + exp_gain >= 100) {
			stats.experience = 100;
			level_up();
		} else {
			stats.experience += exp_gain;
		}
	}
	return 1;
}

int Player::set_exp(int exp) {
	stats.experience = exp;
	return 1;
}

int Player::add_job_bonus(int job) {
	uint8_t* current_stat = &(stats.max_hp);
	for (int i = 0; i < 6; i++) {
		utils.get_file_line(JOB_STATS_PATH, i);

	}
}

int Player::change_job(int job) {
	Player::job.change_job(job);
	stats.level = 1;
	add_job_bonus(job);
}

int Player::level_up() {
	if(stats.level == MAX_LEVEL)
		return 0;
	stats.level++;
	set_exp(0);

	for(int i = 0, rnd; i < 6; i++) {
		rnd = utils.get_random_value();
		stat_up(i, rnd);
	}
	return 1;
}

int Player::stat_up(int stat, int rnd, int amount = 1) {
	if (stat == HP) {
		if (stats.max_hp != MAX_HP && rnd < stats.hp_growth) {
			stats.max_hp = stats.max_hp + amount > MAX_HP ? MAX_HP : stats.max_hp + amount;
			stats.hp += stats.max_hp;
		}
		return 1;
	}
	uint8_t* update_stat = &(stats.max_hp) + stat;
	uint8_t* growth_stat = &(stats.hp_growth) + stat;
	
	if (*update_stat != MAX_STATS && rnd < *growth_stat) {
		++*update_stat;
		return 1;
	}
	return 1;
}