#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int white = 0, blue = 0;

// ÆÄ¶ûÀÌ 1
void DFS(int size, int row, int col, vector<vector<int>>& v) {
	if (size == 1) {
		if (v[row][col] == 1) blue++;
		else white++;
		return;
	}
	bool isSquare = true;
	int init = v[row][col];
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (init != v[i][j]) {
				isSquare = false;
				i = row + size;
				j = col + size;
				break;
			}
		}
	}

	if (isSquare) {
		init == 1 ? blue++ : white++;
	}
	else {
		DFS(size / 2, row, col, v);
		DFS(size / 2, row + size / 2, col, v);
		DFS(size / 2, row, col + size / 2, v);
		DFS(size / 2, row + size / 2, col + size / 2, v);
	}

	return;
}



int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	DFS(N, 0, 0, v);

	cout << white << " " << blue << endl;

	return;
}