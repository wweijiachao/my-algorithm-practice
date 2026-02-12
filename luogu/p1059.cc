#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n): num(n) {
        arr.assign(num, 0);
        init();
        run();
    }
private:
    int num;
    vector<int> arr;

    void init() {
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
        }
    }
    void run() {
        sort(arr.begin(), arr.end());
    }
    void output() {
        for (auto a: arr) {
            cout << a << ' ';
        }
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

    int n;
    cin >> n;
    Solution slt(n);

    return 0;
}