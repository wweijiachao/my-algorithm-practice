/*
** 多源bfs **
题目：烈火逃生 (Fire Maze)
题目描述：
小 A 被困在一个迷宫中，起点为 S，出口为 E（出口只有一个）。迷宫中有一些不可逾越的墙壁 #，以及平地 .。
不幸的是，迷宫中同时存在多个火源 F。

火势每秒会向上下左右四个方向的相邻平地蔓延一格（火无法穿过墙壁，也无法烧毁出口 E）。

小 A 每秒可以向上下左右移动一格。

致命条件： 如果某个格子在小 A 到达的同一秒（或更早）已经被火烧到，那么小 A 绝对不能走这个格子。

请问小 A 能否活着走到出口 E？如果能，输出最短需要的时间；如果无论如何都会被烧死或被困住，输出 Impossible。

输入描述：
第一行输入两个正整数 R 和 C（1 <= R, C <= 1000），表示迷宫的行数和列数。
接下来 R 行，每行 C 个字符。
（保证迷宫中必定有一个 S 和一个 E，可能包含 0 个或多个 F）。

输出描述：
输出一个整数，表示最短逃生时间。如果无法逃生，输出字符串 Impossible。
*/
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
            if (x >= 0 && x < r && y >= 0 && y < c && (fire_time[x][y] == Inf) && (maze[x][y] == '.' || maze[x][y] == 'S')) {
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
            if (x >= 0 && x < r && y >= 0 && y < c && (fire_time[x][y] > a.t + 1) && (maze[x][y] == '.' || maze[x][y] == 'E')) {
                if (maze[x][y] == 'E') {
                    // 逃脱
                    cout << a.t + 1 << '\n';
                    return;
                }
                step.push(point(x, y, a.t + 1));
                maze[x][y] = ',';   // 标记已经走过
            }
        }
    }
    cout << "Impossible\n";
}

int main() {
    while (cin >> r >> c) {
        if (r == 0 && c == 0) break;
        maze.resize(r);
        memset(fire_time, 0x3f, sizeof(fire_time));
        step = queue<point>();
        fire = queue<point>();
        for (int i = 0; i < r; i++) {
            // 输入和初始化
            cin >> maze[i];
            for (int j = 0; j < c; j++) {
                const char ch = maze[i][j];
                if (ch == 'S') {
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