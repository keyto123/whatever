#ifndef MYGAME_ALIVE_HPP_INCLUDED
#define MYGAME_ALIVE_HPP_INCLUDED

#include "stats.hpp"

class Alive {
public:
	Alive(const char* name);
	Alive(const char* name, Stats stats);
	void set_default_stats();
	char* get_name();
	Stats get_stats();
	Stats stats;
protected:
	char* name;
};

#endif // MYGAME_ALIVE_HPP_INCLUDED
