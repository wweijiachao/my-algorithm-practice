#include <iostream>

using namespace std;

int main() {
    int profit;
    int bonus = 0;
    const int mln = 100000;
    cin >> profit;
    if (profit <= mln) {
        bonus += profit * .1;
    } else if (profit <= 2 * mln) {
        bonus += mln * .1 + (profit - mln) * .075;
    } else if (profit <= 4 * mln) {
        bonus += mln * .175 + (profit - 2 * mln) * .05;
    } else if (profit <= 6 * mln) {
        bonus += mln * .275 + (profit - 4 * mln) * .03;
    } else if (profit < 10 * mln) {
        bonus += mln * (.275 + .06) + (profit - 6 * mln) * .015;
    } else {
        bonus += mln * (.275 + .06 + 4 * .015) * (profit - 10 * mln) * .01;
    }

    cout << bonus << endl;

    return 0;
}