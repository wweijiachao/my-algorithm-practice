#include <iostream>

struct node {
	node* left;
	node* right;
};

node* findLca(node* n, node* p, node* q) {
	if (!n || !p || !q) return nullptr;
	if (n == p || n == q) return n;
	auto a =findLca(n->left, p, q);
	auto b = findLca(n->right, p, q);
	if (a && b) return n;
	else if (a) return a;
	else return b;
}