#include <assert.h>
#include <iostream>

using namespace std;

void check(int *arr, int n, int i, int sum, int &cnt) {
  sum += arr[i];
  if (sum > 40)
    return;
  if (sum == 40) {
    cnt++;
    return;
  }
  for (int j = i + 1; j < n; j++) {
    check(arr, n, j, sum, cnt);
  }
}
int main() {
  int n;
  cin >> n;
  int *arr = new int[n];
  assert(arr);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    check(arr, n, i, sum, cnt);
  }
  cout << cnt << endl;
  delete[] arr;

  return 0;
}