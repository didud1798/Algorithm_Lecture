/*
1. ������ ũ�� N�� ����
2. ������ ������ ���� - ��ķ�
3. ���� �� ����Ʈ�� ���Ͽ� �̿� ���� �ľ� - bfs ����
4. �̿��� ����Ʈ�� ���� ������ ����
5. �� ���� ���� �� ä�� ���� �ִ��� �ľ�
6. ������������ �����ϰ� ���
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int a[30][30];
int complex[30][30];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
vector<int> ans;

void bfs(int x, int y, int cnt) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	complex[x][y] = cnt;

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && complex[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					complex[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf_s("%1d", &a[i][j]);
		}
	}

	int cnt = 0;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (a[i][j] == 1 && complex[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}

	printf("%d\n", cnt);
	// �� ������ ���

	int test = cnt;
	while (test) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == test)
					ans[test]++;
			}
		}
		test--;
	}

	sort(ans.begin(), ans.end());

	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}
}