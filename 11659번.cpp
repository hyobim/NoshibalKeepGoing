#include <iostream>
using namespace std;
//prefix sum ����ϱ� 

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int arr[100001],s[100001], N,M; //�迭��������,������,���� ����, ���� ���ؾ��ϴ� Ƚ��
	int i, j;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		s[i] = s[i - 1] + arr[i];
	}
	while (M--) {
		cin >> i >> j;
		cout << s[j] - s[i-1] << "\n";
	}
}