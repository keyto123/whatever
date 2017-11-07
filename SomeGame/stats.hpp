#ifndef SOMEGAME_STATS_H_INCLUDED
#define SOMEGAME_STATS_H_INCLUDED

#include <cstdint>

const int MAX_STATS = 40;
const int MAX_LEVEL = 40;
const int MAX_HP = 60;

typedef struct {
	std::uint8_t level;

	std::uint8_t hp;
	std::uint8_t max_hp;

	std::uint8_t attack;
	std::uint8_t defense;
	std::uint8_t evade;
	std::uint8_t hit;
	std::uint8_t critical;

	std::uint8_t hp_growth;
	std::uint8_t atk_growth;
	std::uint8_t def_growth;
	std::uint8_t evd_growth;
	std::uint8_t hit_growth;
	std::uint8_t crit_growth;

} Stats;

enum STATS {
	HP, ATK, DEF, EVD, HIT, CRIT
};

const Stats default_stats = {
	1, 			// Level
	20,20,		// Current HP, Max hp
	1,1,1,1,1,	// Stats
	1,1,1,1,1,1 // Stats growth
};

#endif // SOMEGAME_STATS_H_INCLUDED
