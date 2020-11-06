#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap {
public:
	int heapsize; //���� ���� ũ��
	int direction; //min heap���� ���� -1, max heap�̸� 1
	int root;
	vector<int> v; //���� �����͸� ��� ����
	Heap(int d) {
		heapsize = 0;
		direction = d;
		root = 1;
		v.push_back(-1); //0���ε����� ������ �̷����� 
	}
	void swap(int x, int y) {
		int tmp = v[x];
		v[x] = v[y];
		v[y] = tmp;
	}
	void upHeap(int idx) { //��������� �۵�
						   //���� ���� ���� ������ ����
		if (idx == root) return; //��������
		else {
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction) { //�̺κ� ����
				swap(parent, idx);
				upHeap(parent);
			}
		}

	}
	void downHeap(int idx) {
		//root���� ����
		//���ʰ� �������� � �ڽİ� ������
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heapsize) { //���ʿ� ��� ���� �ִ°��
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction)
				{
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else { //�������ڽ��� ���񱳴���ΰ��
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHeap(right);
				}
				else return;
			}
		}
		else if (left <= heapsize)//���ʿ��� �����ִ°��
		{
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else return; //���ʸ�ξ��°��
	}

	void insert(int x) { //���Կ���
		v.push_back(x);
		heapsize++;
		upHeap(heapsize);
	}
	int pop() { //���� ����
		int top = v[root];
		v[root] = v[heapsize];
		heapsize--;
		v.pop_back();
		downHeap(root);
		return top;
	}
	int isEmpty() {
		if (heapsize == 0)
			return 1;
		else
			return 0;
	}
	int top() {
		return v[root];
	}
	void print() {
		if (heapsize != 0) {
			for (int i = root; i < heapsize; i++) {
				cout << v[i] << " ";
			}
			cout << v[heapsize] << endl;
		}
		else cout << -1 << endl;
	}
	int fint(int x) {
		if (heapsize != 0) return v.at(x);
	}
};
int main() {
	int test_case;
	string cmd;
	cin >> test_case;
	int n = 0;
	Heap q(MIN);
	while (test_case--) {
		cin >> cmd;

		if (cmd == "insert") {
			cin >> n;
			q.insert(n);
		}
		else if (cmd == "isEmpty") {
			cout << q.isEmpty() << endl;
		}
		else if (cmd == "pop")
		{
			cout << q.pop() << endl;
		}
		else if (cmd == "size") {
			cout << q.heapsize << endl;
		}
		else if (cmd == "top") {
			cout << q.top() << endl;
		}
		else if (cmd == "print") {
			q.print();
		}
	}
	return 0;
}