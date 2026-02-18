#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n;
set<int> q;

int main(void) {
    cin >> n;
    vector<vector<int>> c;
    c.assign(n, vector<int>(n, 0));
    cout << c[0][n];
    
    return 0;
}