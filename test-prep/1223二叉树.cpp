#include <stdio.h>

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y) == 2) {
        while (x != y) {
            if (x > y) x >>= 1;
            else y >>= 1;
        }
        printf("%d\n", x);
    }

    return 0;
}