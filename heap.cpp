#include<iostream>
#include<vector>
using namespace std;

class Heap {
public:
	int heapsize; //현재 힙의 크기
	int dir; //min heap으로 쓰면 -1, max heap이면 1
	vector<int> v; //실제 데이터를 담는 변수
	Heap(int d) {
		heapsize = 0;
		dir = d;
		v.push_back(-1);
	}
	void swap(int x, int y) {
		int tmp = v[x];
		v[x] = v[y];
		v[y] = tmp;
	}
	void upHeap() {
		//힙의 가장 끝의 노드부터 시작
		int idx = heapsize;

		while (idx > 1) {
			//만약 현재 idx 데이터가 부모의 데이터보다 크면 swap()
		}
	}
	void downHeap() {
		//root부터 시작
		int idx = 1;
		//왼쪽과 오른쪽중 어떤 자식과 비교할지
		int t_idx;
		while (idx * 2 <= heapsize) { //만약 해당 노드의 자식이 있을때
			int left = 2 * idx;
			int right = 2 * idx + 1;
			//만약 오른쪽 자식도 있다면 왼쪽자식과 오른쪽 자식중 더큰 데이터를 가지고 있는 자식을 t_idx로 한다.
			if (right <= heapsize) {
			}
			else t_idx = left;

			//t_idx와 idx 번호의 노드 비교연산
		}
	}

	void insert(int x) { //삽입연산

	}
	void pop() { //삭제 연산
	}
};
int main() {
	int test_case;
	cin >> test_case;
	int n, x, p;
	while (test_case--) {

	}
	return 0;
}