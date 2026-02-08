#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int m) {
        elemNum = n, opNum = m;
        unionSet.resize(elemNum + 1);
        for (int i = 0; i <= elemNum; i++) {
            unionSet[i] = i;
        }
    }
    void opreations() {
        for (int a = 0; a < opNum; a++) {
            int z, x, y;
            cin >> z >> x >> y;
            if(z == 1) merge(x, y);
            else {
                if (find(x) == find(y)) cout << "Y\n";
                else cout << "N\n";
            }
        }
    }
private:
    int elemNum, opNum;
    vector<int> unionSet;

    int find(int i) {
        return unionSet[i] == i ? i : unionSet[i] = find(unionSet[i]);
    }
    void merge(int i, int j) {
        int bi = find(i), bj = find(j);
        if (bi == bj) return;
        unionSet[bi] = bj;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    Solution slt(n, m);
    slt.opreations();

    return 0;
}