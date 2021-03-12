#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int N;
int base[3001][3];
// base[i][0] : x, [1] : y, [2] : R
int parent[3001], level[3001];
// level[i] : i가 root인 subtree height
// parent[i] : i의 parent. == i면 root

void solve();

void init(int maxm) {
	for (int i = 0; i <= maxm; i++) {
		level[i] = 1;
		parent[i] = i;
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
	}
	else if (level[u] < level[v]) {
		parent[u] = v;
	}
	else {
		parent[u] = v;
		level[v]++;
	}
}
bool isReachable(int x1, int y1, int r1, int x2, int y2, int r2) {
	int dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	int rsub = (r1 + r2) * (r1 + r2);
	if (rsub >= dist) return true;
	else return false;
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
	init(3000);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> base[i][0] >> base[i][1] >> base[i][2];
		for (int j = 0; j < i; j++) {
			if (isReachable(base[i][0], base[i][1], base[i][2], base[j][0], base[j][1], base[j][2])) {
				merge(i, j);
			}
		}
	}

	set<int> s;
	for(int i = 0; i<N; i++){
		s.insert(find(i));
	}
	cout << s.size() << '\n';

	return;
}