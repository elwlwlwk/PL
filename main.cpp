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
	std::cout << inter.process(a).get_val() << endl;
	a = parser.tokenize_line("add a 3");
	std::cout << inter.process(a).get_val() << endl;
	a = parser.tokenize_line("exp 3");
	std::cout << inter.process(a).get_val() << endl;
	a = parser.tokenize_line("cos 90");
	std::cout << inter.process(a).get_val() << endl;
	
	
	return 0;
}
