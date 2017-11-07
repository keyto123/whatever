#ifndef SOMEGAME_PLAYER_H_INCLUDED
#define SOMEGAME_PLAYER_H_INCLUDED

#include "alive.hpp"

const int MAX_EXP = 99999;

class Player: public Alive {
public:
	Player(const char* name);
	Player(const char* name, Stats stats);
	int exp_up(int exp_gain);
	int set_exp(int exp);
	int level_up();
	int stat_up(int stat, int rnd);
private:
	int total_exp;
	int level_exp;
};

#endif // SOMEGAME_PLAYER_H_INCLUDED
