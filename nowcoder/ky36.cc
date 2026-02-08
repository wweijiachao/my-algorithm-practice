#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct rat {
    int weight;
    string color;
} rat;
int main() {
    int n;
    cin >> n;
    vector<rat> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].weight >> arr[i].color;
    }
    sort(arr.begin(), arr.end(), [](rat a, rat b) {
        return a.weight > b.weight;
    });
    for(auto x:arr) {
        cout << x.color << endl;
    }

    return 0;
}