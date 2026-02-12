#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        cin >> n >> m;
        arr.resize(m);
    }
    void run() {
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
    }
    void output() {
        for (auto a : arr) {
            cout << a << " ";
        }

    }
private:
    int m, n;
    vector<int> arr;
};

int main() {
    // 只有在本地调试（定义了 LOCAL 宏）时才重定向输入
    // 需要在 tasks.json 的 args 里加上 "-DLOCAL"
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    Solution slt;
    slt.run();
    slt.output();

    return 0;
}