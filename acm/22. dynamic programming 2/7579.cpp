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

	// app[i].first가 M 이상이 되어야 하고
	// 이 app[i].second들의 합이 최소가 되어야 함
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

앱 A_i : m_i만큼 사용, 추후에 들어가는 비용 c_i
이 때 새 앱 B 실행 시 M바이트 메모리 필요 -> 현재 활성화된것 중 몇개 비활성화
이 때 c_i의 합 최소화

-> 거꾸로 생각하면 됨.

dp[i][j] = app i까지, cost가 j일 때 memory의 최대값.


for(int i = 0; i<N; i++){
	for(int j = 0; j<N; j++){
		if(j >= cost[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i])
		else dp[i][j] = dp[i-1][j]
	}
}
j > cost[i]
dp[i][j]


*/