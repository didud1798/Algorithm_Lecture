/*
1. ������ ���� ���� ���� (n,m)
2. �丶�� ���� ���� - ��ķ�
3. ���� �丶�� ���� ������ �丶��� �Ϸ� �� ����
4. �丶�䰡 ������ ȿ�� ���� // ���� �丶��� ���� X
5. ���� �� ��� �丶�䰡 ���� ������ �ɸ� �� �� ����
6. ���
7. ��� �丶�䰡 ���� ���ϴ� ��� -1 ���
*/


#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;
int a[1000][1000];
int grow[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && grow[nx][ny] == -1) {
					grow[nx][ny] = grow[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf_s("%d", &a[i][j]);
			grow[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				grow[i][j] = 0;
				bfs(i, j);
			}
		}
	}

	int ans = 0;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (ans < grow[i][j]) {
				ans = grow[i][j];
			}
		}
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (a[i][j] == 0 && grow[i][j] == -1) {
				ans = -1;
			}
		}
	}
	printf("%d\n", ans);
}