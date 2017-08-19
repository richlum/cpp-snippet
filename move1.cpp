#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char** argv){
  std::string str = "hello world";
  std::vector<std::string> v;

  v.push_back(str);
  std::cout << "after copy, str is ' " << str << std::endl;

  v.push_back(std::move(str));
  std::cout << "after move, str is ' " << str << std::endl;
  std::cout << "vector is " ;
  std::for_each(v.begin(), v.end(), [](auto x){ std::cout << x << " ";  });
  std::cout << std::endl;

}