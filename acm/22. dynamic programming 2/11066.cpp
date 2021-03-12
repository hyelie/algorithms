#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
int dp[502][502];
int psum[502];
int file[502];
// sum : prefix sum

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--) {
		solve();
	}
	return 0;
}

void solve() {
	int K; cin >> K;
	psum[0] = 0;
	for (int i = 1; i <= K; i++) {
		cin >> file[i];
		psum[i] = psum[i - 1] + file[i];
	}

	// psum[b] - psum[a-1] : a~b까지 sum
	int temp;

	/*for (int i = 1; i <= K; i++) {
		dp[i][i] = file[i];
	}
	
	초기화를 하면 안되는게 dp[i][i]에서 cost를 소모하지 않음.
	*/


	/*
	
	dp[i][j] : i~j 합치는 데 cost min
	dp[i][k] + dp[k+1][j] : i~k 만드는데 cost + k+1~j 만드는데 cost + i~j size
	이렇게 됨
	
	*/
	for (int i = 1; i < K; i++) {
		dp[i][i + 1] = dp[i][i] + dp[i + 1][i + 1];
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K - i; j++) {
			temp = 2100000000;
			//dp[j][i + j] : 대각 접근
			for (int k = j; k < i + j; k++) {
				// cost 중에 min값 + file size해주어야 함
				temp = min(temp, dp[j][k] + dp[k + 1][i + j]);
			}
			// 
			temp += psum[i + j] - psum[j - 1];
			dp[j][i + j] = temp;
		}
	}

	/*for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= K; j++) {
			cout << dp[i][j] << ' ';
		}cout << endl;
	}*/

	cout << dp[1][K] << '\n';




	return;
}



/*

// K <= 500
// 2초

dp[i][j] : i부터 j까지 합치는 데 cost의 최솟값이라 치자


*/