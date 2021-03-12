#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int n, m, t, s, g, h;
vector<pii> edge[2001];
// edge[i].first : i���� first�� ��. second : weight
int dist[2001];
int candidate[101];

struct mycomp {
	bool operator()(const pii& a, const pii& b) {
		return a.second > b.second;
	}
};

void solve();
void dijkstra(int start) {
	priority_queue<pii, vector<pii>, mycomp> pq;
	// pq.first : vertex num, pq.second : weight val
	for (int i = 1; i <= n; i++) {
		if (i == start) {
			dist[i] = 0;
		}
		else {
			dist[i] = 2000001;	// not visited
		}
		pq.push({ i, dist[i] });
	}

	// tempv : ���� �����ִ� vertex, tempw : ���������� tempv���� weight
	// nxtv : tempv ���� vertex num, nxtw : temp���� nxtv���� weight
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
}

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
	cin >> n >> m >> t >> s >> g >> h;

	for (int i = 0; i <= n; i++) {
		edge[i] = {};
	}

	int a, b, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		edge[a].push_back({ b, d });
		edge[b].push_back({ a, d });
	}

	for (int i = 0; i < t; i++) {
		cin >> candidate[i];
	}

	// s����(s->g, s->h)
	dijkstra(s);
	int s_to_g = dist[g] == 2000001 ? -1 : dist[g];
	int s_to_h = dist[h] == 2000001 ? -1 : dist[h];

	// g����(g<->h, g->V)
	dijkstra(g);
	int g_to_h = dist[h] == 2000001 ? -1 : dist[h];
	vector<int> fromG_candidates_dist(t);
	for (int i = 0; i < t; i++) {
		fromG_candidates_dist[i] = dist[candidate[i]] == 2000001 ? -1 : dist[candidate[i]];
	}
	
	// h����(h->V)
	dijkstra(h);
	vector<int> fromH_candidates_dist(t);
	for (int i = 0; i < t; i++) {
		fromH_candidates_dist[i] = dist[candidate[i]] == 2000001 ? -1 : dist[candidate[i]];
	}




	return;
}

/*

s->g->h->V
s->h->g->V

*/