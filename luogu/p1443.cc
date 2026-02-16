#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    Solution (int n, int m, int x, int y)
        : rows(n), cols(m)
        , start({x - 1, y - 1})
    {
        dists.assign(rows, vector<int>(cols, -1));
        visited.assign(rows, vector<bool>(cols, false));
    }
    void run() {
        bfs();
        output();
    }
private:
    int rows, cols;
    struct point {
        int x, y;
        int dist = -1;
        point(int _x, int _y):x(_x), y(_y){}
        point(int _x, int _y, int _dist):x(_x), y(_y), dist(_dist){}
    };
    point start;
    queue<point> que;
    vector<vector<bool>> visited;
    vector<vector<int>> dists;

    void bfs() {
        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[8] = {1,2, 2, 1, -1, -2, -2, -1};
        start.dist = 0;
        que.push(start);
        visited[start.x][start.y] = true;
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            dists[cur.x][cur.y] = cur.dist;
            for (int i = 0; i < 8; i++) {
                int cx = cur.x + dx[i];
                int cy = cur.y + dy[i];
                if (isOk(cx, cy)) {
                    visited[cx][cy] = true;
                    que.push(point(cx, cy, cur.dist + 1));
                }
            }
        }
    }
    bool isOk(int x, int y) {
        if (x >= rows || x < 0) {
            return false;
        }
        if (y >= cols || y < 0) {
            return false;
        }
        if (visited[x][y]) {
            return false;
        }
        return true;
    }
    void output() {
        for (auto v: dists) {
            for (auto d: v) {
                cout << d << ' ';
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

    int n, m, x, y;
    cin >> n >> m >> x >> y;   
    Solution slt(n, m, x, y);
    slt.run();
    

    return 0;
}