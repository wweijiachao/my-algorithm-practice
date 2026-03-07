#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct task {
    string sname;
    int datetime[7];
    double cost;
    bool operator<(const task& other) const {
        if (cost != other.cost) return cost < other.cost;
        for (int i = 0; i < 6; i++) {
            if (datetime[i] != other.datetime[i]) {
                return datetime[i] < other.datetime[i];
            }
        }
        return datetime[6] < other.datetime[6];
    }
};
int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    string line;
    vector<task> tasks;
    while (getline(cin, line)) {
        // 抢救 1：干掉幽灵 \r
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        
        // 抢救 2：跳过空行
        if (line.empty()) {
            continue; 
        }

        // 抢救 3：干掉字符串尾部的多余空格（可选，但极其稳妥）
        while (!line.empty() && line.back() == ' ') {
            line.pop_back();
        }
        
        task a;
        a.sname = line;
        sscanf(line.c_str(), 
            "%*s %d-%d-%d %d:%d:%d,%d %lf(s)",
            &a.datetime[0], &a.datetime[1], &a.datetime[2],
            &a.datetime[3], &a.datetime[4], &a.datetime[5], 
            &a.datetime[6], &a.cost);
        tasks.push_back(a);
    }
    sort(tasks.begin(), tasks.end());
    for (auto a: tasks) {
        cout << a.sname << endl;
    }
    
    return 0;
}