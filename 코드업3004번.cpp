/* 3004번 데이터 재정렬
첫째 줄에 데이터의 개수 N이 입력된다. ( 1 <= N <= 50,000)
둘째 줄에 공백으로 분리되어 N개의 서로 다른 데이터가 입력된다. (값의 범위:0~500,000)
N개의 데이터를 0 ~ N-1로 재정렬하여 출력하라.

입력 예시)
5
50 23 54 24 123 

출력 예시)
2 0 3 1 4

50 23 54 24 123 에서
23, 24, 50, 54, 123 순서로 0, 1, 2, 3, 4 가 된다.
그리고 원래의 위치대로 출력한다.
*/

/*
처음에 내가 생각한거는 2중 for 문을 쓰는거였다 -> 밑의 코드 주석 참조 
그런데 n의 데이터 갯수가 최대 50000까지 가능했고 ,, 이중 포문을 쓰면 시간초과가 되는 경우가 발생한다 ..! > 미리 판단 했어야 하는 데 못했다 .. 
그래서 다른 풀이를 찾아봤는데 다른 정렬 알고리즘이 필요했다 .,.,.... 

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
	sort(p, p + n); //배열을 오름차순 정렬해줌 -> 순서대로 번호 획득
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (p[j] == d[i].number) //d 의 num이 초기 순서로 위치해있으므로 재정렬 된 상태임 . 
				cout << j << " ";
	}
	delete[] d;
	delete[] p;

}*/

//내가 찾은 풀이는 vector의 pair를 이용한 풀이 였다 .
/*
pair란 ?
pair<[type],[type]> 으로 정의 저장한 값은 각각 .first 와 .second 로 접근 가능하다 .
2개의 연관된 값을 같이 저장해서 관리한다 
!! 특히 연관된 2개의 값에서 각각의 조건에 따라 정렬한 결과를 얻고자 할 때 사용하면 좋다.!!
-> 즉, 두개의 정렬 조건으로 정렬을 하고 싶을 때! 

>>이 문제에 적합한 이유 정렬 조건이 2개인 것이나 다름 없기 때문이다 
정렬 한번 한뒤, 다시 정렬 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp1(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) { //입력받은 데이터 올림차순 정렬
	return a.first < b.first;
}
bool comp2(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
	return a.second.first < b.second.first;
}
int main() {
	int n;
	cin >> n;
	// <입력받을 데이터 , <입력순서기록, 재정렬 데이터 >>
	vector<pair<int, pair<int, int>>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second.first = i; //입력순서기록
	}
	sort(arr.begin(), arr.end(), comp1);
	for (int i = 0; i < n; i++)
		arr[i].second.second = i; //재정렬데이터
	sort(arr.begin(), arr.end(), comp2); 
	for (int i = 0; i < n; i++) cout << arr[i].second.second << " ";
}