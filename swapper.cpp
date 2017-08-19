#include <iostream>
#include <algorithm>
#include <functional>

auto showelm = [](auto val){ std::cout << val << " ";};

template <typename T>
void showarray(T col[], unsigned len){
  //int len = (sizeof(col)/sizeof(*col));
  std::for_each(&col[0],&col[len-1],showelm);
  std::cout << std::endl;  
}


int main(int argc, char **argv){
  int a=5, b=3;
  std::cout << a << "," << b << std::endl;
  std::swap(a,b);
  std::cout << a << "," << b << std::endl;

 // int c[] = {std::iota(0,9,1)} ;
  const int size = 10;
  int d[size];
  std::iota(&d[0],&d[size-1],100);
  //std::for_each(&d[0],&d[9],[](auto val){ std::cout << val << " ";});
  // std::for_each(&d[0],&d[9],showelm);
  // std::cout << std::endl;
  showarray(d,sizeof(d)/sizeof(*d));

  int c[size];
  std::iota(&c[0],&c[size-1],size+1);
  //std::for_each(&c[0],&c[9],[](auto val){ std::cout << val << " ";});
    // std::for_each(&c[0],&c[size-1],showelm);
    // std::cout << std::endl;
  showarray(c,sizeof(c)/sizeof(*d));


  std::swap(c,d);
  std::cout << " after swap " << std::endl;
  showarray(d,sizeof(d)/sizeof(*d));
  showarray(c,sizeof(c)/sizeof(*d));
  

}