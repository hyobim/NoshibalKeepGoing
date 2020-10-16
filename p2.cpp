#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* Parent;
	vector<Node*> child;
	Node(int data) {
		this->data = data;
		Parent = NULL;
	}
	void setParent(Node* pa) {
		Parent = pa;
	}
	void insertChild(Node* child) {
		this->child.push_back(child);
	}
	void delChild(Node* ch) {
		for (int i = 0; i < child.size(); i++) {
			if (child[i] == ch)
				child.erase(child.begin() + i);
		}
	}
};

class Tree {
public:
	Node * root;
	vector<Node*> nodelist;
	int count;

	Tree(int data) {
		Node* node = new Node(data);
		root = node;
		count = 1;
		nodelist.push_back(node);
	}
	int size() {
		return nodelist.size();
	}
	void insert(int d, int da) {
		for (int i = 0; i < size(); i++) {
			if (nodelist[i]->data == d) {
				Node* newnode = new Node(da);
				newnode->Parent = nodelist[i];
				nodelist[i]->child.push_back(newnode);
				nodelist.push_back(newnode);
				return;
			}
		}
	}
	void preorder(Node* node) {
		if (!node) {
			return;
		}
		if (node->child.size() == 0) {
			cout << count << " ";
			count = 0;
		}
		count++;
		for (int i = 0; i < node->child.size(); i++) {
			preorder(node->child[i]);
		}
	}

};

int main() {
	int n, m; //n�� Ʈ���� ���� m�� �������� �� 
	int num1, num2;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		Tree t = Tree(1);
		for (int j = 0; j < m; j++) {
			cin >> num1 >> num2;
			t.insert(num1, num2);
		}
		t.preorder(t.root);
		cout << endl;
	}

}