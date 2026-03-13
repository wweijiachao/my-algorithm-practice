#include <stdio.h>
#include <string.h>
#define MAXN 105


char maze[MAXN][MAXN];
int fa[MAXN * MAXN];
int rk[MAXN * MAXN];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    memset(rk, 0, n);
}
int find(int i) {
    if (fa[i] == i) return i;
    return fa[i] = find(fa[i]);
}
void mergByRk(int i, int j) {
    int bi = find(i);
    int bj = find(j);
    if (bi != bj) {
        if (rk[bi] < rk[bj]) {
            fa[bi] = bj;
        } else if (rk[bi] > rk[bj]) {
            fa[bj] = bi;
        } else {
            fa[bj] = bi;
            rk[bi]++;
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        init(n * m + 10);
        for (int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; i < m; j++) {
                if (maze[i][j] == )
            }
        }
    }


    return 0;
}