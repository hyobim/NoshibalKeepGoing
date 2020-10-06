#include<iostream>
#include<string>
using namespace std;

/*p.element(): 위치 p 에 위치하는 노드의 원소를 반환하는 함수
 >> 연산자 오버로딩을 통해 *p사용 가능 ! ! !!!*/
// 반복자 (iterators) : 원소 순회하는 객체 


// 이중 링크드 리스트 -> 두개의 센티널 노드 header와 trailer에 기반하여 구현

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
		Node * v; //반복자가 가리키는 노드를 저장하기위한 포인터변수
		iterator(Node* u); //반복자 생성자
	public:
		int& operator*(); //반복자가 가리키고있는 노드가 가지고 있는 원소값 반환
		bool operator==(const iterator& p) const; //현재노드와 반복자가 가리키고 있는 노드p와 일치하는지 확인
		bool operator!=(const iterator& p) const;//현재노드와 반복자가 가리키고 있는 노드p와 불일치하는지 확
		iterator& operator++(); //다음노드로 반복자 이동
		iterator& operator--(); //이전노드로 반복자 이동

		friend class SequenceList; //sequencelist가 iterator클래스에 접근할수있도록해줌
	};

private:
	int n; //리스트의 크기
	Node* header; 
	Node* trailer;
public:
	SequenceList();
	int size() const;
	bool empty() const;
	iterator begin() const; //반복자를 맨처음노드로위치시킴 
	iterator end() const; //반복자를 trailer노드에 위치시킴 
	void insertFront(const int& e);
	void insertBack(const int& e);
	void insert(const iterator& p, const int& e);
	void eraseFront();
	void eraseBack();
	void erase(const iterator& p);
	void print(iterator& p);
	iterator atIndex(int i)const; //인덱스 i를 갖는 원소의 위치를 반환
	int indexOf(const iterator& p)const; //위치 p에 있는 원소의 인덱스를 반환
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

void SequenceList::insert(const SequenceList::iterator& p, const int& e) {
	Node* w = p.v; //위치 p의 노드 
	Node* u = w->prev; //위치 p바로이전노드
	Node* v = new Node; //새롭게삽입할 노드 초기화 
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