#ifndef PL_GRAMMER
#define PL_GRAMMER
#include <regex>

class Grammer {
private:

public:
	std::regex get_operator_regex() { return std::regex("(equ|add|sub|mul|div|pow|nrt|exp|ln|sin|cos)"); };
	std::regex get_integer_regex() { return std::regex("^-?[0-9]+$"); };
	std::regex get_float_regex() { return std::regex("^-?[0-9]+\\.[0-9]+$"); };
	std::regex get_variable_regex() { return std::regex("^_*[a-z_]+[a-z0-_]*$"); };
	std::regex get_r_paren_regex() { return std::regex("\\)"); }
	std::regex get_l_paren_regex() { return std::regex("\\("); }
};

#endif