#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> era_sieve(int n) {
    // 埃氏筛，找出从3到 n的所有质数
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n / i; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
int slt(int n) {
    vector<bool> is_prime = era_sieve(n);
    int st = n % 2 ? n - 2 : n - 1;
    for (int i = st; i > 2; i -= 2) {
        if (is_prime[i] && n % i == 0 && is_prime[n / i]) {
            return i;
        }
    }
    return -1;
}
int main() {
    // 只有在本地调试（定义了 LOCAL 宏）时才重定向输入
    // 需要在 tasks.json 的 args 里加上 '-DLOCAL'
    #ifdef LOCAL
        freopen("a0_input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;   
    cout << slt(n);

    return 0;
}