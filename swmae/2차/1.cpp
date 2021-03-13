#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define MYMAX -1

using namespace std;
typedef pair<int, int> pii;
pii adjacent[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int t, M, N, board[11][11], dist[11][11];
pii soma_position, key_position, object_position;


void solve();
// 입력 : 출발점
void BFS(int x, int y) {
	queue<pii> q;
	q.push({ x, y });
	dist[x][y] = 0;
	pii temp, nxt;
	while (!q.empty()) {
		temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			nxt.first = temp.first + adjacent[i].first;
			nxt.second = temp.second + adjacent[i].second;
			if (0 <= nxt.first && nxt.first < N && 0 <= nxt.second && nxt.second < M && board[nxt.first][nxt.second] != 1 && dist[nxt.first][nxt.second] == -1) {
				q.push(nxt);
				dist[nxt.first][nxt.second] = dist[temp.first][temp.second] + 1;
			}
		}
	}
}


int main(void) {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void solve() {
	cin >> t;
	// N이 세로, M이 가로.
	while(t--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];

				if (board[i][j] == 3)
					soma_position = { i, j };
				else if (board[i][j] == 2)
					object_position = { i, j };
				else if (board[i][j] == 4)
					key_position = { i, j };

				dist[i][j] = MYMAX;
			}
		}
		BFS(soma_position.first, soma_position.second);

		// 3에서 4와 2가 전부 다 닿여야만 한다. -> 거리가 -1이 아니어야 함
		if (dist[object_position.first][object_position.second] != -1 && dist[key_position.first][key_position.second] != -1) {
			cout << "1\n";
		}
		else cout << "0\n";

	}

	return;
}

// E -> K -> G
/*

E->K, K->G BFS 하면 됨. 거리가 INF면 불가능,
3 -> 4, 4 -> 2. 1은 벽, 0은 빈칸.

길찾기 문제.
BFS로 풀었음. |V| = 100이고 |E| = 400이므로 BFS로 충분히 풀림
소마 기준으로 key와 object가 둘 다 reachable해야만 보물 상자를 열 수 있음
하나라도 not reachable이면 불가능.

소모시간 30분

*/