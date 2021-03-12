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

	// psum[b] - psum[a-1] : a~b���� sum
	int temp;

	/*for (int i = 1; i <= K; i++) {
		dp[i][i] = file[i];
	}
	
	�ʱ�ȭ�� �ϸ� �ȵǴ°� dp[i][i]���� cost�� �Ҹ����� ����.
	*/


	/*
	
	dp[i][j] : i~j ��ġ�� �� cost min
	dp[i][k] + dp[k+1][j] : i~k ����µ� cost + k+1~j ����µ� cost + i~j size
	�̷��� ��
	
	*/
	for (int i = 1; i < K; i++) {
		dp[i][i + 1] = dp[i][i] + dp[i + 1][i + 1];
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K - i; j++) {
			temp = 2100000000;
			//dp[j][i + j] : �밢 ����
			for (int k = j; k < i + j; k++) {
				// cost �߿� min�� + file size���־�� ��
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
// 2��

dp[i][j] : i���� j���� ��ġ�� �� cost�� �ּڰ��̶� ġ��


*/