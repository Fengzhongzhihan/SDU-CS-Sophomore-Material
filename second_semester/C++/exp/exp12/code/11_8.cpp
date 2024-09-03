//11_8.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	// string line;
	// cout << "Type a line terminated by 't' " << endl;
	// getline(cin, line, 't');
	// cout << line << endl;
	string line;
    char ch;
    cout << "Type a line terminated by 't' " << endl;
    
    // Read characters one by one until 't' is encountered
    while (cin.get(ch) && ch != 't') {
        line += ch;
    }
    
    // Output the collected line
    cout << line << endl;
	return 0;
}
