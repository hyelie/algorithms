#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N, num_edge;
bool adjacent[101][101] = { false, };
bool visited[101] = { false, };
int cnt = 0;

void solve();
void DFS(int cur) {
	visited[cur] = true;
	for (int i = 1; i <= 100; i++) {
		if (!visited[i] && adjacent[cur][i]) {
			cnt++;
			DFS(i);
		}
	}
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N>>num_edge;
	int s, e;
	for (int i = 0; i < num_edge; i++) {
		cin >> s >> e;
		adjacent[s][e] = adjacent[e][s] = true;
	}

	DFS(1);
	
	cout << cnt;

	return;
}