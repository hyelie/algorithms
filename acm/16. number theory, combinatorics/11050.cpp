#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

void solve();

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

void solve() {
	int N, K; cin >> N >> K;
	vector<vector<int>> comb(N+1, vector<int>(N+1, 0));
	// comb[i][j] : iCj
	comb[0][0] = 0;
	comb[1][1] = comb[1][0] = 1;
	for (int i = 2; i <= N; i++) {
		comb[i][0] = comb[i][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
	cout << comb[N][K];


	return;
}

/*

nCk = n-1Ck-1 + n-1Ck

*/