#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();
bool mycomp(const pis& a, const pis& b) {
	return a.first < b.first;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N;
	cin >> N;
	vector<pis> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), mycomp);
	for (int i = 0; i < N; i++) {
		cout << v[i].first <<" "<< v[i].second<<'\n';
	}

	return;
}