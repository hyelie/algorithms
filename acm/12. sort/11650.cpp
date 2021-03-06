#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

void solve();
bool mycomp(const pii& a, const pii& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else return a.first < b.first;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	vector<pii> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].first <<" "<< v[i].second<<'\n';
	}

	return;
}