#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using pdd = pair<double, double>;

double dist(pdd p1, pdd p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}
int main() {
    int n;
    cin >> n;
    vector<pair<pdd, vector<double>>> points(n);
    // 邻接表, first为坐标, second为到其他点的距离
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        points[i].first.first = a;
        points[i].first.second = b;
        points[i].second.resize(n, 0);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            points[i].second[j] = dist(points[i].first, points[j].first);
        }
    }
    // 邻接表初始化完成
    

    return 0;
}