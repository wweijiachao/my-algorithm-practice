#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum = 0;
        dfs(root, sum, targetSum);
        return ok;
    }
private:
    bool ok = false;
    void dfs(TreeNode* node, int sum, const int& tar) {
        sum += node->val;
        auto l = node->left;
        auto r = node->right;
        if(!(l || r) && tar == sum) ok = true;
        if(l) dfs(l, sum, tar);
        if(r) dfs(r, sum, tar);
    }
};
// @lc code=end

