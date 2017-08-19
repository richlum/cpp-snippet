#include <iostream>
// #include <iterator> // c++17
#include <string>
#include <regex>

/* 
  http://en.cppreference.com/w/cpp/regex/regex_search

  doesnt seem explain signatures or options very well, the regex pages do
  a much better job at 
    http://www.regular-expressions.info/stdregex.html
    

*/


int main(int argc, char **argv){
  std::string s = "Some people, when confronted with a problem, think \" I know, I'll use regex.  Now they have tow problems";
  std::regex res1 ("REGEX", 
    std::regex_constants::ECMAScript |  std::regex_constants::icase); 
    // std::regex_constants::nosubs 
    // multiline  (^$)
    // basic === posix
    // extended , awk, grep, egrep 
    // or std::regex_match, 2nd param std::match_results, regex object becomes 3rd param
  if (std::regex_search(s, res1)) {
    std::cout << "text contains the phrase 'regex'" << std::endl;
  }
  // usual sig is std::regex_search(subject,match,re)
  //  subject = string or char
  //  match = match object
  //  re regex pattern


  std::regex wordres("(\\S+)");
  auto words_begin = std::sregex_iterator(s.begin(),s.end(),wordres);
  auto words_end = std::sregex_iterator();
  // cregex_iterator for array of char
  // sregex_iterator for string obj
  // wcregex_iterator for array of wchar_t
  // wsregex_itereator for wstring object


  std::cout 
    << "found "
    << std::distance(words_begin,words_end)
    << " words"
    << std::endl;
  
  const int N = 6;
  std::cout << "words longer than " << N << " chars" << std::endl;
  for(std::sregex_iterator i = words_begin;i!=words_begin;++i){
    std::smatch match = *i;
    // cmatch for array of char
    // smatch for std::string obj
    // wcmatch for wchar_t
    // wsmatch when std::wstring obj 
    std::string match_str = match.str();
      // str(), position(), length()
      // no arg or zero arg for overall capture
      // >1 for specific capture group
    if(match_str.size() > N){  // size = num of capture groups + 1 (overall)
      std::cout << " " << match_str << std::endl;
    }
  }

  std::regex long_word_regex("(\\w{7,})");
  std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
  std::cout << new_s << std::endl;
}

