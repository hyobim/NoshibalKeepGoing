#include <iostream>
#include<cmath>
using namespace std;

class Node {
public:
	int data;
	Node* pre;
	Node* next;
	Node() {
	
		pre = NULL;
		next = NULL;
	}
};
class Iterator {
public:
	Node * v;
	Iterator(Node* v) {
		this->v = v;
	}
	Iterator* operator++() {
		this->v = v->next;
		return this;
	}

};
class Sequence {
public:
	int size;
	Node* head;
	Node* tail;
	Sequence() {
		size = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->pre = head;
	}
	void insert(int i) {
		Node* newnode = new Node;
		newnode->data = i;
		newnode->pre = head;
		newnode->next = head->next;
		head->next->pre = newnode;
		head->next = newnode;
		size++;
	}
	Node* begin() {
		return head->next;
	}
	void Print(Iterator& p) {
		int max=0;
		double avg=0;
	
		while (p.v != tail)
		{

			avg = avg + p.v->data;
			if (p.v->data > max)
				max = p.v->data;
			++p;
		}
		cout << floor(avg / size) << " " << max << endl;
	}
};

int main() {
	int n, m, x;
	cin >> n;
	while (n--)
	{
		Sequence s;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			s.insert(x);
		}
		Iterator p(s.begin());
		s.Print(p);
	}
	
}