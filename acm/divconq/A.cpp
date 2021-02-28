#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	int n; cin >> n;
	string answer = "";
	// n : max segments

	while (n > 0) {
		if (n % 2 == 1) {
			n -= 3;
			answer.push_back('7');
		}
		else {
			n -= 2;
			answer.push_back('1');
		}
	}

	cout << answer << endl;

	return;
}

/*
���� - ����

���� 2�� : 1
���� 3�� : 7
���� 4�� : 4
���� 5�� : 5
���� 6�� : 9
���� 7�� : 8

segment �� �Ⱦ��� 998244353���� ���� ���


3�̸� 7�� ����
4�� 11�� ����
5�� 71�� ����
6�̸� 111
7�̸� 711

*/