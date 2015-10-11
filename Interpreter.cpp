#include <regex>
#include <algorithm>
#include <math.h>
#include <iostream>

#include "Interpreter.h"
#include "Grammer.h"

Token Interpreter::replace_variable(Token tok) {
	Token result = tok;
	if (tok.get_type().compare("variable") == 0) {
		if (m_variables.count(tok.get_val()) == 0) {
			m_variables[tok.get_val()] = Token("integer", 0);
		}
		result = m_variables[tok.get_val()];
	}
	return result;
}

Token Interpreter::process(std::vector<Token> v_token) {
	std::vector<Token> token_stack;
	for (int i = 0; i < v_token.size(); i++) {
		if (v_token[i].get_type().compare("r_paren")!= 0) {
			token_stack.push_back(v_token[i]);
		}		
		else{
			std::vector<Token> sub_v_token;
			while (token_stack[token_stack.size()-1].get_type().compare("l_paren")!= 0) {
				sub_v_token.push_back(token_stack[token_stack.size() - 1]);
				token_stack.pop_back();
			}
			if (token_stack[token_stack.size() - 1].get_type().compare("l_paren") == 0) {
				token_stack.pop_back();
			}
			std::reverse(sub_v_token.begin(), sub_v_token.end());
			token_stack.push_back(execute(sub_v_token));
		}
	}
	return execute(token_stack);
}

