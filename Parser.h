#ifndef PL_PARSER
#define PL_PARSER

#include <vector>
#include <string>

#include "Token.h"
class Parser {
private:
	bool validate_sentence(std::string cmd);
	std::vector<std::string> str_tok(std::string cmd, std::string token);
	std::vector<Token> analyzer(std::vector<std::string> v_cmd);
public:
	std::vector<Token> tokenize(std::string cmd);
	std::vector<Token> tokenize_line(std::string cmd);
};

#endif
