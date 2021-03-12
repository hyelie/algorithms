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
vector<pii> edge[10001];
//edge[i].first : i to first, second : i to first weight
long long dist[501];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> M;
	int A, B, C;
	while (M--) {
		cin >> A >> B >> C;
		edge[A].push_back({ B, C });
	}

	dist[1] = 0;
	for (int i = 2; i <= N; i++) {
		dist[i] = 1000000001;
	}

	int src, dest, weight;
	// N-1번 순회
	for (int i = 0; i < N - 1; i++) {
		// graph 모든 vertex 대해
		for (int v = 1; v <= N; v++) {
			// 각 vertex의 모든 edge 대해
			for (int e = 0; e < edge[v].size(); e++) {
				src = v;
				dest = edge[v][e].first;
				weight = edge[v][e].second;

				if (dist[src] != 1000000001 && dist[dest] > dist[src] + weight) {
					dist[dest] = dist[src] + weight;
				}
			}
		}
	}

	bool isNegCycle = false;
	// negative cycle 검사
	// graph 모든 vertex 대해
	for (int v = 1; v <= N; v++) {
		// 각 vertex의 모든 edge 대해
		for (int e = 0; e < edge[v].size(); e++) {
			src = v;
			dest = edge[v][e].first;
			weight = edge[v][e].second;

			if (dist[v] != 1000000001 && dist[dest] > dist[src] + weight) {
				isNegCycle = true;
			}
		}
	}

	if (isNegCycle) {
		cout << "-1";
	}
	else {
		for (int v = 2; v <= N; v++) {
			if (dist[v] == 1000000001) dist[v] = -1;
			cout << dist[v] << '\n';
		}
	}


	return;
}


// 벨만포드 O(|V|^3), 공간복잡도 O(|V|)
// 음수 사용.