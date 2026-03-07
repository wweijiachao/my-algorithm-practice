#include <iostream>
#include <string>

using namespace std;

int month[13] = {0, 
    31, 28, 31, 
    30, 31, 30, 
    31, 31, 30, 
    31, 30, 31};
int month_prefix[13] = {0};
void cal_pref() {
    for (int i = 1; i <= 12; i++) {
        month_prefix[i] = month[i - 1] + month_prefix[i - 1];
    }
}
struct date {
    int yy, mm, dd;
    static bool isLeap(int yy);
};
bool date::isLeap(int yy) {
    return yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0);
}
int to_absolute_days(const date& d) {
    int y = d.yy - 1;
    int y_days = 365 * y + y / 4 - y / 100 + y / 400;
    int m_days = month_prefix[d.mm];
    if (d.mm > 2 && date::isLeap(d.yy)) m_days++;
    int days = d.dd;
    return y_days + m_days + days;
}
void s_to_date(string s, date& d) {
    d.yy = stoi(s.substr(0, 4));
    d.mm = stoi(s.substr(4, 2));
    d.dd = stoi(s.substr(6, 2));
}
int cal(string s1, string s2) {
    date d1, d2;
    s_to_date(s1, d1);
    s_to_date(s2, d2);
    int res = to_absolute_days(d1) - to_absolute_days(d2);
    if (res < 0) res = -res;
    return res;
}
int main() {
    cal_pref();
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << cal(s1, s2) + 1 << '\n';
    }

    return 0;
}