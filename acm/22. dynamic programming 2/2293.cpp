#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int value[101];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	sort(value, value + n);

	vector<int> dp(k + 1, 0);
	dp[0] = 1;


	// dp[i] : i�� ����� ���.
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			//dp[i][j] = dp[i - 1][j];
			if (value[i] <= j) dp[j] += dp[j - value[i]];
		}
	}

	cout << dp[k];


	return;
}

/*

dp[i][k] : i��° coin���� ����ؼ� k�� ����� ����� ��
	value[i] > k : dp[i-1][k]
	value[i] <= k : dp[i-1][k] + dp[i][k-value[i]]


1 2 5������ 10�� ����� ġ��
  1 2 3 4 5 6 7 8 9 10
1 1 1 1 1 1 1 1 1 1 1 
2 1 2 2 3 3 4 4 5 5 6
5 1 2 2 3 4 5 6 7 8 10

�׷��� dp[i][j] ��� dp[i]�� ��. dp[i] : i���� ����� ����� ��
���� dp[i][k]�� ���� �̴޼� �� dp[i-1][k]�Ƿ� �������(���� �����)


*/