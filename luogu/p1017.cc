#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int r)
        : srcVal(n), dstBase(r), dstArr(25, -1) {}
    void run() {
        init();
        for (int i = -dstBase - 1; i >= 0; i--) {
            if (ok) break;
            dfs(0, i);
        }
        output();
    }
private:
    int srcVal;     // 初始十进制数
    int dstBase;    // 负进制

    vector<int> dstArr;    // 最终结果
    vector<int> nthVal;    // r进制第n位的值
    int nthValSize;
    int curVal = 0;     // 当前值
    bool ok = false;

    void init() {
        int x = 1;
        for (int i = 0; x < 37336 * 2; i++) {
            nthVal.emplace_back(x);
            x *= dstBase;
        }
        nthValSize = nthVal.size();
    }
    bool outrange(int cur, int n) {
        if (n > 16) return false;
        if (srcVal > 0 && cur > srcVal) return true;
        if (srcVal < 0 && cur < srcVal) return true;
        return false;
    }
    void dfs(int n, int i) {
        if (n >= nthValSize) return;
        dstArr[n] = i;
        curVal += nthVal[n] * i;
        if (curVal == srcVal) {
            ok = true;
            return;
        } else if (!outrange(curVal, n + 1)) {
            for (int j = -dstBase - 1; j >= 0; j--) {
                // 从大到小，防止无限循环
                if (ok) return; // 如果已找到结果，就直接停止
                dfs(n + 1, j);  // 找下一层
            }
        }
        curVal -= nthVal[n] * i;
    }
    void output() {
        cout << srcVal << "=";
        int i = dstArr.size() - 1;
        while (dstArr[i] == -1) i--;
        while (dstArr[i] == 0) i--; // 去除前导0
        for (; i >= 0; i--) {
            int a = dstArr[i];
            char ch = a < 10 ? '0' + a : 'A' - 10 + a;
            cout << ch;
        }
        cout << "(base" << dstBase << ")\n";
    }

};

int main() {
    #ifdef LOCAL
        freopen("a0_input.txt", "r", stdin);
    #endif
    int n, r;
    cin >> n >> r;
    Solution slt(n, r);
    slt.run();
    
    return 0;
}