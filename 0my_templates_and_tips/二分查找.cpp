#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 递归 recursion
bool bin_find_recursion(const vector<int>& arr, const int l, const int r, const int target) {
    if (l > r) return false;
    // int mid = (l + r) >> 1;
    int m = l + ((r - l) >> 1);
    int mid = arr[m];
    if (mid == target) return true;
    if (mid > target) return bin_find_recursion(arr, l, m - 1, target);
    return bin_find_recursion(arr, m + 1, r, target);
}
// 迭代 iteration
bool bin_find_iteration(const vector<int>& arr, int l, int r, const int target) {
    if (l > r) return false;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        int mid = arr[m];
        if (mid == target) return true;
        else if (mid > target) r = m - 1;
        else l = m + 1;
    }
    return false;
}
// stl
bool find_stl(const vector<int>& arr, const int target) {
    return binary_search(arr.begin(), arr.end(), target);
}

// 查找下界(第一个target)
int find_lower_bound(const vector<int>& arr, int target) {
    if (arr.empty()) return -1;
    int l = 0, r = arr.size() - 1;
    int m = 0;
    while (l < r) {
        m = l + ((r - l) >> 1);
        int mid_val = arr[m];
        if (mid_val >= target) r = m;
        else l = m + 1;
    }
    return arr[r] == target ? r : -1;
}
// 上界（最后一个target）
int find_upper_bound(const vector<int>& arr, int target) {
    if (arr.empty()) return -1;
    int l = 0, r = arr.size() - 1;
    int m = 0;
    while (l < r) {
        m = l + ((r - l + 1) >> 1);
        int mid_val = arr[m];
        if (mid_val <= target) l = m;
        else r = m - 1;
    }
    return arr[r] == target ? r : -1;
}

bool find_(const vector<int>& arr, const int target) {
    if (arr.empty()) return false;
    return bin_find_iteration(arr, 0, arr.size() - 1, target);
}
int main() {
    int n;
    vector<int> arr(105);

    while (cin >> n) {
        arr.clear();
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int target;
            cin >> target;
            if (find_(arr, target)) {
                cout << "YES\n";
            } else cout << "NO\n";
        }
    }

    return 0;
}
