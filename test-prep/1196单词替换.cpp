#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ws;
int main() {
	string line;
	while (getline(cin >> ws, line)) {
        string org, dst;
        cin >> org >> dst;
        istringstream ss(line);
        string s;
        bool first = true;
        while (ss >> ws >> s) {
            if (!first) {
                cout << " ";
            }
            if (s == org) cout << dst;
            else cout << s;
            first = false;
        }
        cout << '\n';
    }
	
	return 0;
}