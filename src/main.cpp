#include <iostream>
#include "player.h"

#define TESTING

#ifdef TESTING
	#include "test.h"
#endif

int main() {
#ifdef TESTING
    test();
#endif
    return 0;
}
