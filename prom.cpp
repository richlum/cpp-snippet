#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>

void accumulate (
	std::vector<int>::iterator first,
	std::vector<int>::iterator last,
	std::promise<int> accumulate_promise){
	std::cout << "... entered accumulate" << std::endl;
	int sum = std::accumulate(first, last, 0);
	accumulate_promise.set_value(sum);
	std::cout << "... exiting accumulate" << std::endl;
}

std::vector<int> do_work(std::promise<std::vector<int>> barrier){
	std::cout << "... doing work" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::vector<int> v(10);
	std::generate(v.begin(), v.end(), std::rand);
	barrier.set_value(v);
	std::cout << "... done work" << std::endl;
}

int main(int argc, char ** argv){
	std::vector<int> numbers = { 1,2,3,4, 5, 6 };
	std::promise<int> accumulate_promise;
	std::future<int> accumulate_future = accumulate_promise.get_future();
	std::thread work_thread(accumulate, numbers.begin(), numbers.end(),
		std::move(accumulate_promise));

	std::cout << "... before wait" << std::endl;
	accumulate_future.wait();
	std::cout << "result=" << accumulate_future.get() << '\n';
	work_thread.join();

	std::promise<std::vector<int>> barrier;
	std::future<std::vector<int>> barrier_future = barrier.get_future();
	std::cout << "... before new work" << std::endl;
	std::thread new_work_thread(do_work, std::move(barrier));
	std::cout << "... before barrier" << std::endl;
	barrier_future.wait();
	std::cout << " barrier result = " ; 
	[&barrier_future](){
		std::string s;
		auto intv = barrier_future.get();
		int i = 0;
		for_each(intv.begin(), intv.end(), [&i,&s](auto x){
			if (i++ > 0){
				s.insert(s.length(), " , ");
			}
			s.insert(s.length(), std::to_string(x) );
		 });
		 std::cout << s  << std::endl;
	};

	
		
	new_work_thread.join();
}


