#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;
char a[600000];

int main() {

	cin >> a;
	stack<char> left, right; // Ŀ�� ���� ������
	
	int n = strlen(a);

	for (int i = 0; i<n; i++) {
		left.push(a[i]); // Ŀ���� ���ʿ� ���ڸ� ���� ����
	}

	int m; //��ɾ� ����
	cin >> m;

	while (m--) {

		char order;
		cin >> order;

		if (order == 'L') {
			if (!left.empty()) { //Ŀ���� ���ʿ� ���ڰ� �ִ� ���
				right.push(left.top());
				left.pop();
			}
			// Ŀ���� ���ʿ� ���ڰ� ���� ��� ���õǴ� else �ʿ� ����
		}
		else if (order == 'D') {

			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}

		else if (order == 'B') {
			if (!left.empty()) {
				left.pop();
			}

		}
		else if (order == 'P') {
			char c;
			scanf(" %c", &c);
			left.push(c);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	printf("\n");

}