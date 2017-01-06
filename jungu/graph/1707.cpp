#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
/*
1. �׽�Ʈ ���̽�, ����, ���� ����
2. �׷����� �����
3. dfs ����
4. �������� 1, �������� 2
5. 1�̳� 2�� �ƴ� ���� ���ؼ� dfs �ٽ� ����
6. ���� �ڿ� ���� �� ���鳢�� ��ȣ�� ������ �̺б׷��� �ƴ�
*/

using namespace std;
vector<int> a[20001];
int num[20001];

void dfs(int x, int y) {

	num[x] = y;
	for (int i = 0; i < a[x].size(); i++) {
		int n = a[x][i];
		if (num[n] == 0) {
			dfs(n, 3 - y);
		}
	}
}

int main() {

	int t;
	cin >> t;
	bool bi = false;

	while (t--) {

		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			num[i] = 0;
		}

		for (int i = 0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (num[i] == 0) {
				dfs(i, 1);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j<a[i].size(); j++) {
				int k = a[i][j];
				if (num[i] != num[k]) {
					bi = true;
				}
			}
		}
		if (bi == true)
			printf("%s\n", "YES");
		else if (bi == false)
			printf("%s\n", "NO");
	}
}