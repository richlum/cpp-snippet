#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

struct B { 
  virtual void bar() {
    std::cout << "B::bar"; }
  virtual ~B() = default;
};  

struct D : B {
  D() { std::cout << "D::D" << std::endl;   }
  ~D() { std::cout << "D::~D" << std::endl;  }
  void bar() override {  std::cout << "D::bar" << std::endl; }
};

std::unique_ptr<D> pass_through(std::unique_ptr<D> p){
  p->bar();
  return p;
}

int main(int argc, char **argv){
  std::cout << "unique ownership semantics demo" << std::endl;
  {
    auto p = std::make_unique<D>();
    auto q = pass_through(std::move(p));
    assert(!p);
    q->bar();
  }  

  std::cout << "runtime polymorphism demo" << std::endl;
  {
    std::unique_ptr<B> p = std::make_unique<D>();
    p->bar();
    std::vector<std::unique_ptr<B>> v;
    v.push_back(std::make_unique<D>());
    v.push_back(std::move(p));
    v.emplace_back(new D);
    for(auto& p: v) p->bar();
  }

  std::cout << "custom deleter ddmo" << std::endl;
  std::ofstream("demo.txt") << 'x';
  {
    std::unique_ptr<std::FILE, decltype(&std::fclose)> fp(std::fopen("demo.txt","r"), &std::fclose);
    if(fp)
      std::cout << (char) std::fgetc(fp.get()) <<  std::endl;
  }

  std::cout << "custom lambda expression deleter demo" << std::endl;
  {
    std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr){
      std::cout << "destroying from a custom deleter..." << std::endl;
      delete ptr;
    });
    p->bar();
  }

  std::cout << "Array form of unique_ptr demo" << std::endl;
  {
    std::unique_ptr<D[]> p{ new D[3]};
  }
}

