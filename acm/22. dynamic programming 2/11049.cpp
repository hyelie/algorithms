#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
pii input[501];
int dp[501][501] = { 0, };

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i].first >> input[i].second;
	}

	// dp[i][j] : i부터 j까지 행렬곱 연산의 최소값
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N- i; j++) {
			//dp[j][i + j] = k++;
			int temp = 2100000000;
			for (int k = j; k < i + j; k++) {
				temp = min(temp, dp[j][k] + dp[k + 1][i + j] + input[j].first * input[k].second * input[i + j].second);
			}
			dp[j][i + j] = temp;
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j] << ' ';
		}cout << endl;
	}*/

	cout << dp[0][N - 1];

	return;
}

/*

행렬 x by y * y by z를 곱하는 데 연산시간
xyz
-> 3중포문 걸리겠음.

ABC
AB * C, A * BC

ABCD
A * BCD, AB * CD, ABC * D

*/