Token Interpreter::execute(std::vector<Token> v_token) {
	if (v_token[0].get_val().compare("equ") == 0) {
		return exe_equ(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("add") == 0) {
		return exe_add(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("sub") == 0) {
		return exe_sub(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("mul") == 0) {
		return exe_mul(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("div") == 0) {
		return exe_div(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("pow") == 0) {
		return exe_pow(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("nrt") == 0) {
		return exe_nrt(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("exp") == 0) {
		return exe_exp(v_token[1]);
	}
	else if (v_token[0].get_val().compare("ln") == 0) {
		return exe_ln(v_token[1]);
	}
	else if (v_token[0].get_val().compare("sin") == 0) {
		return exe_sin(v_token[1]);
	}
	else if (v_token[0].get_val().compare("cos") == 0) {
		return exe_cos(v_token[1]);
	}
	else if (v_token[0].get_val().compare("int") == 0) {
		return exe_int(v_token[1]);
	}
	else if (v_token[0].get_val().compare("float") == 0) {
		return exe_float(v_token[1]);
	}
	else if (v_token[0].get_val().compare("is") == 0) {
		return exe_is(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("gt") == 0) {
		return exe_gt(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("lt") == 0) {
		return exe_lt(v_token[1], v_token[2]);
	}
	else if (v_token[0].get_val().compare("if") == 0) {
		return exe_if(v_token[1], v_token[2], v_token[3]);
	}
	else if (v_token[0].get_val().compare("print") == 0) {
		return exe_print(v_token[1]);
	}
	else if (v_token[0].get_val().compare("reset") == 0) {
		return exe_reset();
	}
	else if (v_token[0].get_val().compare("type") == 0) {
		return exe_type(v_token[1]);
	}
	else if (v_token[0].get_val().compare("tostring") == 0) {
		return exe_tostring(v_token[1]);
	}
	else if (v_token[0].get_val().compare("tovalue") == 0) {
		return exe_tovalue(v_token[1]);
	}
	return Token();
}

Token Interpreter::exe_equ(Token l_t, Token r_t) {
	m_variables[l_t.get_val()] = r_t;
	return l_t;
}
Token Interpreter::exe_add(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (l_t.get_type().compare("integer") == 0 && r_t.get_type().compare("integer") == 0) {
		return Token("integer", std::to_string(atoi(l_t.get_val().c_str()) + atoi(r_t.get_val().c_str())));
	}
	else {
		return Token("float", std::to_string(atof(l_t.get_val().c_str()) + atof(r_t.get_val().c_str())));
	}
}
Token Interpreter::exe_sub(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (l_t.get_type().compare("integer") == 0 && r_t.get_type().compare("integer") == 0) {
		return Token("integer", std::to_string(atoi(l_t.get_val().c_str()) - atoi(r_t.get_val().c_str())));
	}
	else {
		return Token("float", std::to_string(atof(l_t.get_val().c_str()) - atof(r_t.get_val().c_str())));
	}
}
Token Interpreter::exe_mul(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (l_t.get_type().compare("integer") == 0 && r_t.get_type().compare("integer") == 0) {
		return Token("integer", std::to_string(atoi(l_t.get_val().c_str()) * atoi(r_t.get_val().c_str())));
	}
	else {
		return Token("float", std::to_string(atof(l_t.get_val().c_str()) * atof(r_t.get_val().c_str())));
	}
}
Token Interpreter::exe_div(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (l_t.get_type().compare("integer") == 0 && r_t.get_type().compare("integer") == 0) {
		return Token("integer", std::to_string(atoi(l_t.get_val().c_str()) / atoi(r_t.get_val().c_str())));
	}
	else {
		return Token("float", std::to_string(atof(l_t.get_val().c_str()) / atof(r_t.get_val().c_str())));
	}
}
Token Interpreter::exe_pow(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (l_t.get_type().compare("integer") == 0 && r_t.get_type().compare("integer") == 0) {
		return Token("integer", std::to_string(atoi(l_t.get_val().c_str()) / atoi(r_t.get_val().c_str())));
	}
	else {
		return Token("float", std::to_string(atof(l_t.get_val().c_str()) / atof(r_t.get_val().c_str())));
	}
}
Token Interpreter::exe_nrt(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (l_t.get_type().compare("integer") == 0 && r_t.get_type().compare("integer") == 0) {
		return Token("integer", std::to_string(atoi(l_t.get_val().c_str()) / atoi(r_t.get_val().c_str())));
	}
	else {
		return Token("float", std::to_string(atof(l_t.get_val().c_str()) / atof(r_t.get_val().c_str())));
	}
}
Token Interpreter::exe_exp(Token l_t) {
	l_t = replace_variable(l_t);
	return Token("float", std::to_string(std::exp(atof(l_t.get_val().c_str()))));
}
Token Interpreter::exe_ln(Token l_t) {
	l_t = replace_variable(l_t);
	return Token("float", std::to_string(std::log(atof(l_t.get_val().c_str()))));
}
Token Interpreter::exe_sin(Token l_t) {
	l_t = replace_variable(l_t);
	return Token("float", std::to_string(std::sin(atof(l_t.get_val().c_str()) / 180 * (std::atan(1) * 4))));
}
Token Interpreter::exe_cos(Token l_t) {
	l_t = replace_variable(l_t);
	return Token("float", std::to_string(std::cos(atof(l_t.get_val().c_str()) / 180 * (std::atan(1) * 4))));
}
Token Interpreter::exe_int(Token l_t) {
	l_t = replace_variable(l_t);
	if (l_t.get_type().compare("float") == 0) {
		return Token("integer", std::to_string((int)atof(l_t.get_val().c_str())));
	}
	return l_t;
}
Token Interpreter::exe_float(Token l_t) {
	l_t = replace_variable(l_t);
	if (l_t.get_type().compare("integer") == 0) {
		return Token("float", l_t.get_val());
	}
	return l_t;
}
Token Interpreter::exe_is(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (l_t.get_type().compare(r_t.get_type()) == 0 && l_t.get_val().compare(r_t.get_val())== 0) {
		return Token("integer", "1");
	}
	else {
		return Token("integer", "0");
	}
}
Token Interpreter::exe_gt(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (atof(l_t.get_val().c_str())> atof(r_t.get_val().c_str())) {
		return Token("integer", "1");
	}
	else {
		return Token("integer", "0");
	}
}
Token Interpreter::exe_lt(Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (atof(l_t.get_val().c_str())< atof(r_t.get_val().c_str())) {
		return Token("integer", "1");
	}
	else {
		return Token("integer", "0");
	}
}
Token Interpreter::exe_if(Token stat, Token l_t, Token r_t) {
	l_t = replace_variable(l_t);
	r_t = replace_variable(r_t);
	if (atoi(stat.get_val().c_str())== 1) {
		return l_t;
	}
	else {
		return r_t;
	}
}
Token Interpreter::exe_print(Token l_t) {
	l_t = replace_variable(l_t);
	std::cout << l_t.get_val() << std::endl;
	return l_t;
}
Token Interpreter::exe_reset() {
	m_variables.clear();
	return Token("integer", "0");
}
Token Interpreter::exe_type(Token l_t) {
	l_t = replace_variable(l_t);
	return Token("string", l_t.get_type());
}
Token Interpreter::exe_tostring(Token l_t) {
	l_t = replace_variable(l_t);
	return Token("string", l_t.get_val());
}
Token Interpreter::exe_tovalue(Token l_t) {
	Grammer grammer;
	l_t = replace_variable(l_t);
	if (std::regex_search(l_t.get_val(), grammer.get_float_regex())) {
		return Token("float", l_t.get_val());
	}
	else if (std::regex_search(l_t.get_val(), grammer.get_integer_regex())) {
		return Token("integer", l_t.get_val());
	}
	return Token();
}