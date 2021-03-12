#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[1000001];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] % 15746 + dp[i - 2] % 15746) % 15746;
	}

	cout << dp[N];

	return;
}
/*
N = 1
1

N = 2
00, 11

N = 3
001, 100, 111

N = 4
0011, 0000, 1001, 1100, 1111

N = 5
11111
11100, 11001, 10011, 00111
10000, 00100, 00001

i-2번째에서 00을 붙이는 경우
i-1번째에서 1을 붙이는 경우


*/