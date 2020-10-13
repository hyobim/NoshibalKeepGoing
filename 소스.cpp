#include <iostream>
#include<string>
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

class Stack {
public:
	int size;
	Node* top;

	Stack() {
		size = 0;
		top = NULL;
	}


	void pop() {
		if (size == 0)
			return;
		else {
			Node* tmp = new Node;
			tmp = top;
			int ttmp = tmp->data;
			top = top->next;
			delete tmp;
			size--;
			cout<< ttmp;
		}
	}
	void insert(int i){
		Node* newnode = new Node;
		newnode->data = i;
		if (top == NULL) {
			top = newnode;
		}
		else {
			newnode->next = top;
			top = newnode;
		}
		size++;
	}
};


int main() {
	Stack s;
	string num;
	cin >> num;

	for (int i = 0; i < num.length(); i++) {
		s.insert(num[i] - '0');
	}
	while (s.size !=0)
	{
		s.pop();
	}
	cout << "\n";
}