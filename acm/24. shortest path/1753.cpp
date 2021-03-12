#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int V, E, S;
vector<pii> edge[20001];
// edge[i].first : i에서 first로 감. second : weight
int dist[20001];

void solve();
struct mycomp {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> V >> E >> S;
	int from, to, weight;
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> weight;
		edge[from].push_back({ to, weight });
	}

	priority_queue<pii, vector<pii>, mycomp> pq;
	// pq.first : vertex num, pq.second : weight val
	for (int i = 1; i <= V; i++) {
		if (i == S) {
			dist[i] = 0;
		}
		else {
			dist[i] = 2000001;	// not visited
		}
		pq.push({ i, dist[i] });
	}

	// tempv : 지금 보고있는 vertex, tempw : 시작점부터 tempv까지 weight
	// nxtv : tempv 다음 vertex num, nxtw : temp부터 nxtv까지 weight
	int tempv, tempw, nxtv, nxtw;
	while (!pq.empty()) {
		tempv = pq.top().first;
		tempw = pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[tempv].size(); i++) {
			nxtv = edge[tempv][i].first;
			nxtw = edge[tempv][i].second;
			if (dist[nxtv] > dist[tempv] + nxtw) {
				dist[nxtv] = dist[tempv] + nxtw;
				pq.push({ nxtv, dist[nxtv] });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 2000001) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}



	return;
}