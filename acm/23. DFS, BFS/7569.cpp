#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int M, N, H;
// int board[N][M][H]
int board[101][101][101], dist[101][101][101];
vector<vector<int>> adjacent = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0} , {0, 0, 1} , {0, 0, -1} };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> M >> N>> H;

	queue<vector<int>>q;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j][k];
				dist[i][j][k] = -1;
				if (board[i][j][k] == 1) {
					q.push({ i, j, k });
					dist[i][j][k] = 0;
				}
			}
		}
	}

	vector<int> temp, nxt(3);
	int max_day = 0;
	while (!q.empty()) {
		temp = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			nxt[0] = temp[0] + adjacent[i][0];	// xÁÂÇ¥
			nxt[1] = temp[1] + adjacent[i][1];	// yÁÂÇ¥
			nxt[2] = temp[2] + adjacent[i][2];	// hÁÂÇ¥
			if (0 <= nxt[0] && nxt[0] < N && 0 <= nxt[1] && nxt[1] < M && 0 <= nxt[2] && nxt[2] < H && board[nxt[0]][nxt[1]][nxt[2]] == 0) {
				q.push(nxt);
				board[nxt[0]][nxt[1]][nxt[2]] = 1;
				dist[nxt[0]][nxt[1]][nxt[2]] = dist[temp[0]][temp[1]][temp[2]] + 1;
				max_day = max(max_day, dist[nxt[0]][nxt[1]][nxt[2]]);
			}
		}
	}

	bool allDone = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				if (board[i][j][k] == 0) {
					allDone = false;
				}
			}
			
		}
	}

	if (allDone) {
		cout << max_day;
	}
	else cout << "-1";

	return;
}