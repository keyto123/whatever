#pragma once

#include "stats.h"

class Alive {
public:
	Alive(const char* name, Stats stats);
	char* get_name();
	Stats stats;
protected:
	char* name;
};
