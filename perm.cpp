#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
#include <functional>


void fillRandom(int v[],int size, int max = 123){
  int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> dist(97,max);
  auto genNum = std::bind(dist,generator); 
  std::generate(&v[0],&v[size],genNum);
}
template<typename T>
void show(T v[],int size){
  std::for_each(&v[0],&v[size],[](auto x){ std::cout << x << " ";});
  // std::cout << std::endl;
}

template<typename T>
void swap(T& left, T& right){
  T tmp = left;
  left = right;
  right = tmp;
}
template<typename T>
void permute(int cur, T *A, int sz){
  if (cur+1==sz){
    std::cout << cur << ",  result = ";
    show(A,sz);
    std::cout << std::endl;
    return;
  }
  for (int i=cur;i<sz;i++){
    swap(A[cur],A[i]);
    std::cout << "i=" << i << ",cur=" << cur << ", A=" ; show(A,sz); std::cout << std::endl;
    permute(cur+1,A,sz);
  }
}


int main(int argc, char **argv){
  if (argc <2){
    std::cout << "usage: " << argv[0] << " qty" << std::endl;
    return 0;
  }
  int qty = std::stoi(argv[1]);
  int numlist[qty];
  fillRandom(numlist,qty);
  show(numlist,qty);
  std::cout << "----" << qty << " start" << std::endl;
  permute(0,numlist, qty);

  char charlist[qty];
  std::transform(&numlist[0],&numlist[qty],&charlist[0],[](auto x){ return static_cast<char>(x);});
  show(charlist,qty);
  std::cout << "------" << std::endl;
  permute(0,charlist,qty);
}