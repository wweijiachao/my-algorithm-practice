#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution(int _h, int _r): h(_h / 10.0), r(_r / 10.0) {
        run();
    }
private:
    const double PI = 3.14;
    double h, r;
    void run() {
        double v = PI * r * r * h;
        int n = ceil(20.0 / v);
        cout << n;
    }
};

int main() {
    // 只有在本地调试（定义了 LOCAL 宏）时才重定向输入
    // 需要在 tasks.json 的 args 里加上 '-DLOCAL'
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, r;
    cin >> h >> r;
    Solution slt(h, r);

    return 0;
}