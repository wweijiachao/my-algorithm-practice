#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int m, int s) {
        INF = 0x3fffffff;
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
    int INF; // 2^31-1
    int vNum, eNum, start;
    vector<int> minRoadLen; // 记录源点到每个节点的最短路长度
    vector<bool> visited;   // 记录哪些节点已经确定最短路
    vector<vector<arc>> adjList;    // 邻接表存图

    void input() {
        for (int i = 0; i < eNum; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            // edge: a->b, len=c
            adjList[a].push_back({b, c});
            // if (a == start) {
            //     // 存起点到各个点的初始边
            //     minRoadLen[b] = c < minRoadLen[b] ? c : minRoadLen[b];
            // }
        }
    }
    void djkstra() {
        int curr = start;
        // 找n-1轮, 每轮找到一个最小值
        for (int k = 1; k <= vNum; k++) {
            // 选一个路径最短的点，作为前驱点
            int minLen = INF;
            for (int i = 1; i <= vNum; i++) {
                if(!visited[i] && minRoadLen[i] < minLen) {
                    minLen = minRoadLen[i];
                    curr = i;
                }
            }
            if (minLen == INF) break;
            visited[curr] = true;
            for (auto a : adjList[curr]) {
                if (visited[a.dst]) continue;
                int newLen = a.len + minRoadLen[curr];  // 新路径长度
                if (newLen < minRoadLen[a.dst]) {
                    minRoadLen[a.dst] = newLen; // 更新最短路径长度
                }
            }
        }
        ;
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