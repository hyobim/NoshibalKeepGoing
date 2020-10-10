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
	void insertNode(int par_data, int data) { //해당부모노드를 찾고 자식노드로 추가
		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->Data == par_data) {
				Node* node = new Node(data); //자식노드생성
				node->setParent(node_list[i]); //노드의부모를설정
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				return;
			}
		}
	}
	void delNode(int data){ //노드를 삭제하고 자식 노드들을 부모노드의 자식으로 추가 
		Node* nownode;
		Node* par;
		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->Data == data) {
				nownode = node_list[i];
				if (nownode == root) //루트면삭제안됨
					return;
				par = nownode->Parent;
				for (Node*& child : nownode->Child) { //새로운 부모자식관계연결
					par->insertChild(child);
					child->Parent = par;
				}
				par->delChild(nownode); //부모자식관계끊기
				this->node_list.erase(this->node_list.begin() + i); //리스트에서 삭제하기
				delete nownode; //노드삭제
			}
		}
		return;
	}
	void printChi(int data) { //해당노드의 자식노드들을 출력
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
	void printSie(int data) { //같은 부모를 가지는 자식 노드들을 출력

		for (int i = 0; i < size(); i++)
		{
			if (node_list[i]->Data == data) {
				if (node_list[i]->Parent == NULL) //루트노드
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
			t.printChi(data); // 해당노드의 자식노드들을 출력
			cout << "- data's siblings - \n";
			t.printSie(data);
		}
	}
}