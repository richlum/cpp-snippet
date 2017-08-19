#include <iostream>
#include <complex>

int main(int argc, char **argv){
  auto func = [](auto input){
    return input * input;
  };

  std::cout << func(11) << std::endl;
  std::cout << func(2.345) << std::endl;
  std::cout << func(std::complex<double>(3,-2))  << std::endl; 
}