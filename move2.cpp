#include <string>
#include <iostream>
#include <iomanip>
#include <utility>

struct A{
  std::string s;
  A() : s("test") {
    std::cout << "A ctor " << &this->s << std::endl;
  }
  A(const A& o) : s(o.s) { std::cout << "move failed" << std::endl; }
  A(A&& o ) noexcept : s(std::move(o.s)){
    std::cout << "copy ctor " << &this->s << std::endl;
  }
};

A f(A a){
  return a;
}

struct B : A {
  std::string s2;
  int n;
};

struct C : B {
  ~C(){}
};

struct D : B {
  D(){}
  ~D(){}              // stop impl mov ctor C::(C&&)
  D(D&&) = default ;  // force move ctor
};

int main(int argc, char **argv){
  std::cout << "trying to move A" << std::endl;
  A a1 = f(A());
  std::cout << "before move, a1.s = " << std::quoted(a1.s) << " " <<  &a1.s << std::endl;
  A a2 = std::move(a1);
  std::cout << "after move, a1.s = " << std::quoted(a1.s) << std::endl;
  std::cout << "after move, a2.s = " << std::quoted(a2.s) << " " << &a2.s << std::endl;
  std::cout << "after move, &a1.s = " << &a1.s << std::endl;

  std::cout << "trying to move B" << std::endl;
  B b1;
  std::cout << "before move, b1.s = " << std::quoted(b1.s) << std::endl;
  B b2 = std::move(b1);
  std::cout << "after move, b1.s = " << std::quoted(b1.s) << std::endl; 
  
}

