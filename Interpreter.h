#ifndef PL_INTERPRETER
#define PL_INTERPRETER

#include <map>
#include <vector>

#include "Token.h"
class Interpreter {
private:
	std::map<std::string, Token> m_variables;
	std::vector<Token> token_stack;

	Token execute(std::vector<Token> v_token);
	Token replace_variable(Token tok);

	Token exe_equ(Token l_t, Token r_t);
	Token exe_add(Token l_t, Token r_t);
	Token exe_sub(Token l_t, Token r_t);
	Token exe_mul(Token l_t, Token r_t);
	Token exe_div(Token l_t, Token r_t);
public:
	Token process(std::vector<Token> v_token);
};

#endif