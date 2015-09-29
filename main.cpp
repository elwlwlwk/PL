#include <string>
#include <iostream>
#include "Token.h"
#include "Parser.h"

using namespace std;
int main() {
	Parser parser;
	vector<Token> a = parser.tokenize_line("add test add test2");

	return 0;
}
