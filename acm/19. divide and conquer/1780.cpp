#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int neg = 0, zero = 0, pos = 0;
int board[2187][2187];

void solve();
void DFS(int len, int x, int y) {
	if (len == 1) {
		switch (board[x][y]) {
		case 1:
			pos++;
			break;
		case 0:
			zero++;
			break;
		case -1:
			neg++;
			break;
		}
		return;
	}
	int isFull = true;
	int start = board[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (start != board[i][j]) {
				isFull = false;
				break;
			}
		}
	}

	if (isFull) {
		switch (start) {
		case 1:
			pos++;
			break;
		case 0:
			zero++;
			break;
		case -1:
			neg++;
			break;
		}
	}
	else {
		DFS(len / 3, x, y);
		DFS(len / 3, x, y + len / 3);
		DFS(len / 3, x, y + 2 * len / 3);
		DFS(len / 3, x + len / 3, y);
		DFS(len / 3, x + len / 3, y + len / 3);
		DFS(len / 3, x + len / 3, y + 2 * len / 3);
		DFS(len / 3, x + 2 * len / 3, y);
		DFS(len / 3, x + 2 * len / 3, y + len / 3);
		DFS(len / 3, x + 2 * len / 3, y + 2 * len / 3);
	}
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	DFS(N, 0, 0);
	cout << neg << '\n' << zero << '\n' << pos;

	return;
}