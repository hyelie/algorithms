#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int n, m;
int parent[500001], level[500001];
// level[i] : i가 root인 subtree height
// parent[i] : i의 parent. == i면 root

void solve();

void init(int maxn) {
	for (int i = 0; i <= maxn; i++) {
		parent[i] = i;
		level[i] = 1;
	}
}

int find(int v) {
	if (parent[v] == v) return v;
	parent[v] = find(parent[v]);
	return parent[v];
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) {
		return false;
	}

	if (level[u] > level[v]) {
		parent[v] = u;
	}
	else if (level[u] < level[v]) {
		parent[u] = v;
	}
	else {
		parent[u] = v;
		level[v]++;
	}
	return true;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> n >> m;
	init(n);

	int firstcycle = 0;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		if (merge(x, y) == false) {
			firstcycle = i;
			break;
		}
	}

	cout << firstcycle;


	return;
}