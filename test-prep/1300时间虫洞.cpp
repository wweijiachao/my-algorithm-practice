// 12:50 -- 13:40
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll gcd (ll a, ll b) {
    return b == 0 ? a : gcd (b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m, n;
    unordered_set<ll> occupied;
    while (cin >> n >> m) {
        if (m == 0) {
            cout << 1 << '\n';
            continue;
        }
        occupied.clear();
        for (int i = 0; i < m; i++) {
            ll x;
            cin >> x;
            occupied.insert(x);
        }

        vector<ll> factors;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i * i != n) factors.push_back(n / i);
            }
        }
        sort(factors.begin(), factors.end());

        bool found = false;
        for (auto t: factors) {
            // ll ft = gcd (t, n);
            if (occupied.find(t) == occupied.end()) {
                // 没占领
                cout << t << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << "I can't go on\n";
    }


    return 0;
}