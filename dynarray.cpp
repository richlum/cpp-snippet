#include <iostream>
#include <new>

using namespace std;

int main(int argc, char** argv){
  int i,n;
  int * p;
  cout << "Qty to store";
  cin >> i;
  p = new (nothrow) int[i];
  if (p==nullptr)
    cout << "Error: unable to allocate memory";
  else{
    for (n=0;n<i;n++){
      cout << "enter number:";
      cin >> p[n];
    }
    cout << "Entered value: ";
    for (n=0;n<i;n++){
      cout << p[n];
    }
    delete[] p;
  }  
  return 0;
}