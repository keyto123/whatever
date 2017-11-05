#include "player.hpp"
#include "utils.hpp"

Player::Player(const char* name) : Alive(name) {
	Player::stats.level = 1;
	Player::stats.str_growth = 100;
	Player::stats.vit_growth = 70;
	Player::stats.agi_growth = 50;
	Player::stats.dex_growth = 70;
	Player::stats.luk_growth = 20;

	Player::stats.strength = 5;
	Player::stats.vitality = 5;
	Player::stats.agility = 5;
	Player::stats.dexterity = 5;
	Player::stats.luck = 5;

	Player::stats.max_hp = initial_stats.max_hp + Player::stats.vitality * 2;
	Player::stats.hp = Player::stats.max_hp;

	Player::stats.attack = initial_stats.attack + Player::stats.strength;
	Player::stats.defense = initial_stats.defense + Player::stats.vitality / 2;
	Player::stats.evasion = initial_stats.evasion + Player::stats.agility;
	Player::stats.hit = initial_stats.hit + Player::stats.dexterity;
	Player::stats.critical_chance = Player::stats.luck;
}

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

	for(int i = 0, rnd; i < 5; i++) {
		rnd = get_random_value();
		Player::stat_up(i, rnd);
	}
	return 1;
}

int Player::stat_up(int stat, int rnd) {
	switch(stat) {
	case STR:
		if(Player::stats.strength == MAX_STATS || !(rnd < Player::stats.str_growth))
			break;
		Player::stats.strength++;
		Player::stats.attack++;
		break;
	case VIT:
		if(Player::stats.vitality == MAX_STATS || !(rnd < Player::stats.vit_growth))
			break;
		Player::stats.vitality++;
		Player::stats.max_hp += 2;
		Player::stats.hp += 2;
		if(Player::stats.vitality % 2 == 0) {
			Player::stats.defense++;
		}
		break;
	case AGI:
		if(Player::stats.agility == MAX_STATS || !(rnd < Player::stats.agi_growth))
			break;
		Player::stats.agility++;
		Player::stats.evasion++;
		break;
	case DEX:
		if(Player::stats.dexterity == MAX_STATS || !(rnd < Player::stats.dex_growth))
			break;
		Player::stats.dexterity++;
		Player::stats.hit++;
		break;
	case LUK:
		if(Player::stats.luck == MAX_STATS || !(rnd < Player::stats.luk_growth))
			break;
		Player::stats.luck++;
		Player::stats.critical_chance++;
		break;
	}
	return 1;
}
