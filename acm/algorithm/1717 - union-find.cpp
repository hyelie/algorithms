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
int parent[1000001], level[1000001];
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

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> n >> m;

	init(n);


	int op, x, y;




	for (int i = 0; i < m; i++) {
		cin >> op >> x >> y;
		if (op == 0) {
			merge(x, y);
		}
		else if (op == 1) {
			if (find(x) == find(y)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return;
}

/*

한번 검색에
평균적으로 트리 높이만큼 검색 -> O(logn)
skewed tree 되면 O(n)
그러나 경로압축 써서 O(logn)

*/