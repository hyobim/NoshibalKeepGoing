#include<iostream>
#include<vector>
using namespace std;

class Heap {
public:
	int heapsize; //���� ���� ũ��
	int dir; //min heap���� ���� -1, max heap�̸� 1
	vector<int> v; //���� �����͸� ��� ����
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
		//���� ���� ���� ������ ����
		int idx = heapsize;

		while (idx > 1) {
			//���� ���� idx �����Ͱ� �θ��� �����ͺ��� ũ�� swap()
		}
	}
	void downHeap() {
		//root���� ����
		int idx = 1;
		//���ʰ� �������� � �ڽİ� ������
		int t_idx;
		while (idx * 2 <= heapsize) { //���� �ش� ����� �ڽ��� ������
			int left = 2 * idx;
			int right = 2 * idx + 1;
			//���� ������ �ڽĵ� �ִٸ� �����ڽİ� ������ �ڽ��� ��ū �����͸� ������ �ִ� �ڽ��� t_idx�� �Ѵ�.
			if (right <= heapsize) {
			}
			else t_idx = left;

			//t_idx�� idx ��ȣ�� ��� �񱳿���
		}
	}

	void insert(int x) { //���Կ���

	}
	void pop() { //���� ����
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