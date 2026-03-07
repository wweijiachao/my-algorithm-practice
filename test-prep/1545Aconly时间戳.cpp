#include <iostream>

using namespace std;

int month[13] = {0,
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31};
int prefix[13]{};

void cal_prefix() {
    for (int i = 1; i <= 12; i++) {
        prefix[i] = prefix[i - 1] + month[i - 1];
    }
}

int main() {
    cal_prefix();
    int n;
    while (cin >> n) {
        int mm = 1, dd = 1;
        int hh = 0, mn = 0, ss = 0;
        ss = n % 60; n /= 60;
        mn = n % 60; n /= 60;
        hh = n % 24; n /= 24;
        // 剩下最多364天
        int i = 0;
        while (i < 12 && prefix[i + 1] <= n) i++;
        mm = i;
        dd = n - prefix[i] + 1;
        printf("2009-%02d-%02d ", mm, dd);
        printf("%02d:%02d:%02d\n", hh, mn, ss);
    }

    return 0;
}