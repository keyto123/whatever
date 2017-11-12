#include "alive.h"

Alive::Alive(const char* name) {
	Alive::name = (char*)name;
	Alive::set_default_stats();
}

Alive::Alive(const char* name, Stats stats) {
	Alive::name = (char*)name;
    Alive::stats = stats;
}

char* Alive::get_name() {
	return Alive::name;
}

void Alive::set_default_stats() {
	Alive::stats = default_stats;
}
