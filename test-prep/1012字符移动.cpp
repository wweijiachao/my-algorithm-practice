// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     string s;
//     cin >> s;
//     int len = s.size();
//     for (int i = 0; i < len; i++) {
//         if (s[i] <= '9' && s[i] >= '0') {
//             // 踢到后面
//             s += s[i];
//             s.erase(i, 1);
//             i--;
//             len--;
//         }
//     }
//     cout << s << endl;

//     return 0;
// }


// #include <iostream>
// #include <cctype>
// #include <algorithm>

// using namespace std;

// int main() {
//     string s;
//     cin >> s;
//     stable_partition(s.begin(), s.end(), [](char ch) {
//         return !isdigit(ch);
//     });
//     cout << s << endl;

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1,6,3,6,3,5,6,8,0,9,8,4,3,2,1};
    stable_partition(arr.begin(), arr.end(), [](int a) {
        return a < 5;
    });
    for (auto a: arr) cout << a;

    return 0;
}
