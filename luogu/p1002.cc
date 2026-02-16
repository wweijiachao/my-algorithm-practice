#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int zx, int zy, int mx, int my): dst({zx, zy}) {
        Map.assign(21, vector<bool>(21, false));
        int dx[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
        int dy[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
        for (int i = 0; i < 9; i++) {
            Map[mx + dx[i]][my + dy[i]] = true;
        }
    }
    void run() {
        dfs();
        cout << cnt << endl;
    }
private:
    struct cord {
        int x, y;
        cord(int _x, int _y): x(_x), y(_y){}
        bool operator==(cord& other) {
            return x == other.x && y == other.y;
        }
        bool operator>(cord& other) {
            return x > other.x || y > other.y;
        }
    };
    cord zu = {0, 0}, dst;
    vector<vector<bool>> Map;
    int cnt = 0;

    void dfs() {
        Map[zu.x][zu.y] = true;
        if(zu == dst) {
            cnt += 1;
            return;
        }
        zu.x++;
        if (valid()) {
            dfs();
        }
        zu.x--;
        zu.y++;
        if (valid()) {
            dfs();
        }
        zu.y--;
    }
    bool valid() {
        if (zu > dst) return false;
        if (Map[zu.x][zu.y]) return false;
        return true;
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

    int dstx, dsty, mx, my;
    cin >> dstx >> dsty >> mx >> my;
    Solution slt(dstx, dsty, mx, my);
    slt.run();
    

    return 0;
}