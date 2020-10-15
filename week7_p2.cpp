#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int fsize;
	Node* Parent;
	vector<Node*> Childlist;

	Node() {
		fsize = 0;
		Parent = NULL;
	}
};

class Tree {
public:
	Node * root;
	Node*  node;
	int result;

	Tree(int nodesize) {
		node = new Node[nodesize+1]; //노드배열 동적할당
		root = &node[1]; //1번배열이 루트가 됨 
		result = 0;
	}
	void insert(int i,int fsize) {
		node[i].fsize = fsize;
	}

	void makeChild(int pn, int cn) {
		node[pn].Childlist.push_back(&node[cn]);
		node[cn].Parent = &node[pn];
	}
	void fsizeC(int num) {
		result = 0;
		postOrder(&node[num]);
		cout << result << "\n";
	}
	void postOrder(Node* d) {
		if (d==NULL)
			return;

		for (int i = 0; i < d->Childlist.size(); i++) {
			postOrder(d->Childlist[i]);
		}
		result = result + d->fsize;
	}
};
int main() {
	int N, C;
	int data, size;
	cin >> N >> C;
	Tree* t = new Tree(N);

	for (int i = 0; i < N; i++) {
		cin >> data >> size;
		t->insert(data, size);
	}
	int pa;
	
	for (int i = 0; i < N; i++) {
		cin >> pa;
		int ch = 1;
		while (ch)
		{
			cin >> ch;
			if (ch == 0)
				break;
			t->makeChild(pa, ch);
		}
	}
	int f;
	while (C--)
	{
		cin >> f;
		t->fsizeC(f);
	}
}