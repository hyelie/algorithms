#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[101][101], prefix_sum[101], arr[101];
// DP[i][j] : 0번째 수부터 i번째 수까지 j개의 구간으로 나눌 때 합의 최대값
bool visited[101][101] = { false, };
// visited[i][j] : dp[i][j]값을 계산했는지 여부.

void solve();

// dp[i][j]를 알아내는 함수
int recurse(int i, int j) {
	// 구간이 0개 -> 합은 무조건 0
	if (j == 0) return 0;
	// 만약 i<0 -> 무조건 negative
	if (i < 0)return -32767000;
	// 방문했다면 그 값 줌
	if (visited[i][j]) {
		return dp[i][j];
	}
	dp[i][j] = -32767000;
	visited[i][j] = true;
	// 1) 부분. 총 j개 구간에서, 마지막 구간에 i가 있는 경우 : j번째 구간에 arr[i]가 존재.
	// j번째 구간이 언제 시작하는지를 찾아야 함. 아래는 그 식.
	for (int k = 1; k <= i; k++) {
		dp[i][j] = max(dp[i][j], recurse(k - 2, j - 1) + prefix_sum[i] - prefix_sum[k - 1]);
	}
	// 2) 부분.
	dp[i][j] = max(recurse(i - 1, j), dp[i][j]);
	return dp[i][j];
}
// DP[i][j] : 총 j개 구간이 있다.
// 1) 이 때 마지막 구간에 i가 포함된 경우 : j번째 구간에 arr[i]가 존재한다.
//    j번째 구간이 시작하는 index가 k번째 수부터라고 하면, k-1번째 수는 포함되지 않는다
//    DP[i][j] = DP[k-2][j-1] + sum(k, i) (= psum(i) - psum(k-1)
//		여기서 sum(k, i)는 index k부터 i까지 합이다.	-> 구간합 사용.
//		이 때 k의 값은 찾아주어야 한다.

// 2) 이 때 마지막 구간에 j가 포함되지 않은 경우 :
//    DP[i][j] = DP[i-1][j]

// 1), 2) 값 중 max값.

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// prefix_sum[a] - prefix_sum[b-1] : 구간 b~a까지 합.
	prefix_sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}

	// 0개 구간으로 나눈 건 전부 다 값이 0임. 이미 다 알고 있는 값들.
	for (int i = 0; i <= N; i++) {
		visited[i][0] = true;
		dp[i][0] = 0;
	}

	cout<<recurse(N, M);

	return;
}

// 1 <= M <= N/2
// 각 구간은 1개이상의 연속된 수
// 서로 다른 두 구간이 인접/겹치면 X
// 정확히 M개의 구간
// DP[i][j] : 0번째 수부터 i번째 수까지 j개의 구간으로 나눌 때 최댓값.

// DP[i][j] : 총 j개 구간이 있다.
// 1) 이 때 마지막 구간에 i가 포함된 경우 : j번째 구간에 arr[i]가 존재한다.
//    j번째 구간이 시작하는 index가 k번째 수부터라고 하면, k-1번째 수는 포함되지 않는다
//    DP[i][j] = DP[k-2][j-1] + sum(k, i) (= psum(i) - psum(k-1)
//		여기서 sum(k, i)는 index k부터 i까지 합이다.	-> 구간합 사용.
//		이 때 k의 값은 찾아주어야 한다.

// 2) 이 때 마지막 구간에 j가 포함되지 않은 경우 :
//    DP[i][j] = DP[i-1][j]

// 1), 2) 값 중 max값.

// https://stillchobo.tistory.com/107

