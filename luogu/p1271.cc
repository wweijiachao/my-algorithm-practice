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
    Solution slt;
    slt.run();
    slt.output();

    return 0;
}