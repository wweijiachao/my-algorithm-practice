#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        res1.emplace_back(score(0, 0));
        res2.emplace_back(score(0, 0));
    }
    void runCh(char ch) {
        getCh(ch);
    }
    void output() {
        for (int i = 0; i < res1.size(); i++) {
            cout << res1[i].a << ':' << res1[i].b << endl;
        }
        cout << endl;
        for (int i = 0; i < res2.size(); i++) {
            cout << res2[i].a << ':' << res2[i].b << endl;
        }
    }
private:
    struct score {
        int a, b;
        score(int _a, int _b): a(_a), b(_b){}
        bool dif() {
            return a - b >= 2 || b - a >= 2;
        }
        bool gameOver1() {
            if ((a >= 11 || b >= 11) && dif()) {
                return true;
            }
            return false;
        }
        bool gameOver2() {
            if ((a >= 21 || b >= 21) && dif()) {
                return true;
            }
            return false;
        }
    };
    vector<score> res1, res2;
    bool gameOver1 = false, gameOver2 = false;
    void getCh(char ch) {
        if (ch == 'W') {
            // 华华得一分
            res1.back().a++;
            res2.back().a++;
        } else {
            // 对手得一分
            res1.back().b++;
            res2.back().b++;
        }
        judge();
        adjust();
    }
    void judge() {
        // 判断是否一局结束
        if (res1.back().gameOver1()) {
            gameOver1 = true;
        }
        if (res2.back().gameOver2()) {
            gameOver2 = true;
        }
    }
    void adjust() {
        if (gameOver1) {
            res1.emplace_back(score(0, 0));
            gameOver1 = false;
        }
        if (gameOver2) {
            res2.emplace_back(score(0, 0));
            gameOver2 = false;
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

    Solution slt;
    string str;
    bool over = false;
    while (cin >> str) {
        if (over) break;
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] == 'E') {
                over = true;
                break;
            }
            slt.runCh(str[i]);
        }
    }
    slt.output();

    return 0;
}