#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> doubleVals (const vector<int>& v){
  vector<int> new_vals;
  new_vals.reserve(v.size());
  for (auto itr = v.begin(), end_itr = v.end(); itr != end_itr; ++itr){
    new_vals.push_back( 2 * *itr);
  }
  return new_vals;
}

int main (int argc, char **argv){
  vector<int> v;
  for(int i=0;i<100;i++){
    v.push_back( i );
  }
  v = doubleVals(v);

  for_each(v.begin(), v.end(), [](auto x){ std::cout << x << " "; });

  std::cout << std::endl;

}

