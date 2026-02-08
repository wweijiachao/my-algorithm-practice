#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int deal(int a) {
  if (a % 2) {
    // 奇数
    return (3 * a + 1) / 2;
  } else {
    // 偶数
    return a / 2;
  }
}
int main() {
  int n;
  while (cin >> n) {
    int cnt = 0;
    while (n != 1) {
      cnt++;
      n = deal(n);
    }
    cout << cnt << endl;
  }

  return 0;
}