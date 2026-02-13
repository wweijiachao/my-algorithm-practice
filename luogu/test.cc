#include <iostream>
#include <set>
using namespace std;
int n;
set<int> q;

int main(void) {
    cin >> n;
    while(n--) {
        int x;
        scanf("%d", &x);
        q.insert(x);
    }
    printf("%d\n", q.size());
    for(auto x:q) printf("%d ", x);
    
    
    
    return 0;
}