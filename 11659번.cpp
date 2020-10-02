#include <iostream>
using namespace std;
//prefix sum 기억하기 

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int arr[100001],s[100001], N,M; //배열원소저장,합저장,수의 개수, 합을 구해야하는 횟수
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