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
// level[i] : i�� root�� subtree height
// parent[i] : i�� parent. == i�� root

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

	// u�� ũ�Ⱑ �� ŭ -> v�� u�� ����
	if (level[uroot] > level[vroot]) {
		parent[vroot] = uroot;
	}
	// v�� ũ�Ⱑ �� ŭ -> u�� v��
	else if (level[uroot] < level[vroot]) {
		parent[uroot] = vroot;
	}
	// ���� -> u�� v�� �ְ� v depth ++
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

�ѹ� �˻���
��������� Ʈ�� ���̸�ŭ �˻� -> O(logn)
skewed tree �Ǹ� O(n)
�׷��� ��ξ��� �Ἥ O(logn)

*/