#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << -5 % 2;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
        if (a % 2 == 1 && b % 2 == 0) return true;
        if (a % 2 == 0 && b % 2 == 1) return false;
        return a < b;
    });
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}