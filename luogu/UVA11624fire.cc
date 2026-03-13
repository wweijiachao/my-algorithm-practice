#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

struct point {
    int x, y;   // 坐标
    int t;  
    point(int x_, int y_, int t_): x(x_), y(y_), t(t_) {}
    point(): x(-1), y(-1), t(-1) {}
};

int r, c;
const int Inf = 0x3f3f3f3f;
const int MAXN = 1005;

vector<string> maze;
int fire_time[MAXN][MAXN];

queue<point> step;
queue<point> fire;

void bfs() {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    // 先对火进行bfs
    while (!fire.empty()) {
        auto a = fire.front();
        fire.pop();
        for (int i = 0; i < 4; i++) {
            const int x = a.x + dx[i], y = a.y + dy[i];
            if (x >= 0 && x < r && y >= 0 && y < c && (fire_time[x][y] == Inf) && (maze[x][y] == '.' || maze[x][y] == 'J')) {
                fire.push(point(x, y, a.t + 1));
                fire_time[x][y] = a.t + 1;
            }
        }
    }
    // 对人进行bfs
    while (!step.empty()) {
        auto a = step.front();
        step.pop();
        for (int i = 0; i < 4; i++) {
            const int x = a.x + dx[i], y = a.y + dy[i];
            if (x >= 0 && x < r && y >= 0 && y < c && (fire_time[x][y] > a.t + 1) && (maze[x][y] == '.')) {
                if (x == r - 1 || y == c - 1) {
                    // 逃脱
                    cout << a.t + 2 << '\n';
                    return;
                }
                step.push(point(x, y, a.t + 1));
                maze[x][y] = ',';   // 标记已经走过
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> r >> c;
        maze.resize(r);
        memset(fire_time, 0x3f, sizeof(fire_time));
        step = queue<point>();
        fire = queue<point>();
        for (int i = 0; i < r; i++) {
            // 输入和初始化
            cin >> maze[i];
            for (int j = 0; j < c; j++) {
                const char ch = maze[i][j];
                if (ch == 'J') {
                    step.push(point(i, j, 0)); 
                } else if (ch == 'F') {
                    fire.push(point(i, j, 0));
                    fire_time[i][j] = 0;
                }
            }
        }
        bfs();
    }

    return 0;
}