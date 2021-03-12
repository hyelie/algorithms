#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
vector<vector<int>> board(9, vector<int>(9));
vector<pii> blank;
int arr[10] = { 0, };

void solve();
// board의 row, col 자리에 num을 넣을 수 있는지. 가능하면 true, 아니면 false
// 가로열에서 2개 이상인게 있는지, 세로열에서 2개이상인게 있는지
// 3x3에서 2개이상인게 있는지.
bool insertable(int &num, int &row, int &col) {
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < 9; i++) {
		arr[board[i][col]]++;
	}
	for (int i = 1; i < 10; i++) {
		if (arr[i] >= 2) return false;
	}

	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < 9; i++) {
		arr[board[row][i]]++;
	}
	for (int i = 1; i < 10; i++) {
		if (arr[i] >= 2) return false;
	}

	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
	int blockrow = row / 3 * 3, blockcol = col / 3 * 3;
	for (int i = blockrow; i < blockrow + 3; i++) {
		for (int j = blockcol; j < blockcol + 3; j++) {
			arr[board[i][j]]++;
		}
	}
	for (int i = 1; i < 10; i++) {
		if (arr[i] >= 2) return false;
	}

	return true;
}

bool backtrack(int depth, int maxD) {
	if (depth == maxD) {
		return true;
	}
	pii tempblank = blank[depth];

	for (int i = 1; i < 10; i++) {
		// 구현 여기서 실수.
		board[tempblank.first][tempblank.second] = i;
		if (insertable(i, tempblank.first, tempblank.second)) {
			bool isOK = backtrack(depth + 1, maxD);
			if (isOK) {
				return true;
			}
		}
		board[tempblank.first][tempblank.second] = 0;
	}
	return false;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) blank.push_back({ i, j });
		}
	}

	backtrack(0, blank.size());

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}


	return;
}