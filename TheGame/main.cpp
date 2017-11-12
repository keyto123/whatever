#include <iostream>
#include "player.h"

#define TESTING

#ifdef TESTING
	#include "teste.h"
#endif

int main() {
#ifdef TESTING
    teste();
#endif
    return 0;
}
