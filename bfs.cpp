#include <iostream>
#include<queue>
#include <vector>
using namespace std;


vector<int> graphlist[20000];
bool check[20000] = { 0, };

void bfs(int start) {
	queue<int> p1;
	p1.push(start);
	check[start] = true;
	cout << start << " ";
	int k = 0;
	while (p1.size()!=0)
	{
		k = p1.front();
		for (int i = 0; i < graphlist[k].size(); i++)
		{
			int next = graphlist[k][i];
			if (check[next] == false) {
				check[next] = true;
				cout << graphlist[k][i] << " ";
				p1.push(graphlist[k][i]);
			}
		}
		p1.pop();
	}
}

int search(int s, int j) {
	for (int i = 0; i < graphlist[s].size(); i++)
	{
		if (graphlist[s][i] == j) {
			cout << "-1" << endl;
			return 0;
		}
	}
	return 1;
}
int main() {
	int n, m, start;
	int x;
	cin >> n >> m >> start;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
	}
	for (int i = 0; i < m; i++)
	{
		int e, s;
		cin >> e >> s;
		if (search(e, s)) {
			graphlist[e].push_back(s);
			graphlist[s].push_back(e);
		}
	}
	bfs(start);
	cout << endl;
}