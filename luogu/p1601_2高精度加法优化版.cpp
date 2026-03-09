#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct BigInt {
    string val;
    bool neg = false;
    explicit BigInt(string s) {
        if (s[0] == '-') {
            val = s.substr(1);
            neg = true;
        } else val = s;
    }
    BigInt(string s, bool neg_): val(s), neg(neg_) {}

    // bool testBiggerEqual(const BigInt& s1, const BigInt& s2) const {
    //     const auto len1 = s1.val.size();
    //     const auto len2 = s2.val.size();
    //     if (len1 != len2) return len1 > len2;
    //     for (int i = 0; i < (int)len1; i++) {
    //         const auto ch1 = s1.val[i];
    //         const auto ch2 = s2.val[i];
    //         if (ch1 != ch2) return ch1 > ch2;
    //     }
    //     // 相等
    //     return true;
    // }

    bool operator<(const BigInt& other) const {
        const auto len1 = val.size();
        const auto len2 = other.val.size();
        if (len1 != len2) return len1 < len2;
        for (int i = 0; i < (int)len1; i++) {
            const auto ch1 = val[i];
            const auto ch2 = other.val[i];
            if (ch1 != ch2) return ch1 < ch2;
        }
        // 相等
        return false;
    }
    bool operator>(const BigInt& other) const {
        return other < *this;
    }
    bool operator==(const BigInt& other) const {
        return !(*this < other) && !(other < *this);
    }

    int oprandType (bool n1, bool n2) const {
        //  0    1    2    3 
        // 正正 正负 负正 负负
        int res = 0;
        if (n1) res += 2;
        if (n2) res += 1;
        return res;
    }
    BigInt operator+(const BigInt& other) const {
        string res;
        const auto len1 = val.size();
        const auto len2 = other.val.size();
        const auto size = std::max(len1, len2) + 1;

        res.reserve(size);  // 先为res预留size的空间

        int i = len1 - 1, j = len2 - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += val[i--] - '0';
            if (j >= 0) sum += other.val[j--] - '0';
            // carry = sum / 10;
            // sum %= 10;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else carry = 0;
            // 因为除法和取模式最慢的运算, 可以用减法代替, 能快一点
            res.push_back(sum + '0');
        }
        reverse(res.begin(), res.end());
        return BigInt(res);
    }

    BigInt operator-(const BigInt& other) const {
        string res;
        const auto len1 = val.size();
        const auto len2 = other.val.size();
        const auto maxsize = std::max(len1, len2);
        res.reserve(maxsize);

        int i = len1 - 1, j = len2 - 1;
        int borrow = 0;
        while (i >= 0 || j >= 0) {
            int dif = -borrow;
            if (i >= 0) dif += val[i--] - '0';
            if (j >= 0) dif -= other.val[j--] - '0';
            if (dif < 0) {
                borrow = 1;
                dif += 10;
            } else borrow = 0;
            res.push_back(dif + '0');
        }
        // 此时已经做完字符串相减, 并且大减小一定没有借位
        int realSize = res.size();
        while(--realSize && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return BigInt(res);
    }
};

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        // cin >> s1 >> s2;
        cout << (BigInt(s1) - BigInt(s2)).val << '\n';
        // break;
    }

    return 0;
}