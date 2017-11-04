#ifndef SOMEGAME_PLAYER_H_INCLUDED
#define SOMEGAME_PLAYER_H_INCLUDED

#include "stats.hpp"
#include "alive.hpp"

const int MAX_EXP = 99999;

enum STATS {
	STR, VIT, AGI, DEX, LUK
};

class Player: public Alive {
public:
	Player(const char* name);
	int exp_up(int exp_gain);
	int set_exp(int exp);
	int level_up();
	int stat_up(int stat, int rnd);
	int get_stats(int stat);
private:
	int total_exp;
	int level_exp;
};

#endif // SOMEGAME_PLAYER_H_INCLUDED
