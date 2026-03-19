#include <iostream>
#include <ostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

struct node {
    char val;
    node* left;
    node* right;
};
class Solution {
public:
    Solution(const string& pre_, const string& mid_): pre(pre_), mid(mid_) {
        init();
    }
    ~Solution() {
        destroy(root);
    }
    string run() {
        pstOrder(root);
        return pst;
    }
private:
    string pre, mid;
    string pst;
    node* root;

    int pre_idx;    // 记录此时先序数组到哪儿了

    node* makeTree(int j, int k) {
        // [j, k]: mid        
        if (j > k) return nullptr;
        node* p = new node;
        p->val = pre[pre_idx++];
        int m = j;
        while (mid[m] != p->val) m++;
        p->left = makeTree(j, m - 1);
        p->right = makeTree(m + 1, k);
        return p;
    }
    void init() {
        pre_idx = 0;
        root = makeTree(0, mid.size() - 1);
    }
    void destroy(node* p) {
        if (!p) return;
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
    void pstOrder(node* p) {
        if (!p) return;
        pstOrder(p->left);
        pstOrder(p->right);
        pst += p->val;
    }
};

int main() {
    string pre, mid;
    while (cin >> pre >> mid) {
        Solution slt(pre, mid);
        string pst = slt.run();
        cout << pst << std::endl;
    }

    return 0;
}