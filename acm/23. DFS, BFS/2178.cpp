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
int board[101][101] = { 0 }, dist[101][101];
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
			dist[i][j] = -1;
		}
	}

	queue<pii> q;
	q.push({ 0, 0 });
	dist[0][0] = 1;
	pii temp, nxt;
	while (!q.empty()) {
		temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			nxt.first = temp.first + adjacent[i].first;
			nxt.second = temp.second + adjacent[i].second;
			if (0 <= nxt.first && nxt.first < N && 0 <= nxt.second && nxt.second < M && board[nxt.first][nxt.second] && dist[nxt.first][nxt.second] == -1) {
				q.push(nxt);
				dist[nxt.first][nxt.second] = dist[temp.first][temp.second] + 1;
			}
		}
	}

	cout << dist[N - 1][M - 1];



	return;
}