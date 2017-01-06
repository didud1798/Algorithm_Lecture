/*
1. A, P�� ����
2. ���� D�� �����ϰ�
3. A, P�� ���� D�� ����
4. ��� �����鼭 ������ ����� ī��Ʈ
5. ������ ������� ���� ����� �ű⼭���� �ݺ���
6. ������ ������� ���� ����� �������� ��
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
int c[10000000];

int times(int x, int p) {

	int ans = 1;

	for (int i = 0; i<p; i++) {
		ans = ans * x;
	}
	return ans;
}

int next(int a, int p) {

	int ans = 0;

	while (a > 0) {
		ans += times(a % 10, p);
		a /= 10;
	}
	return ans;
}

int length(int a, int p, int cnt) {

	if (c[a] != 0) {
		return c[a] - 1;
	}
	c[a] = cnt;
	int b = next(a, p);
	return length(b, p, cnt + 1);
}

int main() {

	int a, p;
	cin >> a >> p;
	memset(c, 0, sizeof(c));
	printf("%d\n", length(a, p, 1));

}