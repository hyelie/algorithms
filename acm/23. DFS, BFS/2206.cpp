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

	// �ȻѼ� ���� : 1, �Ѽ����� 0
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
			
			// dist�� 3���̶�, �Ѽ� ���¿� �Ѽ��� ���� ���� �� �ٸ� ������ ��.
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

state : �� �ѽ� ���� -> ���ѽ�
�� �Ȼѽ� ���� -> �ѽ� �� ����

���� ��ġ -> ���� ��ġ
0 0 -> state ����, �Ѿ
0 1 -> state --, �Ѿ

�ִܰŸ��̹Ƿ� DFS�� �̿�


*/