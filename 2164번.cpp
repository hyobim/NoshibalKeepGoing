#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() { //»ý¼ºÀÚ
		data = 0;
		next = NULL;
	}
};

class LinkedList {
public:
	Node * head;
	Node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	int removeFront() {
		if (head == NULL)
			return -1;
		else
		{
			Node* tmp = new Node;
			tmp = head;
			int tmpp = tmp->data;
			head = tmp->next;
			delete tmp;
			return tmpp;
		}

	}
	void addEnd(int x) {
		Node* newnode = new Node;
		newnode->data = x;
		newnode->next = NULL;
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}
};
class Queue {
public:

	LinkedList * list;
	int turn;
	int size;

	Queue() {
		list = new LinkedList();
		turn = 1;
		size = 0;
	}

	int Size() {
		return size;
	}

	int empty() {
		if (size == 0)
			return 1;
		else
			return 0;
	}
	void push(int x)
	{
		list->addEnd(x);
		size++;
	}
	int pop() {
		int s = list->removeFront();
		if (s != -1)
		{
			turn++;
			size--;
		}
		return s;
		
	}
	int front() {
		if (size == 0)
			return -1;
		else
		{
			return list->head->data;
		}
	}
	int back() {
		if (size == 0)
			return -1;
		else
		{
			return list->tail->data;
		}
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Queue q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size != 1)
	{
		if (q.turn % 2 == 0) {
			q.push(q.pop());
		}
		else if (q.turn % 2 == 1) {
			q.pop();
		}
	}
	cout << q.front() << "\n";

}