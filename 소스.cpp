#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
	Node(){
		data = 0;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};
class Tree {
public:

	Node* root;
	Node* cur;
	Tree() {
		cur = NULL;
		root = new Node;
		root->data = 10;
	}
	void insert(int data) {
		Node* newnode = new Node;
		newnode->data = data;

		if (root->left == NULL) {
			root->left = newnode;
			cur = newnode;
			newnode->parent = root;
		}
		else {
			cur->right = newnode;
			newnode->parent = cur;
			cur = newnode;
		}
	}
	int findParent(Node* p) {
		cout << p->data << endl;
		if (p->parent->left == p)
			return p->parent->data;
		else
			return findParent(p->parent);
	}
};

int main() {
	Tree t;
	t.insert(2);
	t.insert(3);
	t.insert(4);
	t.insert(5);
	t.insert(6);
	t.insert(7);
	t.insert(8);

	cout << "ÂğºÎ¸ğ³ëµå´Â? " << t.findParent(t.cur);
}