#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

// n : size.
void recurse(int n, int row, int col, vector<vector<bool>>& v) {
	if (n == 3) {
		for (int i = row; i < row + 3; i++) {
			for (int j = col; j < col + 3; j++) {
				v[i][j] = true;
			}
		}
		v[row + 1][col + 1] = false;
		return;
	}

	int len = n / 3;
	recurse(len, row, col, v);
	recurse(len, row + len, col, v);
	recurse(len, row + 2 * len, col, v);
	recurse(len, row, col + len, v);
	recurse(len, row + 2 * len, col + len, v);
	recurse(len, row, col + 2 * len, v);
	recurse(len, row + len, col + 2 * len, v);
	recurse(len, row + 2 * len, col + 2 * len, v);
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n;
	cin >> n;
	int tempn = n, k = 0;
	while (tempn != 1) {
		tempn /= 3;
		k++;
	}// k : 지수.

	vector<vector<bool>> v(n, vector<bool>(n, false));
	// v[i][j]가 false면 i, j는 빈 공간.
	recurse(n, 0, 0, v);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j]) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}

	return;
}