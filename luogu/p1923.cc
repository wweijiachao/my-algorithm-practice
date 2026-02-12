#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int _n, int _k) {
        n = _n, k = _k;
    }
    void run() {
        input();
        kSmall(0, n - 1);
    }
    int returnRes() {
        return result;
    }
private:
    int n, k;
    vector<int> arr;
    int result;
    void input() {
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    void kSmall(int l, int r) {
        if(l >= r) {
            if (l == k) result = arr[k];
            return;
        }
        // 快速选择
        int i = l - 1, j = r + 1;
        int mid = arr[(l + r) >> 1];
        while(i < j) {
            do i++; while (arr[i] < mid);
            do j--; while (arr[j] > mid);
            if (i < j) swap(arr[i], arr[j]);
        }
        if(k <= j) {
            // 第k个在左边
            kSmall(l, j);
        } else {
            kSmall(j + 1, r);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    Solution slt(n, k);
    slt.run();
    cout << slt.returnRes();

    return 0;
}