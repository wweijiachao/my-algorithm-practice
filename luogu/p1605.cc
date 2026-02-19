#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution (int n, int m, int t)
        : length(n), width(m), numObstacles(t) 
        // , maze(length + 1, vector<bool>(width + 1, true))
        // 尽量用传入的参数来初始化，而不是用类成员变量，如果变量声明顺序打乱则可能段错误
        , maze(n + 1, vector<bool>(m+ 1, true))
        // 编号从1开始
    {
    }
    void setSrc (int sx, int sy) {
        src = {sx, sy};
    }
    void setDst (int fx, int fy) {
        dst = {fx, fy};
    }
    void addObsta (int ox, int oy) {
        maze[ox][oy] = false;
    }
    void run() {
        dfs(src);
        cout << cnt << endl;
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int length, width;
    int numObstacles;
    int cnt = 0;
    struct coord {
        int x, y;
        bool operator==(const coord& other) const {
            // 给函数价格const关键字，表示不会修改类成员变量的值
            return x == other.x && y == other.y;
        }
    };
    coord src, dst;
    vector<vector<bool>> maze;

    void dfs(coord c) {
        if (!valid(c)) return;
        if (c == dst) {
            cnt++;
            return;
        }
        maze[c.x][c.y] = false;
        for (int i = 0; i < 4; i++) {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];
            coord next = {nx, ny};
            dfs(next);
        }
        maze[c.x][c.y] = true;
    }
    bool valid(coord c) {
        int x = c.x, y = c.y;
        if (x <=  0 || y <= 0) return false;
        if (x > length || y > width) return false;
        return maze[x][y];
    }

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, m, t;
    int sx, sy, fx, fy;
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    Solution slt(n, m, t);
    slt.setSrc(sx, sy);
    slt.setDst(fx, fy);
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        slt.addObsta(x, y);
    }
    slt.run();

    return 0;
}