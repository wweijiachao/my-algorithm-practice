#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#define NULLCHAR '0'

using std::cin;
using std::cout;
using std::string;

typedef struct Node {
    char val;
    Node* left;
    Node* right;
} Node;

class Solution {
public:
    Solution(const string& s) {
        std::istringstream ss(s);
        string s2;
        while (ss >> std::ws >> s2) {
            originPreOrderStr += s2;
            if (s2 != "0") preOrderStr += s2;
        }
        originPreOrderStrLen = originPreOrderStr.size();
        int i = 0;
        root = makeTreeByPreorder(i);
    }
    ~Solution() {
        destoryTree(root);
    }
    void run() {
        midOrder(root);
        pstOrder(root);
        outputWithSpace(preOrderStr);
        outputWithSpace(midOrderStr);
        outputWithSpace(pstOrderStr);
        cout << leafNodeNum << '\n';
        // bfs();
    }
private:
    Node* root;
    string originPreOrderStr;
    string preOrderStr;
    string midOrderStr;
    string pstOrderStr;
    int originPreOrderStrLen;
    int leafNodeNum = 0;
    
    Node* makeTreeByPreorder(int& i) {
        if (i >= originPreOrderStrLen || originPreOrderStr[i] == NULLCHAR) return nullptr;
        Node* p = new Node;
        p->val = originPreOrderStr[i];
        i++;
        p->left = makeTreeByPreorder(i);
        i++;
        p->right = makeTreeByPreorder(i);

        if(!p->left && !p->right) leafNodeNum++;
        return p;
    }
    void midOrder(Node* p) {
        if (p == root) midOrderStr = "";
        if (!p) {
            // midOrderStr += NULLCHAR;
            return;
        }
        midOrder(p->left);
        midOrderStr += p->val;
        midOrder(p->right);
    }
    void pstOrder(Node* p) {
        if (p == root) pstOrderStr = "";
        if (!p) {
            // pstOrderStr += NULLCHAR;
            return;
        }
        pstOrder(p->left);
        pstOrder(p->right);
        pstOrderStr += p->val;
    }
    void bfs() {
        std::queue<Node*> que;que.push(root);
        while (!que.empty()) {
            int levelSize = que.size();
            for (int i = 0; i < levelSize; i++) {
                auto p = que.front();
                que.pop();
                if (!p) {
                    // cout << NULLCHAR;
                    continue;
                }
                cout << p->val;
                que.push(p->left);
                que.push(p->right);
            }
        }
        cout << '\n';
    }
    void outputWithSpace(string s) {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            cout << s[i] << (i != len - 1 ? " " : "\n");
        }
    }
    void destoryTree(Node *p) {
        if (!p) return;
        destoryTree(p->left);
        destoryTree(p->right);
        delete p;
    }
};

int main() {
    string str;
    while (std::getline(cin, str)) {
        Solution slt(str);
        slt.run();
        break;
    }

    return 0;
}
