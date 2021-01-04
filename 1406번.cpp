#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> stack1;
	stack<char> stack2;
	string cmd;
	cin >> cmd;
	
	for (int i = 0; i < cmd.length(); i++) {
		stack1.push(cmd[i]);
	}

	int n;
	char line;
	cin >> n;

	while (n--)
	{
		cin >> line;
		char x;
		if (line == 'P')
		{
			cin >> x;
			stack1.push(x);

		}
		else if (line == 'L')
		{
			if (!stack1.empty()) {
			
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		else if (line == 'B')
		{
			if (!stack1.empty()) {
				stack1.pop();
			}
		}
		else if(line=='D')
		{

			if (!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
	}

	while (!stack1.empty())
	{
		stack2.push(stack1.top());
		stack1.pop();
	}
	while (!stack2.empty())
	{
		cout << stack2.top();
		stack2.pop();
	}
	cout<<"\n";
}
