#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node {
public:
	int Data;
	Node* Parent;
	vector<Node*> Child;

	Node(int data){
		Data = data;
		Parent = NULL;
	}

	void setParent(Node* parent) {
		this->Parent = parent;
	}
	void insertChild(Node* child) {
		this->Child.push_back(child);
	}
	void delChild(Node* child) {
		for (int i = 0; i < this->Child.size(); i++) {
			if (this->Child[i] == child)
				this->Child.erase(this->Child.begin() + i);
		}
	}
};

class Tree {
public:
	Node * root;
	vector<Node*> node_list;
	Tree(int d) {
		root = new Node(d);
		node_list.push_back(root);
	}

	int size() {
		return node_list.size();
	}
	void insertNode(int par_data, int data) { //�ش�θ��带 ã�� �ڽĳ��� �߰�
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->Data == par_data) {
				Node* node = new Node(data); //�ڽĳ�����
				node->setParent(node_list[i]); //����Ǻθ𸦼���
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				return;
			}
		}
	}
	void delNode(int data){ //��带 �����ϰ� �ڽ� ������ �θ����� �ڽ����� �߰� 
		Node* nownode;
		Node* par;
		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->Data == data) {
				nownode = node_list[i];
				if (nownode == root) //��Ʈ������ȵ�
					return;
				par = nownode->Parent;
				for (Node*& child : nownode->Child) { //���ο� �θ��ڽİ��迬��
					par->insertChild(child);
					child->Parent = par;
				}
				par->delChild(nownode); //�θ��ڽİ������
				this->node_list.erase(this->node_list.begin() + i); //����Ʈ���� �����ϱ�
				delete nownode; //������
			}
		}
		return;
	}
	void printChi(int data) { //�ش����� �ڽĳ����� ���
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->Data == data) {
				if (node_list[i]->Child.size() == 0)
				{
					cout << "0" << endl;
					return;
				}
				for (int j = 0; j < node_list[i]->Child.size(); j++) {
					cout << node_list[i]->Child[j]->Data << " ";
				}
				cout << endl;
				return;
			}
		}
	}
	void printSie(int data) { //���� �θ� ������ �ڽ� ������ ���

		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->Data == data) {
				if (node_list[i]->Parent == NULL) //��Ʈ���
				{
					cout << data << endl;
				}
				else {
					Node* par_node = node_list[i]->Parent;
					for (int j = 0; j < par_node->Child.size(); j++)
						cout << par_node->Child[j]->Data << " ";

					cout << endl;
					return;
				}
			
			}
		}
		cout << 0 << endl;
	}

};
int main() {
	int n;
	string str;

	cin >> n;
	Tree t=Tree(1);
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "insert") {
			int par, data;
			cin >> par >> data;
			t.insertNode(par, data);
		}
		else if (str == "delete") {
			int data;
			cin >> data;
			t.delNode(data);
		}
		else if (str == "print") {
			int data;
			cin >> data;
			cout << "- data's child - \n";
			t.printChi(data); // �ش����� �ڽĳ����� ���
			cout << "- data's siblings - \n";
			t.printSie(data);
		}
	}
}