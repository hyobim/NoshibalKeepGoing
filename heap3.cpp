#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap {
public:
	int heapsize; //현재 힙의 크기
	int direction; //min heap으로 쓰면 -1, max heap이면 1
	int root;
	vector<int> v; //실제 데이터를 담는 변수
	Heap(int d) {
		heapsize = 0;
		direction = d;
		root = 1;
		v.push_back(-1); //0번인덱스를 비우려고 이렇게함 
	}
	void swap(int x, int y) {
		int tmp = v[x];
		v[x] = v[y];
		v[y] = tmp;
	}
	void upHeap(int idx) { //재귀적으로 작동
						   //힙의 가장 끝의 노드부터 시작
		if (idx == root) return; //종료조건
		else {
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction) { //이부분 이해
				swap(parent, idx);
				upHeap(parent);
			}
		}

	}
	void downHeap(int idx) {
		//root부터 시작
		//왼쪽과 오른쪽중 어떤 자식과 비교할지
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heapsize) { //양쪽에 모두 값이 있는경우
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction)
				{
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else { //오른쪽자식이 더비교대상인경우
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHeap(right);
				}
				else return;
			}
		}
		else if (left <= heapsize)//왼쪽에만 값이있는경우
		{
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else return; //양쪽모두없는경우
	}

	void insert(int x) { //삽입연산
		v.push_back(x);
		heapsize++;
		upHeap(heapsize);
	}
	int pop() { //삭제 연산
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