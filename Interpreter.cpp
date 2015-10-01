#include <regex>
#include <algorithm>
#include <math.h>

#include "Interpreter.h"

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