#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
void solve_iter();

int main(void) {
	solve();
	return 0;
}

void solve() {
	vector<vector<int>> room(15, vector<int>(15));
	// room[i][j] : i�� jȣ
	for (int j = 1; j < 15; j++) {
		room[0][j] = j;
	}
	// ����Ʈ ���� ä��
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {

			if (j == 1) room[i][j] = room[i - 1][j];
			else room[i][j] = room[i - 1][j] + room[i][j - 1];
		}
	}

	int N;
	cin >> N;
	while (N--) {
		int k, n;
		cin >> k >> n;
		cout << room[k][n] << endl;
	}

	return;
}

// 0���� iȣ : i��(�ʱ�ȭ), 1ȣ���� ����

// 0��
// 1 2 3 4 5 ...
// 1��
// 1 3 6 10 15 ...
// 2��
// 1 4 10 20 35 ...

// room[i][j] = room[i - 1][j] + room[i][j - 1];
// i���� j-1ȣ : i-1���� j-1ȣ���� ��
// i���� jȣ : i-1���� jȣ���� �� = i���� j-1ȣ + i-1���� jȣ