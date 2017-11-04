#include <stdio.h>
#include <stdlib.h>
#include "player.h"


void print_player(Player* p) {
	printf("Level: %d\n", p->stats.level);

	printf("Stats: %d, %d, %d, %d, %d\n", p->stats.strength,
			p->stats.vitality, p->stats.agility,
			p->stats.dexterity, p->stats.luck);

	printf("Stats growth: %d, %d, %d, %d, %d\n", p->stats.str_growth,
			p->stats.vit_growth, p->stats.agi_growth,
			p->stats.dex_growth, p->stats.luk_growth);

	printf("Hp: %d/%d\n", p->stats.hp, p->stats.max_hp);

	printf("Final stats: %d, %d, %d, %d, %d\n", p->stats.attack,
			p->stats.defense, p->stats.evasion,
			p->stats.hit, p->stats.critical_chance);

}

int teste() {
	Player player("Lucas");
	char user_option;
	while(1) {
        system("clear");
		print_player(&player);
		scanf("%c", &user_option);
		switch(user_option) {
		default:
			exit(0);
		}
	}
	return 1;
}
