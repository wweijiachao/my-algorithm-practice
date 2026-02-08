#include <iostream>
#include <vector>

using namespace std;

int digitRoot(int n) {
  int c = n % 10;
  while (n > 9) {
    n /= 10;
    c += n % 10;
  }
  if (c > 9)
    return digitRoot(c);
  return c;
}
int main() {
  int n;
  while (cin >> n) {
    cout << digitRoot(n) << endl;
  }
  return 0;
}