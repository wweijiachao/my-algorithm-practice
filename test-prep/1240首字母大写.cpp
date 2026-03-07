#include <cstdio>
#include <iostream>
#include <cctype>

using namespace std;

bool isBlankWjc(char ch) {
    if (ch == ' ') return true;
    if (ch == '\n') return true;
    if (ch == '\r') return true;
    if (ch == '\t') return true;
    return false;
}
int main() {
    char s[105];
    scanf("%[^\n]", s);
    if (islower(s[0])) s[0] -= 32;
    for(int i = 1; s[i] != '\0'; i++) {
        if (isBlankWjc(s[i - 1])) {
            if (islower(s[i])) s[i] -= 32;
        }
    }
    printf("%s\n", s);

    return 0;
}