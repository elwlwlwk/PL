class Parser{
private:
	bool validate_sentence(string cmd);
public:
	vector<Token> tokenize(string cmd);
}
