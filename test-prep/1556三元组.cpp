#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr;
    unordered_map<int, int> freq;
    while (N--) {
        int m;
        cin >> m;
        arr.assign(m, 0);
        freq.clear();
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int sum = arr[i] + arr[j];
                auto it = freq.find(sum);
                if (it != freq.end()) {
                    cnt += it->second;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}