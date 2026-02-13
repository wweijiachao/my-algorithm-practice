#include <iostream>

using namespace std;

int main() {
    // 只有在本地调试（定义了 LOCAL 宏）时才重定向输入
    // 需要在 tasks.json 的 args 里加上 '-DLOCAL'
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    double total = s1 * .2 + s2 * .3 + s3 * .5;
    cout << (int)total;
    

    return 0;
}