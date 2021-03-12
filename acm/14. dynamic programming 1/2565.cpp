#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int dp[101];

bool mycomp(const pii& a, const pii& b) {
	return a.first < b.first;
}

void solve();

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
	sort(v.begin(), v.end(), mycomp);

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxval = *max_element(dp, dp+N);
	cout << N - maxval;
	

	return;
}

/*

LIS.
8 2 9 1 4 6 7 10
first 기준 정렬하고 second에서 LIS 길이 찾으면 됨

*/