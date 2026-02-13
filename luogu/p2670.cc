#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int m): rows(n), cols(m) {
        mine.assign(rows, vector<int>(cols, 0));
        mineMap.assign(rows, "");
        init();
        output();
    }
private:
    int rows, cols;
    vector<vector<int>> mine;
    vector<string> mineMap;

    void init() {
        for (int i = 0; i < rows; i++) {
            string s;
            cin >> s;
            mineMap[i] = s;
            for (int j = 0; j < cols; j++) {
                if (s[j] == '*') {
                    calMines(i, j);
                }
            }
        }
    }
    void calMines(int r, int c) {
        int dx[8] = {-1, 0, 1, -1, 1, -1 ,0, 1};
        int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for (int i = 0; i <8; i++) {
            int r2 = r + dx[i];
            int c2 = c + dy[i];
            bool rAvail = r2 >= 0 && r2 < rows;
            bool cAvail = c2 >= 0 && c2 < cols;
            if (rAvail && cAvail) {
                mine[r2][c2] += 1;
            }
        }
    }
    void output() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mineMap[i][j] == '*') cout << '*';
                else cout << mine[i][j];
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
    
    int n, m;
    cin >> n >> m;
    Solution slt(n, m);

    return 0;
}