#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int m) {
        nums = n, querys = m;
        arr.resize(nums);
    }
    void run() {
        input();
        query();
    }
private:
    int nums, querys;
    vector<int> arr;
    int loc = -1;

    void input() {
        for(int i = 0; i < nums; i++) {
            cin >> arr[i];
        }
    }
    void query() {
        for(int i = 0; i < querys; i++) {
            int tar;
            cin >> tar;
            if (binSearch(tar)) cout << loc + 1 << " ";
            else cout << "-1 ";
        }
        
    }
    bool binSearch(int tar) {
        int l = 0, r = nums - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if(arr[mid] >= tar) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(arr[l] == tar) {
            loc = l;
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    Solution slt(n, m);
    slt.run();

    return 0;
}