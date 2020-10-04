#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

BTreeNode * MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);
	int i;

	for (i = 0; i<expLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))		// 피연산자라면...
		{
			SetData(pnode, exp[i] - '0');
		}
		else					// 연산자라면...
		{
			MakeRightSubTree(pnode, stack.pop(&stack));
			MakeLeftSubTree(pnode, stack.pop(&stack));
			SetData(pnode, exp[i]);
		}

		stack.push(&stack, pnode);
	}

	return stack.pop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) //단말노드라면
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		cout << data; //피연산자출력
	else
		cout << (char)data;  //연산자출력
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}

int main() {
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);
	
	cout << "전위 표기법의 수식: ";
	ShowPrefixTypeExp(eTree); 
	cout << "\n";

	cout << "중위 표기법의 수식: ";
	ShowInfixTypeExp(eTree);
	cout << "\n";

	cout << "후위 표기법의 수식: ";
	ShowPostfixTypeExp(eTree);
	cout << "\n";

	cout << "연산의 결과 : " << EvaluateExpTree(eTree) << "\n";

}