#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[2001][2001];
int arr[2001];

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
		cin >> arr[i];
	}

	// 길이1은 전부 팰린드롬.
	for (int i = 0; i < N; i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i < N-1; i++) {
		if(arr[i] == arr[i+1]) dp[i][i+1] = true;
	}

	// dp[i][j] : idx i~j까지가 palindrome이면 1, 아니면 0
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			//dp[j][i + j] = k++;
			dp[j][i + j] = (dp[j + 1][i + j - 1] == 1 && arr[j] == arr[i + j]) ? 1 : 0;
		}
	}



	int M; cin >> M;
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		cout << dp[s - 1][e - 1] << '\n';
	}

	return;
}