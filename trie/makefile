CXXFLAGS=-std=c++14 -g -Wall
LDFLAGS=-pthread
LIBS=-L/usr/local/lib

clean:
	rm *.o trie_runner
trie: trie.cpp trie.hpp 
	clang ${CXXFLAGS}    $<   -c

trie_runner:  trie_runner.cpp trie.o
	clang++ -v ${CXXFLAGS} ${LIBS} -o $@   $^
