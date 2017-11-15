#include "utils.h"
#include <fstream>
#include <cstdlib>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 99);
std::ifstream file;

int Utils::get_random_value() {
	return dis(gen);
}

/*
TODO: Some day it will be done
char* Utils::get_file_line(const char* file_path, int line) {
	file = std::ifstream(file_path);
	char* line_content = (char*)malloc(100);
	
	file.close();
		if (line_content[0] == '/' && line_content[1] == '/')
			--i;
	return line_content;
}
char** Utils::get_file_content(const char* file_path) {
	for(int i = 0; file_content[i][0] != EOF; i++) {
		file.getline(file_content[i], 100);
	}
}
*/