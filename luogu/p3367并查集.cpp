#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 2e5 + 10; 

int fa[MAXN];
int rank[MAXN];

void init(int n) {
    // 初始化，各个节点的 fa 是自己，rank(高度)是 1
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        rank[i] = 1;
    }
}
int find(int i) {
    // 查找并压缩
    if (fa[i] == i) return i;
    return fa[i] = find(fa[i]);
}
void merge(int i, int j)  {
    // i 合并到 j 中
    int bi = find(i);
    int bj = find(j);
    if (bi != bj) {
        // 按秩合并, 矮的合并到高的
        if (rank[bi] < rank[bj]) {
            fa[bi] = bj;
        } else if (rank[bi] > rank[bj]) {
            fa[bj] = bi;
        } else {
            // 一样高, 随便合并, 但是根的 rank ++
            fa[bj] = bi;
            rank[bi]++;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            merge(x, y);
        } else {
            if (find(x) == find(y)) {
                cout << "Y\n";
            } else cout << "N\n";
        }
    }

    return 0;
}