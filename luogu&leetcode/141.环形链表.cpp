#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto low = head, fast = head;
        if (fast == nullptr) return false;
        while(fast && fast->next) {
            low = low->next;
            fast = fast->next->next;
            if(low == fast) return true;
        }
        return false;
    }
};
// @lc code=end

