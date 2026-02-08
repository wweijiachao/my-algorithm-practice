#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end(), [](char a, char b) { return a > b; });
  cout << s << endl;

  return 0;
}