#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        run();
    }
private:
    int h1, h2, m1, m2;
    void run() {
        cin >> h1 >> m1 >> h2 >> m2;
        int dh = h2 - h1;
        int dm = m2 - m1;
        if (dm < 0) {
            dh -= 1;
            dm += 60;
        }
        cout << dh << " " << dm;
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

    Solution slt;   

    return 0;
}