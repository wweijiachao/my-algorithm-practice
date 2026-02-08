#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// 将火星数分割成数组
vector<int> spiltMars(string a) {
  int i = 0, j = 0;
  vector<int> res;
  for (; j < (int)a.size(); j++) {
    if (a[j] == ',') {
      string s = a.substr(i, j - i);
      j++;
      i = j;
      int num = 0;
      sscanf(s.c_str(), "%d", &num);
      res.push_back(num);
    }
  }
  a = a.substr(i);
  sscanf(a.c_str(), "%d", &j);
  res.push_back(j);
  return res;
}
bool isPrime(int a) {
  for (int i = 2; i <= a / 2; i++) {
    if (a % i == 0)
      return false;
  }
  return true;
}
int main() {
  string a = "1,1,1,0";
  int prime[25] = {2};
  int i = 1;
  for (int j = 3;; j += 2) {
    if (isPrime(j))
      prime[i++] = j;
    if (i >= 25)
      break;
  }
  auto res = spiltMars(a);
  // 火星数对应数组存入 res
  int val = 0;
  for (int i = 0; i < (int)res.size(); i += 1) {
    val += res[i] * pow(prime[i], i);
  }
  cout << val;

  return 0;
}