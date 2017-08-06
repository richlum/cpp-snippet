#include<iostream>
#include<string>

inline std::string concatenate(const std::string& left, const std::string& right){
  return left+right;
}


int main(int argc, char** argv){
  std::string a,b;
  if (argc==3){
    a = std::string(argv[1]);
    b = std::string(argv[2]);
  }else{
    a = std::string("Hello");
    b = std::string("World");
  }
  std::cout << concatenate(a,b);
}