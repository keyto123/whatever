#ifndef SOMEGAME_STATS_H_INCLUDED
#define SOMEGAME_STATS_H_INCLUDED

const int MAX_STATS = 40;
const int MAX_LEVEL = 20;

typedef struct {
	int level;

	int strength;
	int vitality;
	int agility;
	int dexterity;
	int luck;

	int str_growth;
	int vit_growth;
	int agi_growth;
	int dex_growth;
	int luk_growth;

	int max_hp;
	int hp;

	int attack;
	int defense;
	int evasion;
	int hit;
	int critical_chance;
} Stats;

#endif // SOMEGAME_STATS_H_INCLUDED
