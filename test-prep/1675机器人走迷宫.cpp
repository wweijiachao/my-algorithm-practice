#include <cctype>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;


int main() {
    int w, h;
    vector<string> maze;
    maze.reserve(11);
    // 上右下左
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    int src[2];
    while (cin >> w >> h) {
        maze.assign(w, "");
        char op;
        for (int i = 0; i < w; i++) {
            cin >> maze[i];
            for (int j = 0; j < h; j++) {
                if (std::isupper(maze[i][j])) {
                    src[0] = i, src[1] = j;
                    op = maze[i][j];
                    break;
                }
            }
        }
        // start
        bool canTurn = true;
        int i = -1;
        if (op == 'U') i = 0;
        else if (op == 'R') i = 1;
        else if (op == 'D') i = 2;
        else i = 3;

        int cnt = 1;
        while (true) {
            int x = src[0] + dx[i];
            int y = src[1] + dy[i];
            if (x >= 0 && x < w && y >= 0 && y < h && maze[x][y] == '.') {
                // 可以走
                maze[x][y] = '*';
                src[0] = x, src[1] = y;
                cnt++;
                canTurn = true;
            } else {
                // 走不了，要转弯
                if (canTurn) {
                    i = (i + 1) % 4;
                    canTurn = false;
                } else break;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}