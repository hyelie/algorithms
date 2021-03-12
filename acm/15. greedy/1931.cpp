#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();
bool mycomp(const pii& a, const pii& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;
	vector<pii> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), mycomp);

	int start = v[0].first, end = v[0].second, cnt = 1;
	for (int i = 1; i < N; i++) {
		if (v[i].first < end) continue;
		start = v[i].first; end = v[i].second;
		cnt++;
	}
	cout << cnt;

	return;
}