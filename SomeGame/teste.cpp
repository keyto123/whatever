#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

#include "player.h"

#ifdef _WIN32
	#define CLEAR_SCREEN system("cls");
#else
	#define CLEAR_SCREEN(); system("clear");
#endif // linux

void print_player(Player* p) {
	std::uint8_t* p_st = &p->stats.level;
	std::uint8_t index = 0;

	printf("Name: %s\n", p->get_name());

	printf("Level: %d\n", *(p_st + index));
	printf("Hp: %d/%d\n", p->stats.hp, p->stats.max_hp);
	index += 3;

	printf("Stats:");
	for(int i = 0; i < 5; i++, index++) {
		printf(" %d", *(p_st + index));
	}
	printf("\n");

	printf("Stats growth:");
	for(int i = 0; i < 5; i++, index++) {
		printf(" %d", *(p_st + index));
	}
	printf("\n");
}

void player_level_up(Player* player) {
	player->level_up();
}

Stats get_some_stats() {
	Stats stats = {
		1, 					// Level
		20,20, 				// Current hp, Max hp
		2,4,6,8,10, 		// Stats
		80,70,60,50,40,30 	// Stats growth
	};
	return stats;
}

void up_to_max(Player* player) {
	for(int i = 0; i < 39; i++) {
		player_level_up(player);
	}
}

void average_stats() {
	Player t1(".", get_some_stats());
	up_to_max(&t1);
	double avg_hp = t1.stats.max_hp, avg_atk = t1.stats.attack,
			avg_def = t1.stats.defense, avg_hit = t1.stats.hit,
			avg_evd = t1.stats.evade, avg_crit = t1.stats.critical;

	for(int i = 0; i < 99; i++) {
		Player t2(".", get_some_stats());
		up_to_max(&t2);
		avg_hp = (avg_hp + t2.stats.max_hp) / 2;
		avg_atk = (avg_atk + t2.stats.attack) / 2;
		avg_def = (avg_def + t2.stats.defense) / 2;
		avg_hit = (avg_hit + t2.stats.hit) / 2;
		avg_evd = (avg_evd + t2.stats.evade) / 2;
		avg_crit = (avg_crit + t2.stats.critical) / 2;
	}
	printf("average stats: HP:%.0f/%.0f\nStats: %.0f %.0f %.0f %.0f %.0f\n", avg_hp, avg_hp, avg_atk,
																avg_def, avg_hit, avg_evd, avg_crit);
}

int teste() {
	average_stats();
	printf("GitHub Testing\n");
	return 1;
}
