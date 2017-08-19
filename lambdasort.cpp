#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<chrono>
#include<random>
#include<functional>

using namespace std;

void generateRandomInts(int num,vector<int>& v){
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator(seed);
  uniform_int_distribution<int> distribution(1,100);
  auto dice = bind(distribution,generator);
  generate(v.begin(),v.end(),dice);
}


int main(int argc, char **argv){
  if (argc!=2){
    cout<<"usage: " << argv[0] << " qty" << endl;
    return 0;
  }
  int qty = stoi(argv[1]);
  vector<int> v(qty);

  // iota(v.begin(),v.end(),1);
  generateRandomInts(qty,v);  
  cout << "original data" << endl;
  for_each(v.begin(),v.end(),[](auto i){cout<<i<<" ";});
  cout<<endl;
  sort(v.begin(),v.end(),[](auto i, auto j){ return i<j;});
  cout << "sorted data" << endl;
  for_each(v.begin(),v.end(),[](auto i){cout<<i<<" ";});
  cout<<endl;
  return 0;

}