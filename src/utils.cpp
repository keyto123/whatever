#include "utils.h"
#include <fstream>
#include <cstdlib>
#include <random>
#include <sstream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 99);

int Utils::get_random_value() {
	return dis(gen);
}


// TODO: Some day it will be done
std::string Utils::get_file_line(const char* file_path, int line) {
	std::ifstream file = std::ifstream(file_path);

	std::string sline;
	int i = 0;
	for (; getline(file, sline); i++) {
		if (i == line) {
			break;
		}
	}
	if (i != line) {
		return nullptr;
	}
	file.close();
	return sline;
}

std::string Utils::get_file_content(const char* file_path) {
	std::ifstream file = std::ifstream(file_path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}
