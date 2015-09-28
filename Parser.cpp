#include "Parser.h"
bool Parser::validate_sentence(string cmd){
	return true;
}
vector<Token> Parser::tokenize(string cmd){
	if(!validate_sentence(cmd)){
		return vector<Token>();
	}
}
