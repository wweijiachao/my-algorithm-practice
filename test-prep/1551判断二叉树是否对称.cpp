#include <ctype.h>
#include <string.h>
#include <stdio.h>

char str[1005];
char tree[2010];

int symmetric(int i, int j) {
    int a1 = isalpha(tree[i]);
    int a2 = isalpha(tree[j]);
    return a1 == a2;
}

int slt() {
    int len = strlen(str);
    int i = 0, j = 1;
    for (; i < len; i++) {
        while (tree[j] == '*') j++;
        char ch = str[i];
        tree[j] = ch;
        if (ch == '#') {
            tree [2 * j] = '*';
            tree [2 * j + 1] = '*';
        }
        j++;        
    }
    tree[j] = '\0';

    len = strlen(tree + 1);
	int levelNum = 1, totalNum = 0;
	while (1) {
		for (int i = 0; i < (levelNum >> 1); i++) {
			if (!symmetric(totalNum + i + 1, totalNum + levelNum  - i)) return 0;
		}
        totalNum += levelNum;
        levelNum <<= 1;
        if (totalNum == len) return 1;
        else if (totalNum > len) return 0;
	}
    return 1;
}
int main() {
	scanf("%s", str);
	if (slt()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
	
	return 0;
}