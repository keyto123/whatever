#ifndef MYGAME_ALIVE_HPP_INCLUDED
#define MYGAME_ALIVE_HPP_INCLUDED

#include "stats.h"

class Alive {
public:
	Alive(const char* name, Stats stats);
	char* get_name();
	Stats stats;
protected:
	char* name;
};

#endif // MYGAME_ALIVE_HPP_INCLUDED
