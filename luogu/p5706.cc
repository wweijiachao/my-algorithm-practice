#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 只有在本地调试（定义了 LOCAL 宏）时才重定向输入
    // 需要在 tasks.json 的 args 里加上 '-DLOCAL'
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double t;
    int n;
    cin >> t >> n;
    printf("%.3f\n%d", t / n, n * 2);
    

    return 0;
}