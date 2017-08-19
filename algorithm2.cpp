#include<string>
#include<algorithm>
#include<iostream>
#include <random>
#include <functional>
#include <chrono>

using namespace std;

const int sz = int{10};

void generateRandomInts(int num, vector<int>& v){
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(1,100);
  auto dice = std::bind(distribution,generator); // effectively distribution(generator)
  // for (int i=0;i<num;i++){
  //   int anum = dice();
  //   std::cout << "random = " << anum << endl;
  //    v.push_back( anum );
  // }
  std::generate(v.begin(),v.end(),dice);
}



int main(int argc, char** argv){

  std::cout << "arguments " << argc << " : " ;
  for (int i=0;i<argc;i++){
    cout << argv[i] ;
    if (i<argc-1) cout << ", ";
  } 
  std::cout << std::endl;

  if (argc != 2){
    std::cout << "usage: " << argv[0] << " qty" << endl;
    return 0;
  }
  int qty = stoi(argv[1]);
  std::cout <<  qty << " numbers " << std::endl;
  std::vector<int> numbers(qty);
  generateRandomInts(std::stoi(argv[1]),numbers);
  std::vector<int>::iterator it;
  // for (it=numbers.begin();it<numbers.end();it++){
  //   std::cout << *it << std::endl;
  // }
  for (auto i : numbers ){
    std::cout << i << std::endl;
  }
  
}