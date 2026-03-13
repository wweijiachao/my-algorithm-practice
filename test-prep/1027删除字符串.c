#include <stdio.h>
#include <string.h>

int main() {
    char str[30] = "I love nwpu and xi'an city!";
    char* p = strstr(str, "and");
    if (p != NULL) {
        printf("%ld\n", p - str);
        printf("%s\n", p);
    }

    return 0;
}