#include <iostream>
#include <string>

using namespace std;
int prime[1000000]; // �����佺�׳׽��� ü���� �ɷ��� �Ҽ� �迭
int num = 0;
bool c[1000001];

int main() {
	// �����佺�׳׽��� ü
	c[0] = c[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (c[i] == false) {
			prime[num] = i;
			num++;
			for (int j = i + i; j <= 1000000; j += i) {
				c[j] = true;
			}
		}
	}

	while (1) {
		int n; // �Է¹޴� ¦��
		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 1; i < num; i++) {
			if (c[n - prime[i]] == false) {
				printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
				break;
			}
		}
	}

}