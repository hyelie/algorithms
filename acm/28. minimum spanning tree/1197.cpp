#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

int parent[1000001], level[1000001];
// level[i] : i가 root인 subtree height
// parent[i] : i의 parent. == i면 root
int V, E, answer = 0;
void solve();

bool mycomp(const vector<int> &a, const vector<int>&b) {
	return a[2] < b[2];
}

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

void merge(int u, int v, int weight) {
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
	answer += weight;
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> V >> E;
	vector<vector<int>> edge(E, vector<int>(3));
	init(V);
	// edge[i][0] ~ edge[i][1]이 weight edge[i][2]로 연결됨
	for (int i = 0; i < E; i++) {
		cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
	}
	sort(edge.begin(), edge.end(), mycomp);

	for (int i = 0; i < E; i++) {
		merge(edge[i][0], edge[i][1], edge[i][2]);
	}

	cout << answer;

	return;
}