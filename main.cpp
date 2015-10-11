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
	while (1) {
		string cmd;
		getline(cin,cmd);
		inter.process(parser.tokenize_line(cmd));
	}
	return 0;
}
