#include <iostream>
#include <string>

int main() {
    std::string s1, s2;

    while (std::cin >> s1 >> s2) {
        int carry = 0;
        for (int i = s1.size() - 1; i >= 0; i--) {
            s1[i] += s2[i] + carry - '0';
            if (s1[i] > '9') {
                carry = 1;
                s1[i] -= 10;
            } else carry = 0;
        }
        if (carry == 1) {
            s1 = "1" + s1;
        }
        std::cout << s1 << '\n';
    }


    return 0;
}