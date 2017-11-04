#include "alive.hpp"

Alive::Alive(const char* name) {
	Alive::name = (char*)name;
}

char* Alive::get_name() {
	return Alive::name;
}
