#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

struct range {
    int l, r;
    bool operator<(const range& other) const {
        return l < other.l;
    }
};

int main() {
    int L, M;
    while (cin >> L >> M) {
        if (M == 0) {
            cout << L + 1 << '\n';
            continue;
        }
        vector<range> vr;
        vr.reserve(M);
        for (int i = 0; i < M; i++) {
            range r;
            cin >> r.l >> r.r;
            vr.push_back(r);
        }
        sort(vr.begin(), vr.end());
        int a = vr[0].l, b = vr[0].r;
        int len = 0;
        for (int i = 1; i < M; i++) {
            if (vr[i].l <= b && vr[i].r > b) b = vr[i].r;
            else if(vr[i].l > b) {
                len += b - a + 1;
                a = vr[i].l, b = vr[i].r;
            }
        }
        len += b - a + 1;
        cout << L + 1 - len << '\n';
    }

    return 0;
}