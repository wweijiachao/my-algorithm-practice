#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution(int _a, int _b): yuan(_a), jiao(_b) {
        run();
    }
private:
    int yuan, jiao;
    void run() {
        int total = 10 * yuan + jiao;
        int num = floor(total * 1.0 / 19);
        cout << num;
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

    int a, b;
    cin >> a >> b;
    Solution slt(a, b);

    return 0;
}