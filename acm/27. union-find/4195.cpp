#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int n, m;
int parent[200001], level[200001], num_friend[200001];
// level[i] : i가 root인 subtree height
// parent[i] : i의 parent. == i면 root

void solve();

void init(int maxN) {
	for (int i = 1; i <= maxN; i++) {
		parent[i] = i;
		level[i] = 1;
		num_friend[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v]) return v;

	parent[v] = find(parent[v]);
	return parent[v];	
}

void merge(int u, int v) {
	int uroot = find(u), vroot = find(v);

	if (uroot == vroot) {
		cout << num_friend[vroot] << '\n';
		return;
	}

	if (level[uroot] > level[vroot]) {
		parent[vroot] = uroot;
		num_friend[uroot] += num_friend[vroot];
		cout << num_friend[uroot] << '\n';
	}
	else if (level[uroot] == level[vroot]) {
		parent[uroot] = vroot;
		num_friend[vroot] += num_friend[uroot];
		level[vroot]++;
		cout << num_friend[vroot] << '\n';
	}
	else {//level[uroot] < level[vroot]
		parent[uroot] = vroot;
		num_friend[vroot] += num_friend[uroot];
		cout << num_friend[vroot] << '\n';
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
	init(200000);
	map<string, int> m;
	int F; cin >> F;
	string a, b;
	int cnt = 1;
	for (int i = 0; i < F; i++) {
		cin >> a >> b;
		if (m.find(a) == m.end()) {
			m[a] = cnt;
			cnt++;
		}
		if (m.find(b) == m.end()) {
			m[b] = cnt;
			cnt++;
		}
		merge(m[a], m[b]);
	}

	return;
}