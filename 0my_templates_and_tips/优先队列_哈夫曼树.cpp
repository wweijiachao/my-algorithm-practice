#include <iostream>
#include <queue>

using std::priority_queue;
using std::cin;
using std::cout;
// using smallHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;

int main() {
    int n;
    while (cin >> n) {
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            // 默认是大根堆
            pq.push(-x);
        }
        int sum = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            sum -= (a + b);
        }
        cout << sum << '\n';
    }

    return 0;
}