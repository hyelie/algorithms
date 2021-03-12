#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N, M, a, b;
int level[1001], parent[1001], flight[1001];

void solve();
void init(int maxn) {
	for (int i = 0; i <= maxn; i++) {
		level[i] = 1;
		parent[i] = i;
		flight[i] = 1;
	}
}
int find(int v) {
	if (v == parent[v]) return v;
	parent[v] = find(parent[v]);
	return parent[v];
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (level[u] > level[v]) {
		parent[v] = u;
		flight[u] += flight[v];
	}
	else if (level[u] < level[v]) {
		parent[u] = v;
		flight[v] += flight[u];
	}
	else {
		parent[u] = v;
		level[v]++;
		flight[v] += flight[u];
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
	cin >> N >> M;
	init(N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		merge(a, b);
	}

	set<int> s;
	for (int i = 1; i <= N; i++) {
		s.insert(find(i));
	}
	int sum = 0;
	for (auto iter : s) {
		sum += flight[find(iter)];
	}
	cout << sum-s.size() << '\n';

	return;
}

/*

kruskal - union-find
O(|E|log|E|)

prim
O(|V|^2

sparse graph(edge 수 적음) -> prim
dense graph(edge 수 많음) -> kruskal
*/