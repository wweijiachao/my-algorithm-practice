#include <stdio.h>
#include <string.h>

int nums[100005];
int primes[100005];
int findPrime(int* primes, int a, int b) {
	memset(nums, 0, sizeof(nums));
	// nums[i]==0 表示i是质数
	nums[0] = nums[1] = 1;
	for (int i = 4; i <= b; i += 2) nums[i] = 1;
	// 比 2 大的偶数都不是质数
	for (int i = 3; i < (b >> 1); i += 2) {
		// 筛
		if (nums[i] == 0) {
			for (int j = i; j * i <= b; j++) {
				// 内层循环直接从 j = i 开始！前面的已经被筛掉了
				nums[j * i] = 1;	// 质数的所有倍数不是质数
			}
		}
	}
	int i = a, j = 0;
	for (; i <= b; i++) {
		if (nums[i] == 0) primes[j++] = i;
	}
	return j;
}
int isRev(int a) {
	char ch[20];
	sprintf(ch, "%d", a);
	int i = 0, j = strlen(ch) - 1;
	while (i < j) {
		if (ch[i] != ch[j]) return 0;
		i++, j--;
	}
	return 1;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int len = findPrime(primes, a, b);
	for (int i = 0; i < len; i++) {
		if (isRev(primes[i])) {
			printf("%d\n", primes[i]);
		}
	}

	return 0;
}