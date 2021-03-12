#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N;
int board[26][26] = { 0, };
bool visited[26][26] = { false };
pii adjacent[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void solve();
int BFS(int x, int y) {
	queue<pii> q;
	int cnt = 1;
	pii temp, nxt;

	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			nxt.first = temp.first + adjacent[i].first;
			nxt.second = temp.second + adjacent[i].second;
			if (0 <= nxt.first && nxt.first < N && 0 <= nxt.first && nxt.first < N && !visited[nxt.first][nxt.second] && board[nxt.first][nxt.second]) {
				q.push(nxt);
				visited[nxt.first][nxt.second] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	vector<int> ans;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0 && !visited[i][j]) {
				ans.push_back(BFS(i, j));
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}


	return;
}