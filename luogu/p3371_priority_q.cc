#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int m, int s) {
        INF = 0x3f3f3f3f;
        vNum = n, eNum = m, start = s;
        minRoadLen.resize(vNum + 1, INF);
        visited.resize(vNum + 1, false);
        adjList.resize(vNum + 1);
        minRoadLen[start] = 0;
    }
    void run() {
        input();
        djkstra();
        output();
    }
private:
    struct arc {
        int dst, len;
    };
    using pii = pair<int, int>;
    int INF; // 2^31-1
    int vNum, eNum, start;
    vector<int> minRoadLen; // 记录源点到每个节点的最短路长度
    vector<bool> visited;   // 记录哪些节点已经确定最短路
    vector<vector<arc>> adjList;    // 邻接表存图
    priority_queue<pii, vector<pii>, greater<pii>> dists; // first=len, second=id

    void input() {
        for (int i = 0; i < eNum; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            // edge: a->b, len=c
            adjList[a].push_back({b, c});
        }
    }
    void djkstra() {
        dists.push({0, start});
        while (!dists.empty()) {
            auto a = dists.top();
            dists.pop();
            if (visited[a.second]) continue;
            int len = a.first, id = a.second;
            visited[id] = true;
            for (auto a: adjList[id]) {
                if (!visited[a.dst] &&  len + a.len < minRoadLen[a.dst]) {
                    minRoadLen[a.dst] = len + a.len;
                    dists.push({minRoadLen[a.dst], a.dst});
                }
            }
        }

    }
    void output() {
        for (int i = 1; i <= vNum; i++) {
            if (minRoadLen[i] == INF) minRoadLen[i] = 0x7fffffff;
            cout << minRoadLen[i] << ' ';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;
    Solution slt(n, m, s);
    slt.run();
    

    return 0;
}