#include <iostream>
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

	Stack() {
		top = NULL;
		size = 0;
	}
	char pop() {
		if (size == 0)
			return -1;
		else {
			Node* tmp = new Node;
			tmp = top;
			char ttmp = tmp->data;
			top = top->next;

			delete tmp;
			size--;
			return ttmp;
		}
	}
	void push(char a) {
		Node* newnode = new Node;
		newnode->data = a;
		newnode->next = NULL;
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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string stmt;
	char x;
	
	while (true) {
		Stack s;
		getline(cin, stmt);
		if (stmt[0] == '.')
			break;
		for (int i = 0; i < stmt.length(); i++) {
			if (stmt[i] == '(' || stmt[i] == '[') {
				s.push(stmt[i]);
			}
			else if (stmt[i] == ')') {
				x = s.pop();
				if (x != '(' || x == '-1') {
					s.push(x);
					break;
				}
			}
			else if (stmt[i] == ']') {
				x = s.pop();
				if (x != '[' || x == '-1') {
					s.push(x);
					break;
				}
			}
		}

		if (s.size == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
		
}