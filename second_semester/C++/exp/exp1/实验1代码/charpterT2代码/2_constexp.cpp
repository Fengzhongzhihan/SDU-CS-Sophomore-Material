//constexpr 
#include <iostream>
using namespace std;
 constexpr int get_size(){
	return 20;
} 

int main() {
	constexpr int size = get_size(); 
	int j;
	cout << "Hello! " <<size<< endl;
	cout << "Welcome to C++! " << endl;
	return 0;
}
 
