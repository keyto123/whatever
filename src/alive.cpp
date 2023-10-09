#include "alive.h"

Alive::Alive(const char* name, Stats stats = default_stats) {
	Alive::name = (char*)name;
    Alive::stats = stats;
}

char* Alive::get_name() {
	return name;
}
