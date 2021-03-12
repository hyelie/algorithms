#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dist[501][501];
int l;
pii cur, des;
pii adjacent[8] = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
	return 0;
}

void solve() {
	cin >> l >> cur.first >> cur.second >> des.first >> des.second;
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= l; j++) {
			dist[i][j] = -1;
		}
	}

	queue<pii> q;
	q.push(cur);
	dist[cur.first][cur.second] = 0;

	pii temp, nxt;
	while (!q.empty()) {
		temp = q.front(); q.pop();
		if (temp == des) break;
		for (int i = 0; i < 8; i++) {
			nxt.first = temp.first + adjacent[i].first;
			nxt.second = temp.second + adjacent[i].second;
			if (0 <= nxt.first && nxt.first < l && 0 <= nxt.second && nxt.second < l && dist[nxt.first][nxt.second] == -1) {
				q.push(nxt);
				dist[nxt.first][nxt.second] = dist[temp.first][temp.second] + 1;
			}
		}
	}

	cout << dist[des.first][des.second] << '\n';


	return;
}