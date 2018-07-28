#ifndef __TRIE__H
#define __TRIE__H

#include <memory>

#define NULL_TERM '\0'

inline int char_idx(const char c){ return int(c) - int('a'); }

class TrieNode{
  friend class Trie;
private:
  int count = 0;
  bool terminal = false;
  std::unique_ptr<TrieNode> children[26];

  void add(const char*);
  bool contains_word(const char*) const;
  int count_prefix(const char*) const;
}
;

class Trie{
public:
  void add(const char* s){
    first_chars[char_idx(*s)].add(s);
  }
  bool contains_word(const char* s) const {
    return first_chars[char_idx(*s)].contains_word(s);
  }
  int count_prefix(const char* s) const {
    return first_chars[char_idx(*s)].count_prefix(s);
  }
private:
  TrieNode first_chars[26];
}
;

#endif 