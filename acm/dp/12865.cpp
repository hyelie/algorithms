#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve();

int main(void) {
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> v(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	// first�� ����, second�� ��ġ

	vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i <= N; i++) {
		DP[i][0] = 0;
	}
	for (int i = 0; i <= K; i++) {
		DP[0][i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= v[i].first) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - v[i].first] + v[i].second);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	cout << DP[N][K] << endl;

	//O(NK)
	// DP[i][j] : 1���� i��° ���Ǳ���, jkg���� �� �� ���� �� �ִ�� ì�� �� �ִ� ��ġ.

	// DP[i][j] = DP[i-1][j], DP[i-1][j-v[i].first] + v[i].second
	// �� �� : ���� ���� ��
	// �� �� : ���� �� �� -> �� �� �־�� ��. ��� �� �� ������ �Ǻ�����? j >= v[i].first

	return;
}