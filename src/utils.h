#pragma once

#include <string>

class Utils {
public:
	static int get_random_value();
	static std::string get_file_line(const char* file_name, int line);
	static std::string get_file_content(const char* file_name);

private:
	char** file_content;
};
