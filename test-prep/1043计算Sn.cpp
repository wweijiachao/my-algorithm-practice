#include <iostream>

using namespace std;

int main() {
    int a, n;
    cin >> a >> n;

    int res = 0;
    while (n > 0) {
        res += a * n;
        n--;
        a *= 10;
    }
    cout << res << endl;

    return 0;
}