#include <iostream>

using std::cin;
using std::cout;

struct node {
    int val;
    node* left;
    node* right;
};

node* root;

void addToBst(int x) {
    if (!root) {
        root = new node;
        root->val = x;
        root->left = root->right = nullptr;
        return;
    }
    node* p = root;
    node* q;
    while (p) {
        q = p;
        if (x < p->val) p = p->left;
        else if (x > p->val) p = p->right;
        else return; // 已经有这个值了
    }
    node* newp = new node;
    newp->val = x;
    newp->left = newp->right = nullptr;
    if (x < q->val) q->left = newp;
    else q->right = newp;    
}
void preOrder(node* p) {
    if (!p) return;
    cout << p->val << " ";
    preOrder(p->left);
    preOrder(p->right);
}
void midOrder(node* p) {
    if (!p) return;
    midOrder(p->left);
    cout << p->val << " ";
    midOrder(p->right);
}
void pstOrder(node* p) {
    if (!p) return;
    pstOrder(p->left);
    pstOrder(p->right);
    cout << p->val << " ";
}
void destory(node* p) {
    if (!p) return;
    destory(p->left);
    destory(p->right);
    p->left = p->right = nullptr;
    delete p;
}
int main() {
    int n;
    while (cin >> n) {
        root = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            addToBst(x);
        }
        preOrder(root);
        cout << '\n';
        midOrder(root);
        cout << '\n';
        pstOrder(root);
        cout << '\n';
        destory(root);
    }

    return 0;
}