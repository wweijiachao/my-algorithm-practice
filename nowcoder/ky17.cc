#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int res = 0;
    for(auto x:a) {
        for(auto y:b) {
            res += (x - '0') * (y - '0');
        }
    }
    cout << res << endl;

    return 0;
}