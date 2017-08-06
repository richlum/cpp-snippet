#include <iostream>
#include <string>

template <class T>
T sum(T a, T b){
  return a+b;
}

int main(int argc, char** argv){
  std::cout << sum(3,3) << std::endl;
  std::cout << sum(std::string("abc"),std::string("def"))  << std::endl;
  std::cout << sum(1.2,3.4) << std::endl;
}