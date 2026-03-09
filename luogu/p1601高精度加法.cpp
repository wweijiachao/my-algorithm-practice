#include <iostream>
#include <string>

using namespace std;

struct BigInt {
    string val;
    BigInt (string s): val(s){}

    BigInt operator+(const BigInt& other) const {
        string res;
        const auto len1 = val.size();
        const auto len2 = other.val.size();
        const auto size = std::max(len1, len2) + 1;
        res.resize(size, '0');
        int i = len1 - 1, j = len2 - 1, k = size - 1;;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int sum = (val[i] - '0') + (other.val[j] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            res[k] += sum;
            i--, j--, k--;
        }
        while (i >= 0) {
            int sum = (val[i] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            res[k] += sum;
            i--, k--;
        }
        while (j >= 0) {
            int sum = (other.val[j] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            res[k] += sum;
            j--, k--;
        }
        res[0] += carry;
        if (res[0] == '0') return BigInt(res.substr(1));
        else return BigInt(res);
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (BigInt(s1) + BigInt(s2)).val << endl;

    return 0;
}