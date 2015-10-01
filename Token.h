#ifndef PL_TOKEN
#define PL_TOKEN

#include <string>
class Token {
private:
	std::string type;
	std::string val;
	std::string var_val;
public:
	Token():type("null"),val("null"),var_val("null"){};
	Token(std::string type, std::string val);
	Token(std::string type, std::string val, std::string var_val);
	std::string get_val();
	std::string get_type();
	std::string get_var_val();
};

#endif
