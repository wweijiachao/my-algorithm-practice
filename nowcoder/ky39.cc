#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    Solution (int num) {
        // 初始化点的个数
        this->point_nums = num;
        // 初始化并查集
        unionSet.resize(point_nums); 
        for (int i = 0; i < point_nums; i++) {
            unionSet[i] = i;
        }
        // 输入点的数据
        inputPoints();
        // 计算距离，完成邻接表
        calculateDistance();
        // 完成最小生成树，克鲁斯卡尔算法
        minTree();
    }
    double result() {
        return resDist;
    }
private:
    using pdd = pair<double, double>;
    using point = pair<pdd, vector<double>>;
    int point_nums;
    vector<point> adjList;
    vector<int> unionSet;
    double resDist;

    // 输入点
    void inputPoints() {
        adjList.resize(point_nums);
        for (int i = 0; i < point_nums; i++) {
            double a, b;
            cin >> a >> b;
            adjList[i].first.first = a;
            adjList[i].first.second = b;
            adjList[i].second.resize(point_nums);
        }
    }
    // 计算点之间的距离
    void calculateDistance() {
        for (int i = 0; i < point_nums; i++) {
            for (int j = 0; j < point_nums; j++) {
                adjList[i].second[j] = dist(adjList[i].first, adjList[j].first);
            }
        }
    }
    // 计算传入的两点间距离
    double dist(pdd p1, pdd p2) {
        double dx = p1.first - p2.first;
        double dy = p1.second - p2.second;
        return sqrt(dx * dx + dy * dy);
    } 
    // 求最小生成树 
    void minTree() {
        resDist = 0; // 最终距离
        int i = 0, j = 0;
        while(true) {
            double tmpDist = 0;
            // 找一轮最小距离
            for(int m = 0; m < point_nums; m++) {
                for (int n = 0; n < point_nums; n++) {
                    double curDist = adjList[m].second[n];
                    if (curDist == 0) continue; // 该边不存在
                    if(tmpDist == 0 || curDist < tmpDist) {
                        tmpDist = curDist;
                        i = m, j = n;
                    }
                }
            }
            if(tmpDist == 0) break; // 所有边已经找完了
            if(findBoss(i) != findBoss(j)) { // i和j不连通
                resDist += tmpDist; // 最小生成树加上一条边
                merge(i, j);
            }
            adjList[i].second[j] = 0;   // 删除该边
            adjList[j].second[i] = 0;   // 删除对应另一向边

        }
    }
    // 并查集的合并, 将 i 合并到 j 的集合 
    void merge(int i, int j) {
        int bossI = findBoss(i);
        int bossJ = findBoss(j);
        if(bossI != bossJ) {
            unionSet[bossI] = bossJ;
        }
    }
    // 寻找元素在并查集中的代表
    int findBoss(int i) {
        return unionSet[i] == i ? i : unionSet[i] = findBoss(unionSet[i]);
    }
};

int main() {
    int n;
    cin >> n;
    Solution slt(n);
    printf("%.2f\n", slt.result());

    return 0;
}