#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, int m, int s): vNum(n), eNum(m), start(s) {
        edges.resize(vNum + 1);
        visited.resize(vNum + 1, false);
        dist.resize(vNum + 1, inf);
    }
    void run() {
        input();
        dijkstra();
        output();
    }
private:
    int vNum;
    int eNum;
    int start;
    struct edge {
        int dst;
        int len;
    };
    vector<vector<edge>> edges;
    vector<bool> visited;
    vector<long long> dist;
    const long long  inf = 0x7fffffff;

    void input() {
        for (int i = 0; i < eNum; i++) {
            int u, v, w;
            cin >> u>> v >> w;
            // e:u->v, len=w
            edges[u].push_back({v, w});
        }
    }
    void output() {
        for (int i = 1; i <= vNum; i++) {
            cout << dist[i] << ' ';
        }
    }
    void dijkstra() {
        using pli = pair<long long, int>;
        priority_queue<pli, vector<pli>, greater<pli>>pDists;

        dist[start] = 0;
        int curr = start;
        pDists.push({0, start});
        while(!pDists.empty()) {
            auto a = pDists.top();
            pDists.pop();
            curr = a.second;
            if (visited[curr] || dist[curr] < a.first) continue;
            visited[curr] = true;
            for (auto a: edges[curr]) {
                if (visited[a.dst]) continue;
                auto curLen = dist[curr] + a.len;
                if (curLen < dist[a.dst]) {
                    // 对a.dst找到更短路
                    dist[a.dst] = curLen;
                    pDists.push({curLen, a.dst});
                }
            }
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    Solution slt(n, m, s);
    slt.run();

    return 0;
}