#include "player.h"

int create_player() {

}

int player_level_up() {

}

int player_exp_gain(Player* p, int exp_gain) {
	p->total_exp += exp_gain;
	if(p->level_exp != MAX_EXP) {
		return 0;
	}
	p->level_exp += exp_gain;
	return 1;
}

