// 查找一个数组的第K小的数，注意同样大小算一样大。 
// 如  2 1 3 4 5 2 第三小数为3。
/*
 * std::unique 的用法 line:24
 * 原理: 快慢指针
------------------------------------
if (v.empty()) return 0; // 拦截空数组
int j = 0; // 慢指针
for (int i = 1; i < v.size(); i++) { // 快指针从 1 开始跑
    if (v[i] != v[j]) {
        v[++j] = v[i]; // 先挪位置，再坐下去，一步到位
    }
}
return j + 1; // 返回有效长度
------------------------------------
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> arr(1005);
    while (cin >> n) {
        arr.clear();
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        // std::unique() 去重，并将重复元素移到容器最后
        // (只查找相邻的, 需要先排序)
        // 返回值就是去重后有效容器的end() <最后一位+1>
        auto it = unique(arr.begin(), arr.end());
        arr.erase(it, arr.end());
        int k;
        cin >> k;
        cout << arr[k - 1] << '\n';
    }
    return 0;
}
