#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(int n, vector<vector<int>> inputArray)
        : totalNumber(n)
    {
        list.reserve(n);
        for (int i = 0; i < totalNumber; i++) {
            list.emplace_back(
                student(
                i + 1, 
                inputArray[i][0],
                inputArray[i][1], 
                inputArray[i][2])
            );
        }
        run();
    }
private:
    struct student {
        int id = -1;
        int chinese = 0, math = 0, english = 0;
        int sum = 0;

        // 构造函数
        student(int i, int c, int m, int e)
            : id(i), chinese(c), math(m), english(e)
        {
            sum = chinese + math + english;
        }
        bool operator< (const student& other) const {
            if (sum != other.sum) return sum > other.sum;
            else if (chinese != other.chinese) return chinese > other.chinese;
            else return id < other.id;
        }
    };
    int totalNumber;
    vector<student> list;

    void run() {
        sort(list.begin(), list.end());
        for (int i = 0; i < 5; i++) {
            cout << list[i].id << ' ' << list[i].sum << endl;
        }
    }

};

int main() {
    // 只有在本地调试（定义了 LOCAL 宏）时才重定向输入
    // 需要在 tasks.json 的 args 里加上 '-DLOCAL'
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    Solution slt(n, std::move(arr));

    return 0;
}