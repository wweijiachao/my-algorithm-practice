#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<string> suffix;
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) {
        suffix.push_back(s.substr(i));
    }
    sort(suffix.begin(), suffix.end());
    for(auto a: suffix) {
        cout << a << endl;
    }

    return 0;
}