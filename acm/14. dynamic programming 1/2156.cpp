#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[10001];
int drink[10001];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> drink[i];
	}
	// dp[i] : i번째 포도주를 마셨을때 최대로 마신 양.
	dp[0] = 0;
	dp[1] = drink[1];
	dp[2] = dp[1] + drink[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 2] + drink[i], dp[i - 3] + drink[i - 1] + drink[i]), dp[i-1]);
	}
	
	cout << *max_element(dp, dp + n + 1);

	// i-2번째 마시고 i번째 마시는 경우
	// i-1번째 마시고 i번째 마시는 경우

	// i-3번째 마시고 i-2번째 마시고 i번째 마시는 경우
	// i-3번째 마시고 i-1번째 마시고 i번재 마시는 경우

	return;
}


/*





*/