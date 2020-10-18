#include <iostream>
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
class LinkedList {
public:
	Node * start;
	Node* tail;
	int size;
	LinkedList() {
		start = NULL;
		tail = NULL;
		size = 0;
	}
	int sizee() {
		return size;
	}
	void insert(int num) {

		for (int i = 0; i < num; i++) {
			Node* newnode = new Node;
			newnode->data = i+1;
			if (start == NULL) {
				start = newnode;
				tail = newnode;
			}
			else {
				tail->next = newnode;
				tail = newnode;
			}
			size++;
		}
		tail->next = start;
	}
	void Delete(int num) {
		if (size == 1) {
			cout << start->data << ">\n";
			delete start;
			size--;
		}
		else {
			for (int i = 0; i < num-2;i++)
			{
				start = start->next;
			}
			Node* tmp = new Node;
			tmp = start->next;
			start->next = tmp->next;

			start = tmp->next;
			cout << tmp->data << ", ";

			delete tmp;
			size--;
		}
	}
};

int main() {
	LinkedList list;
	int m, n;

	cin >> m >> n;

	list.insert(m);
	cout << "<";
	while (list.sizee()!=0)
	{
		list.Delete(n);
	}
}