#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    Solution (int n)
        : cols(n)
        , mat(n + 2, vector<int>(n + 2, 2)){}
    // 给方阵外面围一圈
    void run() {
        bfs();
        output();
    }
    void setMat(int i, int j) {
        mat[i + 1][j + 1] = 1;
    }
private:
    int cols;
    vector<vector<int>> mat;
    using pii = pair<int, int>;

    void bfs() {
        queue<pii> que;
        que.push(make_pair(0, 0));
        mat[0][0] = 0;
        while (!que.empty()) {
            auto x = que.front().first;
            auto y = que.front().second;
            que.pop();
            
            // 将外围全变成0，内部依然是2
            int dx[4] = {0, -1, 0, 1};
            int dy[4] = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (isOk(nx, ny)) {
                    que.push(make_pair(nx, ny));
                    mat[nx][ny] = 0;
                }
            }
        }
    }
    bool isOk(int x, int y) {
        if (x < 0 || y < 0) return false;
        if (x >= cols + 2 || y >= cols + 2) return false;
        if (mat[x][y] != 2) return false;   // 不是墙
        return true;
    }
    void output() {
        for (int i = 1; i <= cols; i++ ) {
            for (int j = 1; j <= cols; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
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

    int n;
    cin >> n;
    Solution slt(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val == 1) slt.setMat(i, j);
        }
    }
    slt.run();

    return 0;
}