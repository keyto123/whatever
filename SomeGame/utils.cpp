#include "utils.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 99);

int get_random_value() {
	return dis(gen);
}
