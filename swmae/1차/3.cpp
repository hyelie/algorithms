#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M, E;
	vector<int> location(N);
	for (int i = 0; i < N; i++) {
		cin >> location[i];
	}

	int curidx;		// ���� ��ġ���� �۰ų� ���� ������ idx
	for (int i = 0; i < N; i++) {
		if (E >= location[i]) {
			curidx = i;
			break;
		}
	}

	vector<bool> isred(N, false);	// true�� ���� �� ����
	vector<bool> iseaten(N, false);	// true�� ���� ��

	int eaten_num = 0;
	while (eaten_num != M) {
		if (curidx == N - 1) {	// ���� �� ������ ã�����

		}
		else {	// ���� �� ������ ã�����

		}
	}
	// curidx�� curidx+1�̶� ���ϸ� ��
	// ���� curidx�� 0�� ��� -> �״��
	// curidx�� N-1�� ��� -> �� �հŸ� ���� ��

	return;
}

// �� ����� ���� ���� �ɵ�
// �� ǰ.
// �׳�


/*
----------------------------
------
 ------
  ------
   ------
    ... �̷��� ���ؼ� �Ÿ� ã������ �Ǿ��� ������... curidx �������� 
*/