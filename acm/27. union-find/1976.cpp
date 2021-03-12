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
int parent[201], level[201];
// level[i] : i가 root인 subtree height
// parent[i] : i의 parent. == i면 root

void solve();

void init(int maxn) {
	for (int i = 1; i <= maxn; i++) {
		parent[i] = i;
		level[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v])
		return v;

	parent[v] = find(parent[v]);
	return parent[v];
}

void merge(int u, int v) {
	int uroot = find(u), vroot = find(v);

	if (uroot == vroot) return;

	// u의 크기가 더 큼 -> v를 u에 넣음
	if (level[uroot] > level[vroot]) {
		parent[vroot] = uroot;
	}
	// v의 크기가 더 큼 -> u를 v에
	else if (level[uroot] < level[vroot]) {
		parent[uroot] = vroot;
	}
	// 같음 -> u를 v에 넣고 v depth ++
	else {
		parent[uroot] = vroot;
		level[vroot]++;
	}
}

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> M;

	init(N);

	int input;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			if (input == 1) {
				merge(i, j);
			}
		}
	}

	bool isConnect = true;
	int curParent;
	cin >> input;
	curParent = find(input);
	for (int i = 1; i < M; i++) {
		cin >> input;
		if (curParent != find(input)) {
			isConnect = false;
			break;
		}
	}

	if (isConnect) {
		cout << "YES\n";
	}
	else cout << "NO\n";

	return;
}