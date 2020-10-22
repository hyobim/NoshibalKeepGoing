#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	char data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
};

class Stack {
public:
	Node * top;
	int size;
	int sp;

	Stack() {
		top = NULL;
		size = 0;
		sp = 0;
	}
	void check(Node* n) {
		Node* a = n->next;
		if (size!=2&&a->data == a->next->data)
		{
			for (int i = 0; i < 3; i++)
				pop();
		}
		else
			return;
	}
	void push(char a) {

		size++;
		Node* newn = new Node;
		newn->data = a;
		newn->next = NULL;
		if (top == NULL) {
			top = newn;
		}
		else {
			newn->next = top;
			top = newn;
			if (newn->data == newn->next->data)
				check(newn);
		}
		
		
	}
	int sizec() {
		if (size >= 10)
			return 0;
		else
			return 1;
	}
	void pop() {
		if (size == 0)
			return;

		Node* tmp = new Node;
		tmp = top;
		top = top->next;

		size--;
		delete tmp;
	}
};

int main() {
	int n;
	string line;

	cin >> n;
	while (n--)
	{
		Stack s;
		cin >> line;
		for (int i = 0; i < line.length(); i++) {
			s.push(line[i]);
			if (i == 9) {
				if (s.sizec() == 0)
					break;
				else
					continue;
			}
		}
		cout << s.sizec() << endl;
	}
}