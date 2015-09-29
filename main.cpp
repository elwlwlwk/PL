#include <string>
#include <iostream>
#include <regex>
#include "Token.h"
#include "Parser.h"

using namespace std;
int main() {
	Parser parser;
	vector<Token> a = parser.tokenize_line("add ( mul -3 3.51 ) ( equ _a343 3 )");
	
	return 0;
}
