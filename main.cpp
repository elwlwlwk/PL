#include <string>
#include <iostream>
#include <regex>
#include "Token.h"
#include "Parser.h"
#include "Interpreter.h"

using namespace std;
int main() {
	Parser parser;
	Interpreter inter;
	vector<Token> a = parser.tokenize_line("add ( add -3.4 6 ) ( equ a 3 )");
	std::cout<<inter.process(a).get_val();
	
	return 0;
}
