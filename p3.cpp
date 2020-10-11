#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* Parent;
	vector<Node*> child;
	Node() {
		data = 0;
		Parent = NULL;
	}
};

class Tree {
public:
	Node * root;
	vector<Node*> node;

	Tree() {
		root = new Node();
		root->data = 1;
		root->Parent = NULL;
		root->depth = 0;
		node.push_back(root);
	}
	Node* Search(int d) {
		for (int i = 0; i < node.size(); i++)
		{
			if (node[i]->data == d)
				return node[i];
		}
		return NULL;
	}
	void insert(int d, int da) {
		Node* parent = Search(d);
		if (parent == NULL)
			return;
		else {
			Node* newnode = new Node;
			newnode->data = da;
			newnode->Parent = parent;
			parent->child.push_back(newnode);
			node.push_back(newnode);
			newnode->depth = parent->depth + 1;
		}
	}
	void printD(int d) {
		Node* dd = Search(d);
		cout << dd->depth << endl;
	}
	
};

int main() {
	int T,n, x, y;
	cin >> T>>n;
	
	Tree t;
	while (T--)
	{
		cin >> x >> y;
		t.insert(x, y);
	}
	while (n--)
	{
		int wd;
		cin >> wd;
		t.printD(wd);
	}
}