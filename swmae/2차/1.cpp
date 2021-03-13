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
// �Է� : �����
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
	// N�� ����, M�� ����.
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

		// 3���� 4�� 2�� ���� �� �꿩�߸� �Ѵ�. -> �Ÿ��� -1�� �ƴϾ�� ��
		if (dist[object_position.first][object_position.second] != -1 && dist[key_position.first][key_position.second] != -1) {
			cout << "1\n";
		}
		else cout << "0\n";

	}

	return;
}

// E -> K -> G
/*

E->K, K->G BFS �ϸ� ��. �Ÿ��� INF�� �Ұ���,
3 -> 4, 4 -> 2. 1�� ��, 0�� ��ĭ.

��ã�� ����.
BFS�� Ǯ����. |V| = 100�̰� |E| = 400�̹Ƿ� BFS�� ����� Ǯ��
�Ҹ� �������� key�� object�� �� �� reachable�ؾ߸� ���� ���ڸ� �� �� ����
�ϳ��� not reachable�̸� �Ұ���.

�Ҹ�ð� 30��

*/