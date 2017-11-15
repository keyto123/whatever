#ifndef MYGAME_UTILS_HPP_INCLUDED
#define MYGAME_UTILS_HPP_INCLUDED

class Utils {
public:
	int get_random_value();
	char* get_file_line(const char* file_name, int line);
	char** get_file_content(const char* file_name);

private:
	char** file_content;
};


#endif // MYGAME_UTILS_HPP_INCLUDED
