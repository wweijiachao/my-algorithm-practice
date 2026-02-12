#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

struct edge {
    int i, j;   // 边上的两个点
    int len;    // 边长
    bool operator<(const edge& other) {
        return len < other.len;
    }
};
class Solution {
public:
    Solution(int n, int m) {
        vNums = n, eNums = m;
        connected = false;
        edgeLen = 0;
        edges.resize(eNums);
        unionSet.resize(vNums + 1);
        iota(unionSet.begin(), unionSet.end(), 0);
    }
    void run() {
        inputEdges();
        kruskal();
        if(connected) {
            cout << edgeLen << endl;
        } else {
            cout << "orz" << endl;
        }
    }
    
private:
    int vNums, eNums;
    vector<edge> edges;
    vector<int> unionSet;
    int edgeLen;
    bool connected;

    void inputEdges() {
        for (int i = 0; i < eNums; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges[i].i = x, edges[i].j = y, edges[i].len = z;
        }
    }
    void kruskal() {
        sort(edges.begin(), edges.end());
        int num = vNums;
        for (auto& a : edges) {
            int i = a.i, j = a.j;
            if (!sameSet(i, j)) {
                // 不连通，加入mst
                edgeLen += a.len;
                merge(i, j);
                num--;
            }
        }
        if (num == 1) connected = true;
    }
    // 并查集
    int find (int i) {
        return unionSet[i] == i ? i : unionSet[i] = find(unionSet[i]);
    }
    bool sameSet(int i, int j) {
        return find(i) == find(j);
    }
    void merge(int i, int j) {
        int bi = find(i), bj = find(j);
        if (bi != bj) {
            unionSet[bi] = bj;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;   
    cin >> n >> m;
    Solution slt(n, m);
    slt.run();

    return 0;
}