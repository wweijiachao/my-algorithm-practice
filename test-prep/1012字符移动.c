#include <stdio.h>
#include <string.h>

char src[101], dst[101],tmp[101];
int main () {
	scanf("%s", src);
	int i = 0, j = 0, k = 0;
	for (; src[i] != '\0'; i++) {
		if (src[i] >= '0' && src[i] <= '9') {
			tmp[k++] = src[i];
		} else {
			dst[j++] = src[i];
		}
	}
	dst[j] = tmp[k] = '\0';
	strcat(dst, tmp);
	printf("%s\n", dst);
	return 0;
}