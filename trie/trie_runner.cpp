#include <cassert>
#include <iostream>
#include "trie.hpp"

int main(int argc, char** argv){
  Trie t;
  t.add("h");
  t.add("hi");
  t.add("helo");
  t.add("hello");
  t.add("a");
  t.add("trie");
  t.add("is");
  t.add("cool");
  t.add("eggs");

  assert(t.contains_word("hello"));
  assert(t.contains_word("helo"));
  assert(t.contains_word("a"));
  assert(t.contains_word("cool"));
  assert(!t.contains_word("hellow"));
  assert(!t.contains_word("hel"));
  assert(!t.contains_word("hell"));
  assert(!t.contains_word("ib"));
  assert(t.count_prefix("h")==4);
  assert(t.count_prefix("is")==1);
  assert(t.count_prefix("hx")==0);
  assert(t.count_prefix("x")==0);
  assert(t.count_prefix("hel")==2);
  assert(t.count_prefix("hellow")==0);
  assert(t.count_prefix("trie")==1);
  std::cout << "done" << std::endl;
}