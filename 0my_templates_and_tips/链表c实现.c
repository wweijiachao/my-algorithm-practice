#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 反转 left 到 right 之间的链表
Node* reverseLink(Node* head, int left, int right) {
    Node* p = head;
    int cnt = 1;
    for (; cnt < left; cnt++) {
        p = p->next;
    }
    // 现在 p 指向 left 位置的前面
    Node* ll = p;    // 保存 left的前一个节点
    p = p->next;
    Node* q = p->next;
    Node* r = q ? q->next : NULL;
    for (; cnt < right; cnt++) {
        q->next = p;
        p = q, q = r;
        if (r) r = r->next;
        cnt++;
    }
    ll->next->next = q;
    ll->next = p;
    return head;
}
// 反转2： 头插法（推荐）
Node* reverseLink2(Node* head, int left, int right) {
    Node* pre = head;
    for (int i = 0; i < left - 1; ++i) pre = pre->next;

    Node* cur = pre->next; // 始终指向反转部分的第一个节点（例如 2）
    for (int i = 0; i < right - left; ++i) {
        Node* next = cur->next; // 暂存要杀回马枪的节点（例如 3）
        cur->next = next->next; // 2 连上 4
        next->next = pre->next; // 3 插到 2 前面
        pre->next = next;       // 1 连上 3
    }
    return head;
}
// 判断链表是否有环，并返回环的入口节点
Node* testRing(Node* head) {
    Node* p = head;
    Node* q = head;
    while (q) {
        // 快慢指针
        p = p->next;
        q = q ? q->next : q;
        q = q ? q->next : q;
        if (q == p) break;
    }
    if (q == NULL) return NULL;
    q = head;
    while (q != p) {
        p = p->next;
        q = q->next;
    }
    return q;
}