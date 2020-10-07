#include <iostream>
#include<string>
using namespace std;

class Node {
public:
	double data;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}
};

class Struct {
public:
	Node * head;
	Node* tail;
	int size;

	Struct() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	double ShowTop() {
		if (size == 0)
			return 0;
		else
			return tail->data;
	}
	int Size() { return size; }
	void push(double c) {
		Node* newnode = new Node;
		newnode->data = c;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else
		{
			newnode->next = tail;
			tail = newnode;
		}
		size++;
	}
	double pop() {
		if (size == 0)
			return 0;
		else {
			Node* tmp = new Node;
			tmp = tail;
			double tmpp = tmp->data;
			tail = tail->next;

			delete tmp;
			size--;
			return tmpp;
		}
	}
};

int main() {
	Struct s;
	int n;
	double arr[26];
	double a, b;
	cin >> n;
	string command;
	cin >> command;

	int size = command.length();
	
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < size; i++) {
		if (int(command[i]) >= 65) {
			s.push(arr[int(command[i]) - 65]);
		}
		else if (command[i] == '*')
		{
			a = s.pop();
			b = s.pop();
			s.push(a*b);
		}
		else if (command[i] == '/')
		{
			a = s.pop();
			b = s.pop();
			s.push(b/a);
		}
		else if (command[i] == '-')
		{
			a = s.pop();
			b = s.pop();
			s.push(b - a);
		}
		else if (command[i] == '+')
		{
			a = s.pop();
			b = s.pop();
			s.push(b + a);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.pop() << "\n";
}

