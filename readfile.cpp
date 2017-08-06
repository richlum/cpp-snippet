#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv){
  string line;
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while(getline(myfile,line)){
      cout << line << '\n';
    }
    myfile.close();
  }else{
    cout << "unable to open file " << argv[1] << endl;
  }
  return 0;
  
}