#include <cctype>
#include <cstring>
#include <stdio.h>

char tree_[1005];
char* tree = tree_ + 1;

int symmetric(int i, int j) {
    int a1 = isalpha(tree[i]);
    int a2 = isalpha(tree[j]);
    return a1 == a2;
}

int slt() {
	int levelNum = 1, totalNum = 0;
    int len = strlen(tree);
	while (1) {
		for (int i = 0; i < (levelNum >> 1); i++) {
			if (!symmetric(totalNum + i, totalNum + levelNum  -1 - i)) return 0;
		}
        totalNum += levelNum;
        levelNum <<= 1;
        if (totalNum == len) return 1;
        else if (totalNum > len) return 0;
	}
    return 1;
}
int main() {
	scanf("%s", tree);
	if (slt()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
	
	return 0;
}