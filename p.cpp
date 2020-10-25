#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
};
class Queue {
public:
	Node * head;
	Node* tail;
	int size;
	Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insert(int data) {
		Node* newnode = new Node;
		newnode->data = data;
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		size++;
	}
	void deletee() {
		if (size == 0)
			return;
		Node* tmp = new Node;
		tmp = head;
		head = head->next;
		
		size--;
		delete tmp;
	
	}
	int front() {
		return head->data;
	}
};
int main() {
	
	int t,n;
	Queue p1;
	Queue p2;
	int pp1, pp2;
	int point1=0,point2 =0;
	cin >> t;
	while (t--)
	{
		
		cin >> n;
		int* arr1 = new int[n+1];
		int* arr2 = new int[n+1];
		for (int i = 0; i < n; i++)
		{
			cin >> pp1;
			arr1[i] = 0;
			p1.insert(pp1);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> pp2;
			arr2[i] = 0;
			p2.insert(pp2);
		}
		for (int i = 0; i < n; i++) {
			pp1 = p1.front()+arr1[i];
			pp2 = p2.front()+arr2[i];
			if (pp1> pp2) {
				p1.deletee();
				p2.deletee();
				arr1[i+1] = pp1-pp2 - 1;
				point1++;
			}
			else if (pp1<pp2) {
				p2.deletee();
				p1.deletee();
				arr2[i+1] = pp2-pp1 - 1;
				point2++;
			}
			else if (pp1== pp2)
			{
				p1.deletee();
				p2.deletee();
			}
		}
		if (point1 > point2)
			cout << "1" << endl;
		else if (point2 > point1)
			cout << "2" << endl;
		else
			cout << "0" << endl;
	}
}

