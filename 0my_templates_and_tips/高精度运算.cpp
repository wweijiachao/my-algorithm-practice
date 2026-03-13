#include <iostream>
#include <vector>

using namespace std;

struct BigInt {
    vector<int> v;  // 逆序存储，绝对值
    bool neg = false;

    explicit BigInt(string s) {
        int head = 0;
        if (s[0] == '-') {
            neg = true;
            head = 1;
        }
        for (int i = s.size() - 1; i >= head; i--) {
            v.push_back(s[i] - '0');
        }
    }

    string toString() const {
        string res;
        if (neg) res += '-';
        for (int i = v.size() - 1; i >= 0; i--) res += v[i] + '0';
        return res;
    }
    void normalize() {
        // 去除前导零
        while (v.size() > 1 && v.back() == 0) v.pop_back();
        // 处理 -0
        if (v.size() == 1 && v[0] == 0 && neg) neg = !neg;
    }
    void addWithAbs(const vector<int>& other) {
        // 绝对值原地加法, 加到自身
        size_t i = 0, j = 0;
        int carry = 0;
        while (i < v.size() || j < other.size() || carry) {
            if (i == v.size()) v.push_back(0);
            v[i] += carry;
            if (j < other.size()) v[i] += other[j++];
            carry = v[i] / 10;
            v[i] %= 10;
            i++;
        }
    }
    void subWithAbs(const vector<int>& other) {
        // 绝对值原地减法, 保证输入是大减小或者相等
        size_t i = 0, j = 0;
        int borrow = 0;
        while (i < v.size() || j < other.size()) {
            v[i] -= borrow;
            if (j < other.size()) v[i] -= other[j++];
            if (v[i] < 0) {
                borrow = 1;
                v[i] += 10;
            } else borrow = 0;
            i++;
        }
        normalize();
    }

    bool testAbsIfBiggerEqual(const BigInt& other) const {
        auto len1 = v.size();
        auto len2 = other.v.size();
        if (len1 != len2) return len1 > len2;
        for (int i = len1 - 1; i >= 0; i--) {
            if (v[i] != other.v[i]) return v[i] > other.v[i];
        }
        // 相等
        return true;
    }
    BigInt& operator+=(const BigInt& other) {
        if (neg == other.neg) {
            // 符号相同, 绝对值相加, 符号不变
            addWithAbs(other.v);
        } else {
            // 符号相反, 绝对值相减,保留本数符号
            bool bgEq = testAbsIfBiggerEqual(other);
            if (bgEq) subWithAbs(other.v);
            else {
                // 绝对值小, 改成后减前, 符号取反
                vector<int> tmp(v.begin(), v.end());
                v = other.v;
                subWithAbs(tmp);
                neg = !neg;
            }
        }
        return *this;
    }
    BigInt& operator-=(const BigInt& other) {
        if (neg == other.neg) {
            // 符号相同, 保留自身符号, 绝对值相减
            bool bgEq = testAbsIfBiggerEqual(other);
            if (bgEq) subWithAbs(other.v);
            else {
                // 绝对值小, 改成后减前, 符号取反
                vector<int> tmp(v.begin(), v.end());
                v = other.v;
                subWithAbs(tmp);
                neg = !neg;
            }
        } else {
            // 符号不同, 保留自身符号, 绝对值相加
            addWithAbs(other.v);
        }
        return *this;
    }
    BigInt operator+(const BigInt& other) const {
        BigInt res = *this;
        res += other;
        return res;
    }
    BigInt operator-(const BigInt& other) const {
        BigInt res = *this;
        res -= other;
        return res;
    }
    BigInt operator*(const BigInt& other) const {
        BigInt res("0");
        // 预留足够空间, 最多是 len1 + len2
        res.v.assign(v.size() + other.v.size(), 0);

        for (size_t i = 0; i < other.v.size(); i++) {
            for (size_t j = 0; j < v.size(); j++) {
                res.v[i + j] += v[j] * other.v[i];
                res.v[i + j + 1] += res.v[i + j] / 10;
                res.v[i + j] %= 10;
            }
        }
        // 确定符号
        res.neg = (neg != other.neg);
        res.normalize();
        return res;
    }
};

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << (BigInt(s1) * BigInt(s2)).toString() << endl;
    }

    return 0;
}