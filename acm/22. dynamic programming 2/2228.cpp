#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[101][101], prefix_sum[101], arr[101];
// DP[i][j] : 0��° ������ i��° ������ j���� �������� ���� �� ���� �ִ밪
bool visited[101][101] = { false, };
// visited[i][j] : dp[i][j]���� ����ߴ��� ����.

void solve();

// dp[i][j]�� �˾Ƴ��� �Լ�
int recurse(int i, int j) {
	// ������ 0�� -> ���� ������ 0
	if (j == 0) return 0;
	// ���� i<0 -> ������ negative
	if (i < 0)return -32767000;
	// �湮�ߴٸ� �� �� ��
	if (visited[i][j]) {
		return dp[i][j];
	}
	dp[i][j] = -32767000;
	visited[i][j] = true;
	// 1) �κ�. �� j�� ��������, ������ ������ i�� �ִ� ��� : j��° ������ arr[i]�� ����.
	// j��° ������ ���� �����ϴ����� ã�ƾ� ��. �Ʒ��� �� ��.
	for (int k = 1; k <= i; k++) {
		dp[i][j] = max(dp[i][j], recurse(k - 2, j - 1) + prefix_sum[i] - prefix_sum[k - 1]);
	}
	// 2) �κ�.
	dp[i][j] = max(recurse(i - 1, j), dp[i][j]);
	return dp[i][j];
}
// DP[i][j] : �� j�� ������ �ִ�.
// 1) �� �� ������ ������ i�� ���Ե� ��� : j��° ������ arr[i]�� �����Ѵ�.
//    j��° ������ �����ϴ� index�� k��° �����Ͷ�� �ϸ�, k-1��° ���� ���Ե��� �ʴ´�
//    DP[i][j] = DP[k-2][j-1] + sum(k, i) (= psum(i) - psum(k-1)
//		���⼭ sum(k, i)�� index k���� i���� ���̴�.	-> ������ ���.
//		�� �� k�� ���� ã���־�� �Ѵ�.

// 2) �� �� ������ ������ j�� ���Ե��� ���� ��� :
//    DP[i][j] = DP[i-1][j]

// 1), 2) �� �� max��.

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

	// prefix_sum[a] - prefix_sum[b-1] : ���� b~a���� ��.
	prefix_sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}

	// 0�� �������� ���� �� ���� �� ���� 0��. �̹� �� �˰� �ִ� ����.
	for (int i = 0; i <= N; i++) {
		visited[i][0] = true;
		dp[i][0] = 0;
	}

	cout<<recurse(N, M);

	return;
}

// 1 <= M <= N/2
// �� ������ 1���̻��� ���ӵ� ��
// ���� �ٸ� �� ������ ����/��ġ�� X
// ��Ȯ�� M���� ����
// DP[i][j] : 0��° ������ i��° ������ j���� �������� ���� �� �ִ�.

// DP[i][j] : �� j�� ������ �ִ�.
// 1) �� �� ������ ������ i�� ���Ե� ��� : j��° ������ arr[i]�� �����Ѵ�.
//    j��° ������ �����ϴ� index�� k��° �����Ͷ�� �ϸ�, k-1��° ���� ���Ե��� �ʴ´�
//    DP[i][j] = DP[k-2][j-1] + sum(k, i) (= psum(i) - psum(k-1)
//		���⼭ sum(k, i)�� index k���� i���� ���̴�.	-> ������ ���.
//		�� �� k�� ���� ã���־�� �Ѵ�.

// 2) �� �� ������ ������ j�� ���Ե��� ���� ��� :
//    DP[i][j] = DP[i-1][j]

// 1), 2) �� �� max��.

// https://stillchobo.tistory.com/107

