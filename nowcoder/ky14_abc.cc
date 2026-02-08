#include <iostream>
using namespace std;

int main () {
    for(int a = 0; a <= 5; a++) {
        for(int b = 0; b <= 4; b++) {
            for(int c = 0; c < 10; c++) {
                int sum = 100 * a + 110 * b + 12 * c;
                if(sum == 532) {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}