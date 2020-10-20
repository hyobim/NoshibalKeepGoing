#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
	int data;
	vector<Node*> childlist;
	Node* Parent;
	Node() {
		data = 0;
		Parent = NULL;
	}
};

class Tree {
public:
	Node * root;
	vector<Node*> nodelist;

	Tree() {
		root = new Node;
		root->data = 1;
		root->Parent = NULL;
		nodelist.push_back(root);
	}

	void insert(int p, int c) {
		Node* pp = NULL;
		for (int i = 0; i < nodelist.size(); i++) {
			if (nodelist[i]->data == p)
				pp = nodelist[i];
		}
		if (pp == NULL)
			return;
		Node* newnode = new Node;
		newnode->data = c;
		newnode->Parent = pp;
		nodelist.push_back(newnode);
		pp->childlist.push_back(newnode);
	}
	void search(int num) {
		for (int i = 0; i < nodelist.size(); i++) {
			if (nodelist[i]->data == num)
				PostOrder( nodelist[i]);
		}
	}
	void PostOrder(Node* br) {
		if (br->childlist.size() == 0)
			cout << br->data << " ";
		for (int i = 0; i < br->childlist.size(); i++)
			PostOrder(br->childlist[i]);
	}
};
int main() {
	int treesoo;
	int num, choose;
	int p, c;
	cin >> treesoo;
	while (treesoo--)
	{
		Tree t;
		cin >> num >> choose;
		for (int i = 0; i < num; i++) {
			cin >> p >> c;
			t.insert(p, c);
		}
		t.search(choose);
		cout << endl;
	}
}