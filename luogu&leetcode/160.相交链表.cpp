#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // auto p = headA, q = headB;
        // int m = 0, n = 0;
        // while (p != nullptr) {
        //     m++;
        //     p = p->next;
        // }
        // while (q != nullptr) {
        //     n++;
        //     q = q->next;
        // }
        // p = headA, q = headB;
        // if (m > n) {
        //     for (int i = 0; i < m - n; i++) {
        //         p = p->next;
        //     }
        // } else {
        //     for (int i = 0; i < n - m; i++) {
        //         q = q->next;
        //     }
        // }
        // while(p != nullptr) {
        //     if (p == q) return p;
        //     p = p->next;
        //     q = q->next;
        // }
        // return nullptr;
        
        if (headA == nullptr || headB == nullptr) return 0;
        auto p = headA, q = headB;
        while (p != q) {
            p = p == nullptr ? headB : p->next;
            q = q == nullptr ? headA : q->next;
        }
        return p;
    }
};
// @lc code=end

