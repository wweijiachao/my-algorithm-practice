// 13:00 -- 
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution(int h, int w, vector<string> input)
        : height(h), width(w), maze(std::move(input))
        , src(point(-1, -1, 0)), min_time(-1) {}
    
    void run() {
        init();
        bfs();
    }
    int res() {
        return min_time;
    }
private:
    int height, width;
    struct point {
        int x, y;
        int t;
        point(): x(-1), y(-1), t(-1) {}
        explicit point(int t_):x(-1), y(-1), t(t_) {}
        point(int x_, int y_): x(x_), y(y_), t(-1) {}
        point(int x_, int y_, int t_): x(x_), y(y_), t(t_) {}
    };
    vector<string> maze;    
    point src;
    int min_time;

    void init() {
        for (int i = 0; i < height; i++) {
            auto pos = maze[i].find('S');
            if (pos != string::npos) {
                // src = {i, (int)pos};
                src = point(i, (int)pos, 0);
                return;
            }
        }
    }
    bool valid(point p) {
        int x = p.x, y = p.y;
        if (x < 0 || x >= height) return false;
        if (y < 0 || y >= width) return false;
        return maze[x][y] != '#';
    }
    void bfs() {
        const int dx[4] = {0, -1, 0, 1};
        const int dy[4] = {1, 0, -1, 0};
        queue<point> que;
        que.push(src);
        maze[src.x][src.y] = '#';
        // 走过的都设成墙, 省去一个visited数组
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                point p(
                    cur.x + dx[i],
                    cur.y + dy[i],
                    cur.t + 1
                );
                if (valid(p)) {
                    if (maze[p.x][p.y] == 'E') {
                        min_time = p.t;
                        return;
                    }
                    que.push(p);
                    maze[p.x][p.y] = '#';
                }
            }
        }
    }
};
int main() {
    int h, w;
    while (cin >> h >> w) {
        if (h == 0 && w == 0) break;
        vector<string> maze(h);
        for (int i = 0; i < h; i++) {
            cin >> maze[i];
        }
        Solution slt(h, w, std::move(maze));
        slt.run();
        cout << slt.res() << '\n';
    }

    return 0;
}