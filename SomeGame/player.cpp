#include "player.h"
#include "utils.h"

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

