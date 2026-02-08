#include <iostream>

using namespace std;

class Solution {
public:
    Solution (int *arr, int n) {
        this->arr = arr;
        this->n = n;
        this->cnt = 0;
    }
    int getResult() {
        for(int i = 0; i < n; i++) {
            dfs(i, 0);
        }
        return this->cnt;
    }
private:
    int *arr;
    int n;
    int cnt;
    const int TARGET = 40;

    void dfs(int i, int sum) {
        sum += arr[i];
        if (sum > TARGET) return;
        if (sum == TARGET) {
            cnt++;
            return;
        }
        for (int j = i + 1; j < this->n; j++) {
            dfs(j, sum);
        }
    }

};

int main() {
    int n;
    cin >> n;

    int * arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution slt(arr, n);
    cout << slt.getResult() << endl;

    delete [] arr;
    return 0;
}