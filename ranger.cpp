#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
  if (argc<1){
    cout << "usage: " << argv[0] << " word " << endl;
    return 0;
  }
  for (char c : string(argv[1])){
    cout << "[" << c << "]" << endl;
  }
  cout << argv[1] << endl;

}