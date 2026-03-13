#include <stdio.h>
#include <string.h>

char str[100005];

// 提取出来的“中心扩展”纯逻辑，极其干净，且把 len 作为参数传进来
int expand(int i, int j, int len) {
    // 完美的短路求值安检：先查界，再读值！
    while (i >= 0 && j < len && str[i] == str[j]) {
        i--;
        j++;
    }
    // 退出 while 时，i 和 j 已经是不满足条件的非法位置了
    // 真实的有效边界是 (i+1) 到 (j-1)，长度为 (j-1) - (i+1) + 1 = j - i - 1
    return j - i - 1;
}

int main() {
    // 处理空字符串或读入失败的严谨写法
    if (scanf("%s", str) != 1) return 0; 
    
    int len = strlen(str);
    int maxSubLen = 1;
    
    // k 从 0 开始，逻辑更直观，绝不漏掉任何一个中心
    for (int k = 0; k < len; k++) {
        // 1. 把 k 当作唯一中心（处理奇数回文，如 aba）
        int len1 = expand(k, k, len);
        // 2. 把 k 和 k+1 中间的虚线当作中心（处理偶数回文，如 abba）
        int len2 = expand(k, k + 1, len);
        
        // 打擂台更新最大值
        if (len1 > maxSubLen) maxSubLen = len1;
        if (len2 > maxSubLen) maxSubLen = len2;
    }
    
    printf("%d\n", maxSubLen);
    return 0;
}