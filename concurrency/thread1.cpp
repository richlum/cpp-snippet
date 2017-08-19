#include <thread>
#include <iostream>
#include <vector>
#include <string>

void worker(){
  std::cout << "Thread " << std::this_thread::get_id() << std::endl;
}

int main(int argc, char **argv){
  if (argc!=2){
    std::cout <<  "usage: " << argv[0] << "qtyOfWorkerThreads" << std::endl;
    return 0;
  }
  int qty = std::stoi(argv[1]);
  std::vector<std::thread> threads;

  for (int i=0;i<qty;i++){
    threads.push_back(std::thread(worker));
  }

  for (auto& thread: threads){
    thread.join();
  }

  return 0;
}