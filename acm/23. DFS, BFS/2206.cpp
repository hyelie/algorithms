#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;


int N, M;
int board[1001][1001] = { 0 }, dist[1001][1001][2];
pii adjacent[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			board[i][j] = s[j] - '0';
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
		}
	}

	// 안뿌순 상태 : 1, 뿌순상태 0
	queue<pair<pii, int>> q;
	q.push({ { 0, 0 }, 1});
	dist[0][0][0] = dist[0][0][1] = 1;
	pii temp, nxt;
	int state;
	while (!q.empty()) {
		temp = q.front().first; state = q.front().second;

		if (temp.first == N - 1 && temp.second == M - 1) break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nxt.first = temp.first + adjacent[i].first;
			nxt.second = temp.second + adjacent[i].second;
			
			// dist가 3중이라서, 뿌순 상태와 뿌수지 않은 상태 둘 다를 관리해 줌.
			if (0 <= nxt.first && nxt.first < N && 0 <= nxt.second && nxt.second < M && board[nxt.first][nxt.second] == 0 && dist[nxt.first][nxt.second][state] == -1) {
				q.push({ nxt, state });
				dist[nxt.first][nxt.second][state] = dist[temp.first][temp.second][state] + 1;
			}
			if (0 <= nxt.first && nxt.first < N && 0 <= nxt.second && nxt.second < M && board[nxt.first][nxt.second] == 1 && state == 1) {
				q.push({ nxt, 0 });
				dist[nxt.first][nxt.second][0] = dist[temp.first][temp.second][1] + 1;
			}
		}
	}

	cout << max(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);



	return;
}

/*

state : 벽 뿌신 상태 -> 못뿌심
벽 안뿌신 상태 -> 뿌실 수 있음

현재 위치 -> 다음 위치
0 0 -> state 유지, 넘어감
0 1 -> state --, 넘어감

최단거리이므로 DFS를 이용


*/