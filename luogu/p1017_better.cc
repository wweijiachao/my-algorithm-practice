#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int r)
        :val(n), base(r) {}
        
    void run() {
        calculate();
        output();
    }
private:
    int val;
    int base;

    string res;

    void calculate() {
        if (val == 0) {
            res = "0";
            return;
        }
        int n = val;
        int remain = 0;
        while (n != 0) {
            remain = n % base;
            n /= base;
            if (remain < 0) {
                remain -= base;
                n++;
            }
            res += remain > 9 ? 'A' + remain - 10 : '0' + remain;
        }
        reverse(res.begin(), res.end());
    }
    void output() {
        cout << val << "=";
        cout << res;
        cout << "(base" << base << ")" << endl;
    }
};
int main() {
    int n, r;
    cin >> n >> r;

    Solution slt(n, r);
    slt.run();

    return 0;
}