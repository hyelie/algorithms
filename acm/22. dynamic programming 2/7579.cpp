#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int memory[101], cost[101];
//pii app[101];
// app.first : memory, app.second : cost;
int dp[101][10001];

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> memory[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}

	int min_val = 2100000000;

	for (int j = 0; j < 10001; j++) {
		dp[0][j] = 0;
	}

	// app[i].first�� M �̻��� �Ǿ�� �ϰ�
	// �� app[i].second���� ���� �ּҰ� �Ǿ�� ��
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10001; j++) {
			if (j >= cost[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
			else dp[i][j] = dp[i - 1][j];

			if (dp[i][j] >= M) {
				min_val = min(min_val, j);
			}
		}
	}

	cout << min_val;

	return;
}

/*

�� A_i : m_i��ŭ ���, ���Ŀ� ���� ��� c_i
�� �� �� �� B ���� �� M����Ʈ �޸� �ʿ� -> ���� Ȱ��ȭ�Ȱ� �� � ��Ȱ��ȭ
�� �� c_i�� �� �ּ�ȭ

-> �Ųٷ� �����ϸ� ��.

dp[i][j] = app i����, cost�� j�� �� memory�� �ִ밪.


for(int i = 0; i<N; i++){
	for(int j = 0; j<N; j++){
		if(j >= cost[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i])
		else dp[i][j] = dp[i-1][j]
	}
}
j > cost[i]
dp[i][j]


*/