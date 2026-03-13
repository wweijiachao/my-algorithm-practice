#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void my_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1;
    int m = l + ((r - l) >> 1);
    int mid_val = arr[m];
    while (i < j) {
        do i++; while (arr[i] < mid_val);
        do j--; while (arr[j] > mid_val);
        if (i < j) std::swap(arr[i], arr[j]);
    }
    my_sort(arr, l, j);
    my_sort(arr, j + 1, r);
}
/*
划分区间不能用i，一定要用j
原因：
	j 永远是安全的：因为 j 是从右往左走的，
	当它停下来时，它脚下踩着的数一定是小于等于 mid_val 的。
	所以从 l 到 j，绝对都是小数字（或者等于基准的数），没有“漏网之大鱼”。

	i 是不安全的： 因为 i 是从左往右走的，
	当它和 j 交叉停下来时，它脚下踩着的数一定是大于等于 mid_val 的。
	如果你用 i 作为左半边的结尾，必定会把一个大数裹挟进左边。
*/
void my_sort(vector<int>& arr) {
    my_sort(arr, 0, arr.size() - 1);
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
        my_sort(arr);
        for (auto a: arr) cout << a << " ";
        cout << '\n';
    }

    return 0;
}
