#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int now = 13 * 60 + 15;
    while (n--) {
        int hh, mm;
        scanf("%d:%d", &hh, &mm);
        int time_ = now + hh * 60 + mm;
        hh = (time_ / 60) % 24;
        mm = time_ % 60;
        printf("%d:%d\n", hh, mm);
    }

    return 0;
}