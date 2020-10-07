/* 3004�� ������ ������
ù° �ٿ� �������� ���� N�� �Էµȴ�. ( 1 <= N <= 50,000)
��° �ٿ� �������� �и��Ǿ� N���� ���� �ٸ� �����Ͱ� �Էµȴ�. (���� ����:0~500,000)
N���� �����͸� 0 ~ N-1�� �������Ͽ� ����϶�.

�Է� ����)
5
50 23 54 24 123 

��� ����)
2 0 3 1 4

50 23 54 24 123 ����
23, 24, 50, 54, 123 ������ 0, 1, 2, 3, 4 �� �ȴ�.
�׸��� ������ ��ġ��� ����Ѵ�.
*/

/*
ó���� ���� �����ѰŴ� 2�� for ���� ���°ſ��� -> ���� �ڵ� �ּ� ���� 
�׷��� n�� ������ ������ �ִ� 50000���� �����߰� ,, ���� ������ ���� �ð��ʰ��� �Ǵ� ��찡 �߻��Ѵ� ..! > �̸� �Ǵ� �߾�� �ϴ� �� ���ߴ� .. 
�׷��� �ٸ� Ǯ�̸� ã�ƺôµ� �ٸ� ���� �˰����� �ʿ��ߴ� .,.,.... 

struct Data
{
int number;
int su;

};
bool cmp(const Data& D1, const Data& D2) {
if (D1.number <= D2.number)
return true;
else
return false;
}

int main() {
	int n;
	cin >> n;
	Data* d = new Data[n];
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> d[i].number;
		p[i] = d[i].number;
	}
	sort(p, p + n); //�迭�� �������� �������� -> ������� ��ȣ ȹ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (p[j] == d[i].number) //d �� num�� �ʱ� ������ ��ġ�������Ƿ� ������ �� ������ . 
				cout << j << " ";
	}
	delete[] d;
	delete[] p;

}*/

//���� ã�� Ǯ�̴� vector�� pair�� �̿��� Ǯ�� ���� .
/*
pair�� ?
pair<[type],[type]> ���� ���� ������ ���� ���� .first �� .second �� ���� �����ϴ� .
2���� ������ ���� ���� �����ؼ� �����Ѵ� 
!! Ư�� ������ 2���� ������ ������ ���ǿ� ���� ������ ����� ����� �� �� ����ϸ� ����.!!
-> ��, �ΰ��� ���� �������� ������ �ϰ� ���� ��! 

>>�� ������ ������ ���� ���� ������ 2���� ���̳� �ٸ� ���� �����̴� 
���� �ѹ� �ѵ�, �ٽ� ���� 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp1(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) { //�Է¹��� ������ �ø����� ����
	return a.first < b.first;
}
bool comp2(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
	return a.second.first < b.second.first;
}
int main() {
	int n;
	cin >> n;
	// <�Է¹��� ������ , <�Է¼������, ������ ������ >>
	vector<pair<int, pair<int, int>>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second.first = i; //�Է¼������
	}
	sort(arr.begin(), arr.end(), comp1);
	for (int i = 0; i < n; i++)
		arr[i].second.second = i; //�����ĵ�����
	sort(arr.begin(), arr.end(), comp2); 
	for (int i = 0; i < n; i++) cout << arr[i].second.second << " ";
}