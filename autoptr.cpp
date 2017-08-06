#include <iostream>
#include <string>

template<class T>
class Auto_ptr1{
  T* m_ptr;
public:
    Auto_ptr1(T* ptr=nullptr):m_ptr(ptr){
    }
    ~Auto_ptr1(){
      delete m_ptr;
    }
    T& operator*() const { return *m_ptr;}
    T* operator->() const { return m_ptr; }
};

class Resource{
public:
  const std::string name = "I am a resource";
  Resource() { std::cout << "resource acquired" << std::endl; }
  ~Resource() { std::cout << "resource destroyed" << std::endl; }
  std::string getName() { return name; };
};

int main(int argc, char** argv){
  Auto_ptr1<Resource> res(new Resource);
  std::cout << (*res).name << std::endl;
  std::cout << res->name << std::endl;
  return 0;
}

/*
  auto_ptr1 is to hold ownership of an object and delete it when auto_ptr is deleted
  operator overloading to allow dereferencing of class members.
*/