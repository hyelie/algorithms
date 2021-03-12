#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int n;
pair<float, float> star[101];
int parent[1001], level[1001];
float answer = 0;

void solve();

bool mycomp(const pair<pii, float>& a, const pair<pii, float>& b) {
	return a.second < b.second;
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

void merge(int u, int v, float weight) {
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

float dist(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> star[i].first >> star[i].second;
	}

	cout << fixed;
	cout.precision(4);

	vector<pair<pii, float>> edge;
	// edge[i].first.first : ������ǥ
	// edge[i].first.second : ������ǥ
	// edge[i].second : �Ÿ�

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edge.push_back({ {i, j}, dist(star[i].first, star[i].second, star[j].first, star[j].second) });
		}
	}

	init(n);

	sort(edge.begin(), edge.end(), mycomp);

	int edgesize = edge.size();
	for (int i = 0; i < edgesize; i++) {
		merge(edge[i].first.first, edge[i].first.second, edge[i].second);
	}

	cout << answer;

	return;
}