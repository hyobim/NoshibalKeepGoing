#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
	char Data;
	Node* left;
	Node* right;
	vector<Node*> Child;

	Node(char data) {
		right = NULL;
		left = NULL;
		Data = data;
	}

	void insertChild(Node* child) {
		this->Child.push_back(child);
	}

};

class Tree {
public:
	Node * root;
	vector<Node*> node_list;
	Tree(char d) {
		root = new Node(d);
		node_list.push_back(root);
	}

	int size() {
		return node_list.size();
	}
	void insertNodeL(char par_data, char data) { //�ش�θ��带 ã�� �ڽĳ��� �߰�
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->Data == par_data) { //�θ���ã�� 
				Node* node = new Node(data); //�ڽĳ�����
				node_list[i]->insertChild(node);
				node_list[i]->left=node; //����� ���ʰ���
				node_list.push_back(node);
				return;
			}
		}
	}
	void insertNodeR(char par_data, char data) { //�ش�θ��带 ã�� �ڽĳ��� �߰�
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->Data == par_data) { //�θ���ã�� 
				Node* node = new Node(data); //�ڽĳ�����
				node_list[i]->right = node; //����� �����ʰ���
				node_list.push_back(node);
				return;
			}
		}
	}


	void PreOrder(Node* n) {
		if (n == NULL)
			return;
		cout << n->Data;
		PreOrder(n->left);
		PreOrder(n->right);
	}
	void InOrder(Node* n) {
		if (n == NULL)
			return;
		InOrder(n->left);
		cout << n->Data;
		InOrder(n->right);
	}
	void PostOrder(Node* n) {
		if (n == NULL)
			return;
		PostOrder(n->left);
		PostOrder(n->right);
		cout << n->Data;
	}


};
int main() {
	int n;
	cin >> n;
	Tree t = Tree('A');
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x>>y>>z;
		if (y != '.')
			t.insertNodeL(x, y);
		if (z != '.')
			t.insertNodeR(x, z);
	}
	t.PreOrder(t.root);
	cout << "\n";
	t.InOrder(t.root); 
	cout << "\n";
	t.PostOrder(t.root);
	cout << "\n";

}