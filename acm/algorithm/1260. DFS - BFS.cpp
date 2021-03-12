#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int N, M, V;
int adjacent[1001][1001] = { 0, };
bool Dvisited[1001] = { false };
bool Bvisited[1001] = { false };

void solve();
// cur : 현재 방문한 node idx
void DFS(int cur) {
	cout << cur << ' ';
	Dvisited[cur] = true;
	for (int i = 1; i <= 1000; i++) {
		if (adjacent[cur][i] && !Dvisited[i]) {
			DFS(i);
		}
	}
}
void BFS(int cur) {
	queue<int> q;
	q.push(cur);
	Bvisited[cur] = true;

	while (!q.empty()) {
		cur = q.front(); q.pop();
		cout << cur << " ";
		for (int i = 1; i <= 1000; i++) {
			if (adjacent[cur][i] && !Bvisited[i]) {
				q.push(i);
				Bvisited[i] = true;
			}
		}
	}
	cout << '\n';
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> M >> V;
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		adjacent[s][e] = adjacent[e][s] = 1;
	}

	DFS(V);
	cout << '\n';
	BFS(V);

	return;
}

/*

O(|E| + |V|)

*/