#include <iostream>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int len = str.size();
        int dec = 0;
        for(int i = 0; i < len; i++) {
            int mm = len - i - 1;
            dec += (str[i] - '0') * ((2 << mm) - 1);
        }
        cout << dec << endl;
    }
    return 0;
}