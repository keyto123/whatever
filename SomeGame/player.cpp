#include "player.h"
#include <random>

const Stats initial_stats = {
	1, 			// Level
	1,1,1,1,1, 	// Stats
	1,1,1,1,1, 	// Stats growth
	20,20, 		// Max hp, current hp
    5, 			// Atk
    5, 			// Defense
    5, 			// Evasion
    5, 			// Hit
    0 			// Critical
};

Player::Player(const char* name) {
	Player::name = (char*)name;

	Player::stats.level = 1;
	Player::stats.str_growth = 60;
	Player::stats.vit_growth = 60;
	Player::stats.agi_growth = 60;
	Player::stats.dex_growth = 60;
	Player::stats.luk_growth = 60;

	Player::stats.strength = 5;
	Player::stats.vitality = 5;
	Player::stats.agility = 5;
	Player::stats.dexterity = 5;
	Player::stats.luck = 5;

	Player::stats.max_hp = initial_stats.max_hp + Player::stats.vitality;
	Player::stats.hp = Player::stats.max_hp;

	Player::stats.attack = initial_stats.attack + Player::stats.strength;
	Player::stats.defense = initial_stats.defense + Player::stats.vitality / 2;
	Player::stats.evasion = initial_stats.evasion + Player::stats.agility;
	Player::stats.hit = initial_stats.hit + Player::stats.dexterity;
	Player::stats.critical_chance = Player::stats.luck;
}

char* Player::get_name() {
	return Player::name;
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
	Player::stats.level++;
	set_exp(0);

	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);
	for(int i = 0; i < 2; i++) {
		Player::stat_up(i, dis(gen));
	}
	return 1;
}

int Player::stat_up(int stat, int rnd) {
	switch(stat) {
	case STR:
		Player::stats.strength += !(rnd > Player::stats.str_growth);
		Player::stats.attack = initial_stats.attack + Player::stats.strength;
		break;
	case VIT:
		Player::stats.vitality += !(rnd > Player::stats.vit_growth);
		Player::stats.max_hp = initial_stats.max_hp + Player::stats.vitality * 2;
		Player::stats.defense = initial_stats.defense + Player::stats.vitality / 2;
		break;
	case AGI:
		Player::stats.agility += !(rnd > Player::stats.agi_growth);
		Player::stats.evasion = initial_stats.evasion + Player::stats.agility;
	case DEX:
		Player::stats.dexterity += !(rnd > Player::stats.dex_growth);
		Player::stats.hit = initial_stats.hit + Player::stats.dexterity;
	case LUK:
		Player::stats.luck += !(rnd > Player::stats.luk_growth);
		Player::stats.critical_chance = Player::stats.luck;
		break;
	}
	return 1;
}
