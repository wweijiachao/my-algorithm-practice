#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int i, j;   // 两点的编号 
    double len; // 边长
    bool operator<(const edge& other) const {
        return len < other.len;
    }
};
class Solution {
public:
    Solution(int n) {
        point_nums = n;
        points.resize(n);
        unionSet.resize(n);
        for (int i = 0; i < n; i++) {
            unionSet[i] = i;
        }
        resultDistant = 0;
    }
    void run() {
        inputCoord();
        calculateEdge();
        kruskal();
    }
    double returnResult() {
        return resultDistant;
    }
private:
    using pdd = pair<double, double>;

    int point_nums;
    vector<pdd> points;
    vector<edge> edges;
    vector<int> unionSet;
    double resultDistant;

    // TODO 输入各点的坐标
    void inputCoord() {
        for (int i = 0; i < point_nums; i++) {
            cin >> points[i].first >> points[i].second;
        }
    }
    // 计算边
    void calculateEdge() {
        for (int i = 0; i < point_nums; i++) {
            for (int j = i + 1; j < point_nums; j++) {
                auto p = [this](int a, int b){
                    double dx = points[a].first - points[b].first;
                    double dy = points[a].second- points[b].second;
                    return sqrt(dx * dx + dy * dy);
                };
                edges.push_back({i, j, p(i, j)});
            }
        }
    }
    // TODO 克鲁斯卡尔算法
    void kruskal() {
        sort(edges.begin(), edges.end());
        for (auto& a : edges) {
            int i = a.i, j = a.j;
            if (find(i) != find(j)) {
                // 边的两点不在一个连通图内, 加入最小生成树
                resultDistant += a.len;
                merge(i, j);
            }
        }
    }
    // 并查集实现
    int  find(int i) {
        return unionSet[i] == i ? i : unionSet[i] = find(unionSet[i]);
    }
    void merge(int i, int j) {
        // 把 i 合并到 j 所在集合
        int bi = find(i), bj = find(j);
        if (bi == bj) return;
        unionSet[bi] = bj;
    }
};

int main() {
    int n;
    cin >> n;
    Solution slt(n);
    slt.run();
    printf("%.2f\n", slt.returnResult());

    return 0;
}