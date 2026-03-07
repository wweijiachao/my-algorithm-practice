#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct task {
    string line;
    string datetime;
    double cost;
    bool operator<(const task& other) const {
        if (cost != other.cost) return cost < other.cost;
        return datetime < other.datetime;
    }
};
int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    vector<task> tasks;
    string line;
    while (getline(cin, line)) {
        if (line == "") continue;
        istringstream ss(line);
        string name, date, time, cost;
        ss >> name >> date >> time >> cost;
        tasks.push_back({line, date + time, stod(cost)});
    }
    sort(tasks.begin(), tasks.end());
    for (auto a: tasks) {
        cout << a.line << '\n';
    }


    return 0;
}