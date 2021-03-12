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
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	int K;
	cin >> M >> K;
	vector<vector<int>> w(M, vector<int>(K));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> w[i][j];
		}
	}

	vector<vector<int>> u(N, vector<int>(K));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			long long sum = 0;
			for (int k = 0; k < M; k++) {
				sum += v[i][k] * w[k][j];
			}
			u[i][j] = sum;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << u[i][j] << ' ';
		}
		cout << '\n';
	}

	return;
}

/*

O(n^3)

*/