#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
/*
1. ����, ����, ������ ����
2. �׷����� �����
3. dfs, bfs ����
*/

using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int x) {

	check[x] = true;
	printf("%d ", x);

	for (int i = 0; i<a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

void bfs(int start) {

	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);

	while (!q.empty()) {

		int x = q.front();
		q.pop();
		printf("%d ", x);

		for (int i = 0; i<a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {

	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	} // �׷����� ����

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	} // ���� ��ȣ�� ���� ���� ���� �湮�Ѵٴ� ���� ������ �����

	dfs(start);
	printf(" ");
	bfs(start);
	printf(" ");

}