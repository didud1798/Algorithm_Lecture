#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
/*
1. ����, ���� ����
2. �׷����� �����
3. dfs ����
4. dfs�� �� ����Ŭ ���ư� ������ ������ +1
*/

using namespace std;
vector<int> a[1001];
bool check[1001];


void dfs(int x) {

	check[x] = true;

	for (int i = 0; i<a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

int main() {

	int n, m;
	int comp = 0;
	cin >> n >> m;

	for (int i = 0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	} // �׷����� ����

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			comp++;
		}
	}
	printf("%d\n", comp);
}