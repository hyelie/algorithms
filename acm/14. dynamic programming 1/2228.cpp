#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
int recurse(int idx, int partnum, vector<vector<int>>& DP, vector<vector<bool>>& visited, vector<int>& arr, vector<int>& sum) {
	if (idx <= 0 || partnum < 0) return -200000000;
	if (visited[idx][partnum] == true) return DP[idx][partnum];

	// DP[i][j] : 총 j개 구간이 있다.
	// 1) 이 때 마지막 구간에 i가 포함된 경우 : j번째 구간에 arr[i]가 존재한다.
	//    j번째 구간이 시작하는 index가 k번째 수부터라고 하면, k-1번째 수는 포함되지 않는다
	//    DP[i][j] = DP[k-2][j-1] + sum(k, i)
	//		여기서 sum(k, i)는 index k부터 i까지 합이다.	-> 구간합 사용.
	//		이 때 k의 값은 찾아주어야 한다.

	// 2) 이 때 마지막 구간에 j가 포함되지 않은 경우 :
	//    DP[i][j] = DP[i-1][j]
	visited[idx][partnum] == true;
	DP[idx][partnum] = recurse(idx - 1, partnum, DP, visited, arr, sum);
	for (int i = idx; i >= 1; i--) {
		// 1) 이 때 마지막 구간에 i가 포함된 경우 : j번째 구간에 arr[i]가 존재한다.
		//    j번째 구간이 시작하는 index가 k번째 수부터라고 하면, k-1번째 수는 포함되지 않는다
		int last_part_sum = arr[idx] - arr[i-1];
		int i_to_idx_sum = recurse(idx - 2, partnum - 1, DP, visited, arr, sum) + last_part_sum;
		DP[idx][partnum] = max(DP[idx][partnum], i_to_idx_sum);

	}
	return DP[idx][partnum];
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> arr(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	vector<int> prefix_sum(N + 1);	// prefix_sum[a] - prefix_sum[b-1] : 구간 b~a까지 합.
	prefix_sum[0] = 0;
	prefix_sum[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}
	// DP[i][j] : 0번째 수부터 i번째 수까지 j개의 구간으로 나눌 때 최댓값.
	vector < vector<int>> DP(N+1, vector<int>(M+1, -199999999));
	// visited[i][j] : DP[i][j] 값을 계산했는지 여부.
	vector<vector<bool>> visited(N+1, vector<bool>(M + 1, false));
	// 0개 구간으로 나눈 건 전부 다 값이 0임. 이미 다 알고 있는 값들.
	for (int i = 0; i <= N; i++) {
		visited[i][0] = true;
		DP[i][0] = 0;
	}

	cout << recurse(N, M, DP, visited, arr, prefix_sum);


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
//    DP[i][j] = DP[k-2][j-1] + sum(k, i)
//		여기서 sum(k, i)는 index k부터 i까지 합이다.	-> 구간합 사용.
//		이 때 k의 값은 찾아주어야 한다.

// 2) 이 때 마지막 구간에 j가 포함되지 않은 경우 :
//    DP[i][j] = DP[i-1][j]

// 1), 2) 값 중 max값.

// https://stillchobo.tistory.com/107
