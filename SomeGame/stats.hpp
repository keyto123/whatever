#ifndef SOMEGAME_STATS_H_INCLUDED
#define SOMEGAME_STATS_H_INCLUDED

#include <cstdint>

const int MAX_STATS = 40;
const int MAX_LEVEL = 40;

typedef struct {
	std::uint8_t level;

	std::uint8_t strength;
	std::uint8_t vitality;
	std::uint8_t agility;
	std::uint8_t dexterity;
	std::uint8_t luck;

	std::uint8_t str_growth;
	std::uint8_t vit_growth;
	std::uint8_t agi_growth;
	std::uint8_t dex_growth;
	std::uint8_t luk_growth;

	std::uint8_t max_hp;
	std::uint8_t hp;

	std::uint8_t attack;
	std::uint8_t defense;
	std::uint8_t evasion;
	std::uint8_t hit;
	std::uint8_t critical_chance;
} Stats;

enum STATS {
	STR, VIT, AGI, DEX, LUK
};

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

#endif // SOMEGAME_STATS_H_INCLUDED
