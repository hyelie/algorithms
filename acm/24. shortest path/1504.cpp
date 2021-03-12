#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N, E;
vector<pii> edge[801];
// edge[i].first : i에서 first로 감. second : weight

struct mycomp {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};

void solve();
// start부터 end까지 SP 값 리턴
int dijkstra(int start, int end) {
	vector<int> dist(N + 1, 800001);
	// dist[i] : 1번부터 i번까지 min weight

	dist[start] = 0;
	priority_queue<pii, vector<pii>, mycomp> pq;
	// pq.first : vertex num, pq.second : vertex num까지 weight
	for (int i = 1; i <= N; i++) {
		pq.push({ i, dist[i] });
	}

	int curv, curw, nxtv, nxtw;
	// tempv : 지금 보고있는 vertex, tempw : 시작점부터 tempv까지 weight
	// nxtv : tempv 다음 vertex num, nxtw : temp부터 nxtv까지 weight
	while (!pq.empty()) {
		curv = pq.top().first;
		curw = pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[curv].size(); i++) {
			nxtv = edge[curv][i].first;
			nxtw = edge[curv][i].second;
			if (dist[nxtv] > dist[curv] + nxtw) {
				dist[nxtv] = dist[curv] + nxtw;
				pq.push({ nxtv, dist[nxtv] });
			}
		}
	}



	return dist[end];

}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	int v1, v2;
	cin >> v1 >>v2;

	a = dijkstra(v1, v2);
	bool v1v2possible = true, v2v1possible = true;
	int one_v1, v2_N, one_v2, v1_N;
	one_v1 = dijkstra(1, v1);
	v2_N = dijkstra(v2, N);
	one_v2 = dijkstra(1, v2);
	v1_N = dijkstra(v1, N);

	if (a == 800001) {
		cout << "-1";
		return;
	}
	else {
		if (one_v1 == 800001 || v2_N == 800001) v1v2possible = false;
		if (one_v2 == 800001 || v1_N == 800001) v2v1possible = false;
	}

	if (!v1v2possible && !v2v1possible) {
		cout << "-1";
	}
	else if (v1v2possible && !v2v1possible) {
		cout << a + one_v1 + v2_N;
	}
	else if (!v1v2possible && v2v1possible) {
		cout << a + one_v2 + v1_N;
	}
	else {
		cout << a + min(one_v1 + v2_N, one_v2 + v1_N);
	}

	// 2가지. 1->v1->v2->N, 1->v2->v1->N

	//800001

	


	return;
}


/*

두 vertex를 거침 : 이를 v1, v2라 하면
시작점 ~ v1, v1 ~ v2, v2 ~ N으로 dijkstra 하면 됨

*/