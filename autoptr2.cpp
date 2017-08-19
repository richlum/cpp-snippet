#include <iostream>

template<class T>
class Auto_ptr3{
  T* m_ptr;
public:
  Auto_ptr3(T* ptr = nullptr): m_ptr(ptr){
  }
  ~Auto_ptr3(){
    delete m_ptr;
  }
  Auto_ptr3(const Auto_ptr3& other){
    m_ptr = new T;
    *m_ptr = *other.m_ptr;
  }
  Auto_ptr3& operator=(const Auto_ptr3& other){
    if(&other == this)
      return *this;
    delete m_ptr;
    m_ptr = new T;
    *m_ptr = *other.m_ptr;
    return *this;   
  }
  T& operator*() const { return *m_ptr; }
  T* operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};

class Resource {
public:
  Resource() { std::cout << "resource acquired" << std::endl; }
  ~Resource() { std::cout << "resource destroyed" << std::endl; }
};

Auto_ptr3<Resource> generateResource(){
  Auto_ptr3<Resource> res(new Resource);
  return res;
}

int main(int argc, char **argv){
  Auto_ptr3<Resource> mainres;
  mainres = generateResource();
  return 0;
}

