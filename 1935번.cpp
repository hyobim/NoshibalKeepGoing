#include<iostream>
#include<string>
#include <ctype.h>
using namespace std;

class BTNode {
public:
	int data;
	BTNode* left;
	BTNode* right;

	BTNode* MakeBTreeNode() {
		BTNode* newnode = new BTNode;
		newnode->left = NULL;
		newnode->right = NULL;

		return newnode;
	}

	int getData(BTNode* bt) {
		return bt->data;
	}
	void setData(BTNode* bt, int d) {
		bt->data = d;
	}
	BTNode* getLeft(BTNode* bt) {
		return bt->left;
	}
	BTNode* getRight(BTNode* bt) {
		return bt->right;
	}
	void setLeft(BTNode* main, BTNode* sub) {
		if (main->left != NULL)
			delete(main->left);
		else
			main->left = sub;
	}
	void setRight(BTNode* main, BTNode* sub) {
		if (main->right != NULL)
			delete(main->right);
		else
			main->right = sub;
	}
};
typedef BTNode* Data;

class Node
{
public:
	Data data; //btnode의 주소값을 저장함 
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	
};
class stack {
public:
	Node * tail;
	Node* head;
	int size;
	stack() {
		size = 0;
		tail = NULL;
		head = NULL;
	}
	Data peek(stack* st) {
		if (size == 0)
			return NULL;
		else
		{
			return st->tail->data;
		}
	}
	Data pop(stack* st) {
		if (size == 0)
			return NULL;
		else
		{
			Node* tmp = new Node;
			tmp = tail;
			Data tmmp = tmp->data;
			tail = tail->next;

			delete tmp;
			return tmmp;
		}
		size--;
	}
	void push(stack* st , Data x) {
		Node* newnode = new Node;
		newnode->data = x;
		newnode->next = NULL;
		if (st->head == NULL)
		{
			st->head = newnode;
			st->tail = newnode;
		}
		else {
			newnode->next = st->tail;
			st->tail = newnode;
		}
		size++;
	
	}
	
};
Data MakeExpTree(string exp, int a[]) {
	stack s;

	BTNode* pn=NULL;


	int exl = exp.length();
	for (int i = 0; i < exl; i++) {

		pn= pn->MakeBTreeNode();

		if (int(exp[i])>=65) {
			pn->setData(pn, a[int(exp[i])-65]);
		}
		else {
			pn->setRight(pn, s.pop(&s));
			pn->setLeft(pn, s.pop(&s));
			pn->setData(pn, exp[i]);
		}

		s.push(&s , pn);
	}
	return s.pop(&s);
}
double EvaluateExpTree(BTNode* bt) {
	double op1, op2;
	if (bt->getLeft(bt) == NULL && bt->getRight(bt) == NULL)
		return bt->getData(bt);

	op1 = EvaluateExpTree(bt->getLeft(bt));
	op2 = EvaluateExpTree(bt->getRight(bt));
	switch (bt->getData(bt))
	{
	case'+':
		return op1 + op2;
	case'-':
		return op1 - op2;
	case'*':
		return op1 * op2;
	case'/':
		return op1 / op2;
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, a[26];
	cin >> n;
	string exp;
	cin >> exp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	BTNode* etree = MakeExpTree(exp,a);
	cout << fixed;
	cout.precision(2);
	cout<<EvaluateExpTree(etree)<<"\n";
}