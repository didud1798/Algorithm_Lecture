/*
1. �迭�� ǥ���Ǵ� �̷θ� ����.
2. ����� (1,1) ������ (M,N)
3. ��������� M,N���� ���� ��θ� bfs�� ����
4. �� �� �鸰 ���� üũ
5. bfs �ѹ� �� ������ ī��Ʈ+1
6. ī��Ʈ ������ �ʱⰪ 1
*/

#include <cstdio>
#include <queue>

using namespace std;

int n, m;
int a[100][100];
bool c[100][100];
int cnt[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


int main() {

	cin >> n >> m;
	c[0][0] = true;
	cnt[0][0] = 1;

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (c[nx][ny] == false && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					cnt[nx][ny] = cnt[x][y] + 1;
					c[nx][ny] = true;
				}
			}
		}
	}

	printf("%d\n", cnt[n][m]);

}