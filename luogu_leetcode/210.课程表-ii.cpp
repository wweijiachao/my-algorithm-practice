#include <queue>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses);
        makeGraph(prerequisites);
        return khan(numCourses);
    }
private:
    vector<vector<int>> adjList;
    vector<int> inDegree;

    void init(int n) {
        adjList.assign(n, vector<int>());
        inDegree.assign(n, 0);
    }
    void makeGraph(vector<vector<int>>& pre) {
        for (auto a: pre) {
            adjList[a[1]].push_back(a[0]);
            inDegree[a[0]] += 1;
        }
    }
    vector<int> khan(int n) {
        vector<int> res;
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            res.push_back(cur);
            for (const auto& a:adjList[cur]) {
                inDegree[a] -= 1;
                if (inDegree[a] == 0) que.push(a);
            }
        }
        if (res.size() != n) return {};
        return res;
    }
};
// @lc code=end

