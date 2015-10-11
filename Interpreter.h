#ifndef PL_INTERPRETER
#define PL_INTERPRETER

#include <map>
#include <vector>

#include "Token.h"
class Interpreter {
private:
	std::map<std::string, Token> m_variables;

	Token execute(std::vector<Token> v_token);
	Token replace_variable(Token tok);

	Token exe_equ(Token l_t, Token r_t);
	Token exe_add(Token l_t, Token r_t);
	Token exe_sub(Token l_t, Token r_t);
	Token exe_mul(Token l_t, Token r_t);
	Token exe_div(Token l_t, Token r_t);
	Token exe_pow(Token l_t, Token r_t);
	Token exe_nrt(Token l_t, Token r_t);
	Token exe_exp(Token l_t);
	Token exe_ln(Token l_t);
	Token exe_sin(Token l_t);
	Token exe_cos(Token l_t);
	Token exe_int(Token l_t);
	Token exe_float(Token l_t);
	Token exe_is(Token l_t, Token r_t);
	Token exe_gt(Token l_t, Token r_t);
	Token exe_lt(Token l_t, Token r_t);
	Token exe_if(Token stat, Token l_t, Token r_t);
	Token exe_print(Token l_t);
	Token exe_reset();
	Token exe_type(Token l_t);
	Token exe_tostring(Token l_t);
	Token exe_tovalue(Token l_t);
public:
	Token process(std::vector<Token> v_token);
};

#endif