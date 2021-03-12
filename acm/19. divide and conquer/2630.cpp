#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int board[128][128];
int blue = 0, white = 0;
// 파랑이 1 하양이 0

void solve();
void DFS(int len, int x, int y) {
	if (len == 1) {
		if (board[x][y] == 0) white++;
		else blue++;
		return;
	}
	
	bool isFull = true;
	int start = board[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (board[i][j] != start) {
				isFull = false;
				break;
			}
		}
	}

	if (isFull) {
		if (start == 0) white++;
		else blue++;
	}
	else {
		DFS(len / 2, x, y);
		DFS(len / 2, x + len/2, y);
		DFS(len / 2, x, y +len/2);
		DFS(len / 2, x+len/2, y+len/2);
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
	cout << white << '\n' << blue;

	return;
}