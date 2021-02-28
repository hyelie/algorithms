#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
int recurse(int idx, int partnum, vector<vector<int>>& DP, vector<vector<bool>>& visited, vector<int>& arr, vector<int>& sum) {
	if (idx <= 0 || partnum < 0) return -200000000;
	if (visited[idx][partnum] == true) return DP[idx][partnum];

	// DP[i][j] : �� j�� ������ �ִ�.
	// 1) �� �� ������ ������ i�� ���Ե� ��� : j��° ������ arr[i]�� �����Ѵ�.
	//    j��° ������ �����ϴ� index�� k��° �����Ͷ�� �ϸ�, k-1��° ���� ���Ե��� �ʴ´�
	//    DP[i][j] = DP[k-2][j-1] + sum(k, i)
	//		���⼭ sum(k, i)�� index k���� i���� ���̴�.	-> ������ ���.
	//		�� �� k�� ���� ã���־�� �Ѵ�.

	// 2) �� �� ������ ������ j�� ���Ե��� ���� ��� :
	//    DP[i][j] = DP[i-1][j]
	visited[idx][partnum] == true;
	DP[idx][partnum] = recurse(idx - 1, partnum, DP, visited, arr, sum);
	for (int i = idx; i >= 1; i--) {
		// 1) �� �� ������ ������ i�� ���Ե� ��� : j��° ������ arr[i]�� �����Ѵ�.
		//    j��° ������ �����ϴ� index�� k��° �����Ͷ�� �ϸ�, k-1��° ���� ���Ե��� �ʴ´�
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
	vector<int> prefix_sum(N + 1);	// prefix_sum[a] - prefix_sum[b-1] : ���� b~a���� ��.
	prefix_sum[0] = 0;
	prefix_sum[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
	}
	// DP[i][j] : 0��° ������ i��° ������ j���� �������� ���� �� �ִ�.
	vector < vector<int>> DP(N+1, vector<int>(M+1, -199999999));
	// visited[i][j] : DP[i][j] ���� ����ߴ��� ����.
	vector<vector<bool>> visited(N+1, vector<bool>(M + 1, false));
	// 0�� �������� ���� �� ���� �� ���� 0��. �̹� �� �˰� �ִ� ����.
	for (int i = 0; i <= N; i++) {
		visited[i][0] = true;
		DP[i][0] = 0;
	}

	cout << recurse(N, M, DP, visited, arr, prefix_sum);


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
//    DP[i][j] = DP[k-2][j-1] + sum(k, i)
//		���⼭ sum(k, i)�� index k���� i���� ���̴�.	-> ������ ���.
//		�� �� k�� ���� ã���־�� �Ѵ�.

// 2) �� �� ������ ������ j�� ���Ե��� ���� ��� :
//    DP[i][j] = DP[i-1][j]

// 1), 2) �� �� max��.

// https://stillchobo.tistory.com/107
