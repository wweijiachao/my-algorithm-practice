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
    }
    void run() {
        bfs();
        output();
    }
private:
    int rows, cols;
    struct point {
        int x, y;
        point(int _x, int _y):x(_x), y(_y){}
    };
    point start;
    queue<point> que;
    vector<vector<int>> dists;

    void bfs() {
        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[8] = {1,2, 2, 1, -1, -2, -2, -1};
        que.push(start);
        while (!que.empty()) {
            auto cur = que.front();
            int curdist = dists[cur.x][cur.y];
            que.pop();
            for (int i = 0; i < 8; i++) {
                int cx = cur.x + dx[i];
                int cy = cur.y + dy[i];
                if (isOk(cx, cy)) {
                    dists[cx][cy] = curdist + 1;
                    que.push(point(cx, cy));
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
        if (dists[x][y] != -1) {
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