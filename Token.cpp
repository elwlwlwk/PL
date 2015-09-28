#include "Token.h"
Token::Token(std::string type, std::string val):type(type), val(val){
}
std::string Token::get_val(){
	return this->val;
}
std::string Token::get_type(){
	return this->type;
}
