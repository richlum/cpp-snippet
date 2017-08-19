#include <iostream>

int& setit(int& x){
	return x;
}
// take reference of parameter and return ref to paramter....
// since we return a ref to a var, we apparently can assign to it.

int main(int argc, char **argv){
	int a = 9;
	int &lref = a;
	int &&rref = 8;
	//int &&rref = a;  // illegal, rhv cannot be assign lhv
	//int &&rref2 = &(setit(a));   // unsure how to assign 
	std::cout << a << " , " << lref << " , " << rref << std::endl;
	if (lref == rref + 1)
		std::cout << "Equals";
	else
		std::cout << "Not Equals";
	std::cout << std::endl;
	std::cout << "can change rref if non const ";
	rref = 13;
	std::cout << rref << " " <<  (rref == 13 ? "yes" : "no") << std::endl; 


	int y;
	setit(y) = 3;		// set a value by return ref 
	std::cout << y << std::endl;  
	std::cout << setit(y) << std::endl;  // oddly ret of a ref to an int still yields int for output - output auto type coercion ?
	std::cout << (setit(y) = 5) << std::endl; 

}
