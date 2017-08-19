#include <iostream>
#include <string>
#include <algorithm>

int main(int argc,char **argv){
	std::string s = "one two three four five six";
	for_each(s.begin(),s.end(),[](auto c){ std::cout << c << std::endl; });
}
