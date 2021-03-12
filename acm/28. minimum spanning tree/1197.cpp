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
// level[i] : i�� root�� subtree height
// parent[i] : i�� parent. == i�� root
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
	// edge[i][0] ~ edge[i][1]�� weight edge[i][2]�� �����
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