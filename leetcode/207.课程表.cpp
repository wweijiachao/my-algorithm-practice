#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
    bool khan(int n) {
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            for (auto a:adjList[cur]) {
                inDegree[a] -= 1;
                if (inDegree[a] == 0) que.push(a);
            }
        }
        for (int i = 0; i < n; i++) {
            if (inDegree[i] != 0) return false;
        }
        return true;
    }
};
// @lc code=end


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}