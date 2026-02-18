#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int a, int b, vector<int> inputArr)
        : numFloors(n), src(a), dst(b)
        , cnts(n, -1)
    {
        moveFloors = std::move(inputArr);
    }
    void run() {
        bfs();
        cout << cnts[dst];
    }
private:
    int numFloors;
    int src, dst;
    vector<int> cnts;
    vector<int> moveFloors;
    
    void bfs() {
        cnts[src] = 0;
        if (src == dst) return;
        queue<int> que;
        que.push(src);
        while (!que.empty()) {
            int a = que.front();
            que.pop();
            int up = a + moveFloors[a];
            int dn = a - moveFloors[a];
            if (valid(up)) {
                cnts[up] = cnts[a] + 1;
                que.push(up);
            }
            if (valid(dn)) {
                cnts[dn] = cnts[a] + 1;
                que.push(dn);
            }
            if (dn == dst || up == dst) return;
        }
    }
    bool valid(int x) {
        if (x == src) return false;
        if (x < 1 || x > numFloors) {
            return false;
        }
        return cnts[x] == -1;
        // cnt == -1说明还未访问
    }
};

int main() {
    // 只有在本地调试（定义了 LOCAL 宏）时才重定向输入
    // 需要在 tasks.json 的 args 里加上 '-DLOCAL'
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;   
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    Solution slt(n, a, b, std::move(arr));
    slt.run();

    return 0;
}