#include "Token.h"

Token::Token(std::string type, std::string val) :type(type), val(val),var_val(val) {
}

Token::Token(std::string type, std::string val, std::string var_val) : type(type), val(val), var_val(var_val) {
}

std::string Token::get_val() {
	return this->val;
}
std::string Token::get_type() {
	return this->type;
}

std::string Token::get_var_val() {
	return this->var_val;
}