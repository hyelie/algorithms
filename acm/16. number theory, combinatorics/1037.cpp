#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[51];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dp[i];
	}
	sort(dp, dp + N);
	if (N == 1) cout << dp[0] * dp[0];
	else cout << dp[0] * dp[N - 1];


	return;
}
/*
70
2 7 10 35
*/