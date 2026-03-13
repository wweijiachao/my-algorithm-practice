#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
	
	int n;
	cin >> n;
	vector<int> arr;
    arr.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
    for (auto a: arr) cout << a << " ";
	cout << endl;	
	auto it =unique(arr.begin(), arr.end());
	arr.erase(it, arr.end());
	for (auto a: arr) cout << a << " ";
	cout << endl;	
	return 0;
}