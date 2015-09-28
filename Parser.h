#include <vector>
#include <string>

#include "Token.h"
class Parser{
private:
	bool validate_sentence(std::string cmd);
public:
	std::vector<Token> tokenize(std::string cmd);
}
