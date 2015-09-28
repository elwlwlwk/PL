#include <string>
#include <iostream>
#include "Token.h"

using namespace std;
int main(){
	Token test("test","test2");
	std::cout<<test.get_val()<<test.get_type()<<std::endl;

	return 0;
}
