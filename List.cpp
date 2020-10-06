#include<iostream>
#include<string>
using namespace std;

/*p.element(): ��ġ p �� ��ġ�ϴ� ����� ���Ҹ� ��ȯ�ϴ� �Լ�
 >> ������ �����ε��� ���� *p��� ���� ! ! !!!*/
// �ݺ��� (iterators) : ���� ��ȸ�ϴ� ��ü 


// ���� ��ũ�� ����Ʈ -> �ΰ��� ��Ƽ�� ��� header�� trailer�� ����Ͽ� ����

class SequenceList {
private:
	struct Node
	{
		int e;
		Node* prev;
		Node* next;

	};
public:
	class iterator {
	private:
		Node * v; //�ݺ��ڰ� ����Ű�� ��带 �����ϱ����� �����ͺ���
		iterator(Node* u); //�ݺ��� ������
	public:
		int& operator*(); //�ݺ��ڰ� ����Ű���ִ� ��尡 ������ �ִ� ���Ұ� ��ȯ
		bool operator==(const iterator& p) const; //������� �ݺ��ڰ� ����Ű�� �ִ� ���p�� ��ġ�ϴ��� Ȯ��
		bool operator!=(const iterator& p) const;//������� �ݺ��ڰ� ����Ű�� �ִ� ���p�� ����ġ�ϴ��� Ȯ
		iterator& operator++(); //�������� �ݺ��� �̵�
		iterator& operator--(); //�������� �ݺ��� �̵�

		friend class SequenceList; //sequencelist�� iteratorŬ������ �����Ҽ��ֵ�������
	};

private:
	int n; //����Ʈ�� ũ��
	Node* header; 
	Node* trailer;
public:
	SequenceList();
	int size() const;
	bool empty() const;
	iterator begin() const; //�ݺ��ڸ� ��ó��������ġ��Ŵ 
	iterator end() const; //�ݺ��ڸ� trailer��忡 ��ġ��Ŵ 
	void insertFront(const int& e);
	void insertBack(const int& e);
	void insert(const iterator& p, const int& e);
	void eraseFront();
	void eraseBack();
	void erase(const iterator& p);
	void print(iterator& p);
	iterator atIndex(int i)const; //�ε��� i�� ���� ������ ��ġ�� ��ȯ
	int indexOf(const iterator& p)const; //��ġ p�� �ִ� ������ �ε����� ��ȯ
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

void SequenceList::insert(const SequenceList::iterator& p, const int& e) {
	Node* w = p.v; //��ġ p�� ��� 
	Node* u = w->prev; //��ġ p�ٷ��������
	Node* v = new Node; //���ӰԻ����� ��� �ʱ�ȭ 
	v->e = e;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	this->n++;
}

void SequenceList::insertFront(const int& e) {
	insert(begin(), e);
}
void SequenceList::insertBack(const int& e) {
	insert(end(), e);
}
void SequenceList::erase(const iterator& p) {
	Node* v = p.v;
	Node* w = v->next;
	Node* u = v->prev;
	u->next = w; w->prev = u;
	delete v;
	this->n--;
}

void SequenceList::eraseFront() {
	erase(begin());
}
void SequenceList::eraseBack() {
	erase(--end());
}
void SequenceList::print(iterator& p) {
	if(size() == 0)
		return;
	for (int i = 0; i < size(); i++) {
		cout << *p<<" ";
		++p;
	}
	cout << endl;
}
int SequenceList::size() const {
	return n;
}
bool SequenceList::empty() const {
	return(n == 0);
}
SequenceList::iterator::iterator(Node* u) {
	v = u;
}
SequenceList::iterator SequenceList::begin() const {
	return iterator(header->next);
}
SequenceList::iterator SequenceList::end() const {
	return iterator(trailer);
}
int& SequenceList::iterator::operator*() {
	return v->e;
}
bool SequenceList::iterator::operator==(const iterator& p)const {
	return v == p.v;
}
bool SequenceList::iterator::operator!=(const iterator& p)const {
	return v != p.v;
}
SequenceList::iterator& SequenceList::iterator::operator++() {
	v = v->next;
	return*this;
}
SequenceList::iterator& SequenceList::iterator::operator--(){
	v = v->prev;
	return*this;
}

SequenceList::iterator SequenceList::atIndex(int i)const {
	iterator p = begin();
	for (int j = 0; j < i; i++)
	{
		++p;
	}
	return p;
}

int SequenceList::indexOf(const iterator& p)const {
	iterator q = begin();
	int j = 0;
	while (q!=p)
	{
		++q;
		++j;
	}
	return j;
}

int main() {
	int T;
	cin >> T;

	SequenceList sl;
	SequenceList::iterator iter = sl.begin();

	for (int i = 0; i < T; i++) {
		string command;
		cin >> command;

		if (command == "insert")
		{
			int a;
			cin >> a;
			sl.insert(iter,a);
		}
		else if (command == "erase") {
			sl.erase(iter);
		}
		else if (command == "begin") {
			iter=sl.begin();
		}
		else if (command == "end") {
			iter=sl.end();
		}
		else if (command == "++") {
			iter=iter.operator++();
		}
		else if (command == "--") {
			iter=iter.operator--();
		}
		else if (command == "print") {
			sl.print(iter);
		}
		else if (command == "size") {
			cout << sl.size() << endl;
		}
		else {
			cout << "your command is wrong" << endl;
		}
	}
}