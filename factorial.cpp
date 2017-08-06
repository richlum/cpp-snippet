#include<iostream>
using namespace std;

inline long fact (long a){
  if (a>1)
    return (a*fact(a-1));
  else
    return 1;
}


int main(int argc,char** argv){

  int value;
  if (argc!=2){
    cout << "usage: " << argv[0] << " integerValue" << endl;
    return 0;
  }
  value = stoi(argv[1]);
  cout << "factorial  " << value << endl;
  cout << fact(value) << endl;
}