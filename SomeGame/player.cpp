#include "player.hpp"
#include "utils.hpp"

Player::Player(const char* name) : Alive(name) {}

Player::Player(const char* name, Stats stats) : Alive(name, stats) {}

int Player::exp_up(int exp_gain) {
	if(Player::total_exp == MAX_EXP) {
		return 0;
	}

	Player::total_exp += exp_gain;

	if(Player::stats.level == MAX_LEVEL) {
		return 0;
	}

	if(Player::level_exp < 100) {
		if(Player::level_exp + exp_gain >= 100) {
			Player::level_exp = 100;
			Player::level_up();
		} else {
			Player::level_exp += exp_gain;
		}
	}
	return 1;
}

int Player::set_exp(int exp) {
	Player::level_exp = exp;
	return 1;
}

int Player::level_up() {
	if(Player::stats.level == MAX_LEVEL)
		return 0;
	Player::stats.level++;
	set_exp(0);

	for(int i = 0, rnd; i < 6; i++) {
		rnd = get_random_value();
		Player::stat_up(i, rnd);
	}
	return 1;
}

int Player::stat_up(int stat, int rnd) {
	switch(stat) {
	case HP:
		if(stats.max_hp == MAX_HP || !(rnd < stats.hp_growth))
			break;

		stats.max_hp++;
		stats.hp++;
		break;
	case ATK:
		if(stats.attack == MAX_STATS || !(rnd < stats.atk_growth))
			break;

		stats.attack++;
		break;

	case DEF:
		if(stats.defense == MAX_STATS || !(rnd < stats.def_growth))
			break;

		stats.defense++;
		break;

	case EVD:
		if(stats.evade == MAX_STATS || !(rnd < stats.evd_growth))
			break;

		stats.evade++;
		break;

	case HIT:
		if(stats.hit == MAX_STATS || !(rnd < stats.hit_growth))
			break;

		stats.hit++;
		break;

	case CRIT:
		if(stats.critical == MAX_STATS || !(rnd < stats.crit_growth))
			break;

		stats.critical++;
		break;
	}
	return 1;
}

