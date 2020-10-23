#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
	int data;
	Node* pre;
	Node* next;
	Node() {
		data = 0;
		pre = NULL;
		next = NULL;
	}
};
class DLinkedList {
public:
	Node * head;
	Node* tail;
	int avg;
	int max;
	int size;
	DLinkedList() {
		avg = 0;
		max = 0;
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insert(int i){
		Node* newnode = new Node;
		newnode->data = i;
		if (head == NULL)
		{
			newnode->pre = head;
			newnode->next = tail;
			head = newnode;
			tail = newnode;

		}
		else {
			newnode->pre = tail;
			tail->next = newnode;
			tail = newnode;
		}
		size++;
	}
	void iterator() {
		Node* ite = head;
		int a = size;
		while (size--)
		{
			avg = avg + ite->data;
			if (ite->data > max)
				max = ite->data;
			ite = ite->next;
		}
		cout << floor(avg / a) << " " << max << endl;
	}
};
int main() {
	int n,m,an;
	cin >> n;
	while (n--)
	{
		DLinkedList d;
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> an;
			d.insert(an);
		}
		d.iterator();
	}
}