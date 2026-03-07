#include <iostream>

using namespace std;
using ll = long long;

int month[13] = {0,
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31};

bool isLeap(int yy) {
    return yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0);
}

int main() {
    ll n;
    while (cin >> n) {
        int hh = 0, mn = 0, ss = 0;
        ss = n % 60; n /= 60;
        mn = n % 60; n /= 60;
        hh = n % 24; n /= 24;
        
        int cur_year = 2009;
        while (true) {
            int y_days = isLeap(cur_year) ? 366 : 365;
            if (n >= y_days) {
                cur_year++;
                n -= y_days;
            } else break;
        }
        int cur_month = 1;
        while (true) {
            int m_days = month[cur_month];
            if (cur_month == 2 && isLeap(cur_year)) m_days++;
            if (n >= m_days) {
                cur_month++;
                n -= m_days;
            } else break;
        }
        int cur_day = n + 1;

        printf("%d-%02d-%02d ", cur_year, cur_month, cur_day);
        printf("%02d:%02d:%02d\n", hh, mn, ss);
    }

    return 0;
}