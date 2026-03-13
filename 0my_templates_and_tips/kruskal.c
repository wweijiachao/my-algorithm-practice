#include <stdio.h>
#include <stdlib.h>

#define MAXM 200005
#define MAXN 5005


typedef struct edge {
    int u, v; // 边两端节点
    int len;  // 边长
} Edge;

Edge edges[MAXM];   // 边集
int fa[MAXN];
int rk[MAXN];

int cmp (const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    if(e1->len < e2->len) return -1;
    if(e1->len > e2->len) return 1;
    return 0;
}

void faInit(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        rk[i] = 1;
    }
} 
int find(int i) {
    if (fa[i] == i) return i;
    return fa[i] = find(fa[i]);
}
void mergeByRk(int i, int j) {
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
int linked(int i, int j) {
    return find(i) == find(j);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    faInit(N);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        Edge a = {x, y, z};
        edges[i] = a;
    }
    qsort(edges, M, sizeof(Edge), cmp);

    long long totalSize = 0;
    int treeNodes = 1;  // 生成树里面的节点数量

    for (int i = 0; i < M; i++) {
        Edge a = edges[i];
        if (!linked(a.u, a.v)) {
            mergeByRk(a.u, a.v);
            totalSize += a.len;
            treeNodes++;
        }
    }

    int isLinked = 1;
    int rt = find(1);
    for (int i = 2; i <= N; i++) {
        if (find(i) != rt) {
            isLinked = 0;
            break;
        }
    }

    if (treeNodes != N) printf("orz\n");
    else printf("%lld\n", totalSize);

    return 0;
}