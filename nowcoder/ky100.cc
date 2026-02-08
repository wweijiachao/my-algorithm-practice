#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string pAdd(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, t = 0;
    string res = "";

    while (i >= 0 || j >= 0 || t) {
        if (i >= 0) t += a[i--] - '0';
        if (j >= 0) t += b[j--] - '0';
        res += (t % 10) + '0';
        t /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string pMinus(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, t = 0;
    string res = "";
    while (i >= 0 || j >= 0 || t) {
        if (i >= 0) t += a[i] - '0';
        if (j >= 0) t -= b[i] - '0';
        if (t < 0) {
            res += (t + 10) % 10 + '0';
            t = -1;
        } else {
            res += t + '0';
            t = 0;
        }
    }
    return res;
}
int main() {
    cout << -3 / 10;
    return 0;
}