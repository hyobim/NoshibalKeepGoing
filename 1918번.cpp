#include<iostream>
#include<string>
using namespace std;
//틀린이유 복습

class Node {
public:
	char data;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}
};
class Stack
{
public:
	int sizee;
	Node* top;
	Stack() {
		sizee = 0;
		top = NULL;
	}

	void push(char x);
	char pop();
	int size();
	int empty();
	int Top();
};
int Stack::size() {
	return sizee;
}
int Stack::empty() {
	if (sizee == 0)
		return 1;
	else
		return 0;
}
int Stack::Top() {
	if (sizee == 0)
		return -1;
	else
		return top->data;
}
char Stack::pop() {
	if (sizee == 0) {
		return -1;
	}
	else {
		Node* tmp = new Node;
		char tmpp = top->data;
		tmp = top;
		top = top->next;
		delete tmp;
		sizee--;
		return tmpp;
	}
}
void Stack::push(char x) {
	Node* newnode = new Node;
	newnode->data = x;
	newnode->next = NULL;

	if (sizee == 0)
		top = newnode;
	else {
		newnode->next = top;
		top = newnode;
	}
	sizee++;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Stack st;
	string command;
	cin >> command;
	int size = command.length();
	for (int i = 0; i < size; i++)
	{
		if (command[i] == '(')
			st.push(command[i]);
		else if (command[i] == ')')
		{
			while(st.Top()!='(')
			{
				cout << st.pop();
			}
			st.pop();
		}
		else if (command[i] == '*'||command[i]=='/') {
			while (st.Top()=='*' || st.Top()=='/')
			{
				cout << st.pop();
			}
			st.push(command[i]);
			
		}
		else if (command[i] == '+' || command[i] == '-') {
			while (st.Top()!='(' && st.size()!=0)
			{
					cout << st.pop();
			}
			st.push(command[i]);

		}
		else {
			cout << command[i];
		}

	}
	while (st.size()!=0) {
		cout << st.pop();
	}

}