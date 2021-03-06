#include <regex>

#include "Parser.h"
#include "Grammer.h"

bool Parser::validate_sentence(std::string cmd) {
	return true;
}

std::vector<Token> Parser::tokenize(std::string cmd) {
	if (!validate_sentence(cmd)) {
		return std::vector<Token>();
	}
}

std::vector<Token> Parser::tokenize_line(std::string cmd) {
	if (!validate_sentence(cmd)) {
		return std::vector<Token>();
	}
	std::vector<std::string> v_cmd = str_tok(cmd, std::string(" "));
	std::vector<Token> v_tok = analyzer(v_cmd);
	return v_tok;
}

std::vector<std::string> Parser::str_tok(std::string str, std::string delimiters) {
	std::vector<std::string> tokens;
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
	return tokens;
}

std::vector<Token> Parser::analyzer(std::vector<std::string> v_cmd) {
	std::vector<Token> v_tok;
	Grammer grammer= Grammer();
	for (int i = 0; i< v_cmd.size(); i++) {
		if (std::regex_search(v_cmd[i], grammer.get_operator_regex())){
			v_tok.push_back (Token("operator", v_cmd[i]));
		}
		else if (std::regex_search(v_cmd[i], grammer.get_integer_regex())) {
			v_tok.push_back(Token("integer", v_cmd[i]));
		}
		else if (std::regex_search(v_cmd[i], grammer.get_float_regex())) {
			v_tok.push_back(Token("float", v_cmd[i]));
		}
		else if (std::regex_search(v_cmd[i], grammer.get_l_paren_regex())) {
			v_tok.push_back(Token("l_paren", v_cmd[i]));
		}
		else if (std::regex_search(v_cmd[i], grammer.get_r_paren_regex())) {
			v_tok.push_back(Token("r_paren", v_cmd[i]));
		}
		else if (std::regex_search(v_cmd[i], grammer.get_variable_regex())) {
			v_tok.push_back(Token("variable", v_cmd[i]));
		}
		else if (std::regex_search(v_cmd[i], grammer.get_string_regex())) {
			v_cmd[i]= v_cmd[i].substr(1, v_cmd[i].length() - 2);
			v_tok.push_back(Token("string", v_cmd[i]));
		}
		else {
			v_tok.push_back(Token("unknown", v_cmd[i]));
		}
	}
	return v_tok;
}
