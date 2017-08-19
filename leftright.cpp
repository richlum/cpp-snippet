#include <iostream>


void fun(const int &lref){
  std::cout << "lhv const" << std::endl;
}

void fun(int &&rref){
  std::cout << "rhv ref" << std::endl;
}

int main(int argc, char** argv){
  int x = 5;
  fun(x);
  fun(5);
  return 0;
}